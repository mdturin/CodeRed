#include<bits/stdc++.h>
using namespace std;

template<typename T>
class FenwickTree3D{
private:
    int a, b, c;
    vector<vector<vector<T>>> ft;

    inline int LSB(int x){return x & (-x);}

    T Q(int x, int y, int z){
        T sum = 0;
        for(int x_ = x; x_ > 0; x_ -= LSB(x_))
        for(int y_ = y; y_ > 0; y_ -= LSB(y_))
        for(int z_ = z; z_ > 0; z_ -= LSB(z_))
            sum += ft[x_][y_][z_];
        return sum;
    }

public:
    T query(int x1, int y1, int z1, int x2, int y2, int z2){
        ++x1; ++y1; ++z1; ++x2; ++y2; ++z2;
        T val1 = Q(x2, y2, z2) - Q(x1-1, y2, z2) - Q(x2, y1-1, z2) + Q(x1-1, y1-1, z2);
        T val2 = Q(x2, y2, z1-1) - Q(x1-1, y2, z1-1) - Q(x2, y1-1, z1-1) + Q(x1-1, y1-1, z1-1);
        return val1 - val2;
    }

    T query(int x, int y, int z){return query(x, y, z, x, y, z);}

    void update(int x, int y, int z, T value){
        ++x; ++y; ++z;
        for(int x_ = x; x_ <= a; x_ += LSB(x_))
        for(int y_ = y; y_ <= b; y_ += LSB(y_))
        for(int z_ = z; z_ <= c; z_ += LSB(z_))
            ft[x_][y_][z_] += value;
    }

    FenwickTree3D(int _a, int _b, int _c) : a(_a+1), b(_b+1), c(_c+1){
        ft.assign(_a+5, vector<vector<T>>(_b+5, vector<T>(_c+5, 0)));
    }
};

int main(){return 0;}
