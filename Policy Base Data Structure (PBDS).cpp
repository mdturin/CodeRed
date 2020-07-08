#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define AT find_by_order /// return index pointer
#define POS order_of_key /// return value of index

template<typename TYPE, typename CMP>
using oset = tree<TYPE, null_type, 
             CMP, rb_tree_tag, 
             tree_order_statistics_node_update>;

template<typename TYPE>
struct cmp{
    bool operator()(const TYPE &a, const TYPE &b)
        const{
            return a.c > b.c;
            /// change according to your 
            /// data type and compare function
        }  
};

void example0(){
    struct node{
        int a, b, c;
        node(int _a, int _b, int _c):
            a(_a), b(_b), c(_c){}
    };

    oset< node, cmp<node> > s;
    for(int i=1; i<=5; i++)
        s.insert(node(i, i*i, i*i*i));
    
    for(int i=0; i<int(s.size()); i++)
        cout << (*s.AT(i)).a << ' '
             << (*s.AT(i)).b << ' '
             << (*s.AT(i)).c << '\n';
}

int main(){
    example0();

	// int a[] = {65,12,8,87,548}, n = 5;

    // oset< int, cmp<int> > s;
    // for(int i=0; i<n; i++)
    //     s.insert(a[i]);

	// for(int i=0; i<s.size(); i++)
	// 	cout << *s.AT(i) << " ";
    // cout << endl;

	// for(int i=0; i<s.size(); i++)
	// 	cout << s.POS(a[i]) << " ";
    // cout << endl;
	
	return 0;
}
