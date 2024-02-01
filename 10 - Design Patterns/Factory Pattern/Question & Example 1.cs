// Design a Zoo Management System Using the Factory Method Pattern
// ---------------------------------------------------------------
// You are tasked with designing a system for managing different 
// types of animals and furniture in a zoo. The system should allow 
// for easy addition of new types of animals and furniture without 
// modifying existing code. Implement this system using the Factory 
// Method design pattern in C#.

namespace AnimalDesignFactoryPatternExample;

public interface IData
{
    string Id { get; set; }
    void InitializeData(object[] args);
}

public interface IAnimal : IData
{
    string Name { get; set; }
    int Age { get; set; }
    Species Species { get; set; }
    void Eating(string food);
    void Sleeping();
    void MakingSound();
}

public interface IFurniture : IData
{
    string Name { get; set; }
    Color Color { get; set; }
    Material Material { get; set; }
    double Cost { get; set; }
}

public enum Color
{
    Brown,
    Black,
    White
}

public enum Material
{
    Wood,
    Metal,
    Plastic
}

public enum Species
{
    Lion,
    Elephant,
    Giraffe
}

public abstract class AFurniture : IFurniture
{
    public string Id { get; set; } 
        = Guid.NewGuid().ToString();
    public string Name { get; set; }
    public Color Color { get; set; }
    public Material Material { get; set; }
    public double Cost { get; set; }

    public virtual void InitializeData(object[] args)
    {
        if(args.Length != 4)
            throw new ArgumentException("Invalid number of arguments");

        Name =  (string) args[0];
        Color = (Color) args[1];
        Material = (Material) args[2];
        Cost = (double) args[3];
    }
}

public abstract class AAnimal : IAnimal
{
    public string Id { get; set; } 
        = Guid.NewGuid().ToString();
    public string Name { get; set; }
    public int Age { get; set; }
    public Species Species { get; set; }

    public virtual void InitializeData(object[] args)
    {
        if(args.Length != 3)
            throw new ArgumentException("Invalid number of arguments");

        Name = (string) args[0];
        Age = (int) args[1];
        Species = (Species) args[2];
    }

    public virtual void Eating(string food)
    {
        Console.WriteLine($"{Name} is eating {food}");
    }

    public virtual void Sleeping()
    {
        Console.WriteLine($"{Name} is sleeping");
    }

    public virtual void MakingSound()
    {
        Console.WriteLine($"{Name} is making sound");
    }
}

public class Lion : AAnimal
{
    public override void MakingSound()
    {
        Console.WriteLine($"{Name} is making sound: Roar");
    }
}

public class Elephant : AAnimal
{
    public override void MakingSound()
    {
        Console.WriteLine($"{Name} is making sound: Trumpets and rumbles");
    }
}

public class Giraffe : AAnimal
{
    public override void MakingSound()
    {
        Console.WriteLine($"{Name} is making sound: Bleat");
    }
}

public class Chair : AFurniture { }

public class Table : AFurniture { }

public class Sofa : AFurniture { }

public class DataModelType
{
    // Animal Types
    public const string Lion = "Lion";
    public const string Elephant = "Elephant";
    public const string Giraffe = "Giraffe";

    // Furniture Types
    public const string Chair = "Chair";
    public const string Table = "Table";
    public const string Sofa = "Sofa";
}

public interface ISynchronizer
{
    static Dictionary<string, Type>? Initiators { get; set; }
    IData Sync(string key, params object[] args);
}

public abstract class ASynchronizer : ISynchronizer
{
    protected static Dictionary<string, Type>? Initiators { get; set; }
    public virtual IData Sync(string key, params object[] args)
    {
        if (Initiators == null || !Initiators.TryGetValue(key, out Type? type))
            throw new KeyNotFoundException("Invalid Animal Type Exception");

        var constructor = type.GetConstructor(Type.EmptyTypes);
        if (constructor == null)
            throw new NullReferenceException($"Constructor of type {type} not found!");

        var instance = (IData)constructor.Invoke(null);

        instance.InitializeData(args);

        return instance;
    }
}

public class AnimalSynchronizer : ASynchronizer
{
    static AnimalSynchronizer()
    {
        Initiators = new Dictionary<string, Type>()
        {
            { DataModelType.Lion,     typeof(Lion) }, 
            { DataModelType.Elephant, typeof(Elephant) }, 
            { DataModelType.Giraffe,  typeof(Giraffe) } 
        };
    }
}

public class FurnitureSynchronizer : ASynchronizer
{
    static FurnitureSynchronizer()
    {
        Initiators = new Dictionary<string, Type>()
        {
            { DataModelType.Chair, typeof(Chair) },
            { DataModelType.Table, typeof(Table) },
            { DataModelType.Sofa,  typeof(Sofa) } 
        };
    }
}

public class ModelFactory
{
    private static readonly Dictionary<string, ISynchronizer> _instances;
    private static readonly Dictionary<string, Type> _initiators;

    private static ISynchronizer GetInstanceOf(string type)
    {
        if (_instances.TryGetValue(type, out ISynchronizer? instance))
            return instance;

        var syncronizer = Activator.CreateInstance(_initiators[type]) as ISynchronizer ?? 
            throw new NullReferenceException($"Syncronizer of type {_initiators[type]} not found!");

        _instances.Add(type, syncronizer);
        return syncronizer;
    }

    static ModelFactory()
    {
        _instances ??= [];
        _initiators = new Dictionary<string, Type>()
        {
            { DataModelType.Lion,     typeof(AnimalSynchronizer) },
            { DataModelType.Elephant, typeof(AnimalSynchronizer) },
            { DataModelType.Giraffe,  typeof(AnimalSynchronizer) },
            { DataModelType.Chair,    typeof(FurnitureSynchronizer) },
            { DataModelType.Table,    typeof(FurnitureSynchronizer) },
            { DataModelType.Sofa,     typeof(FurnitureSynchronizer) }
        };
    }

    public static T CreateModel<T>(string type, params object[] args)
        where T : class, IData
    {
        var synchronizer = GetInstanceOf(type);
        return synchronizer.Sync(type, args) as T ??
            throw new NullReferenceException($"Model of type {type} not found!");
    }
}

public class AnimalDesignFactoryTask
{
    public static void Run()
    {
        var lion = ModelFactory
            .CreateModel<IAnimal>(DataModelType.Lion, "Simba", 5, Species.Lion);
        var elephant = ModelFactory
            .CreateModel<IAnimal>(DataModelType.Elephant, "Dumbo", 3, Species.Elephant);
        var giraffe = ModelFactory
            .CreateModel<IAnimal>(DataModelType.Giraffe, "Melman", 2, Species.Giraffe);

        lion.Eating("meat");
        lion.Sleeping();
        lion.MakingSound();

        elephant.Eating("grass");
        elephant.Sleeping();
        elephant.MakingSound();

        giraffe.Eating("leaves");
        giraffe.Sleeping();
        giraffe.MakingSound();

        var chair = ModelFactory
            .CreateModel<IFurniture>(DataModelType.Chair, "Chair", Color.Brown, Material.Wood, 100.50D);
        var table = ModelFactory
            .CreateModel<IFurniture>(DataModelType.Table, "Table", Color.Black, Material.Metal, 200.25D);
        var sofa = ModelFactory
            .CreateModel<IFurniture>(DataModelType.Sofa, "Sofa", Color.White, Material.Plastic, 300.75D);

        Console.WriteLine($"Chair: {chair.Name}, {chair.Color}, {chair.Material}, {chair.Cost}");
        Console.WriteLine($"Table: {table.Name}, {table.Color}, {table.Material}, {table.Cost}");
        Console.WriteLine($"Sofa: {sofa.Name}, {sofa.Color}, {sofa.Material}, {sofa.Cost}");
    }
}
