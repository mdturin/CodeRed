#include<bits/stdc++.h>
using namespace std;

/**
Source : WiiliamFiset
Binery Index Tree
Range Upate
Point Query
*/

template<typename T> class bit{
private:
    size_t n;
    vector<T> b[2];

    /// Isolates the lower one bit value
    /// lsb(108) = lsb(0B 1101100) = (0B 100) = 4
    /// lsb(64)  = lsb(0B 1000000) = (OB 1000000) = 64
    int lsb(int x){return (x & -x);}

    /// add 'v' to index 'i' and all the
    /// parents for 'i', O(log n)
    void add(int i, T v){
        while(i<n){
            b[0][i] += v;
            i += lsb(i);
        }
    }

    T sum(int i, int p){
        T res = 0;
        while(i){
            res += b[p][i];
            i &= ~lsb(i);
            /// same as, i -= lsb(i), but faster
        }
        return res;
    }

public:
    /// Construct array in O(n)
    /// VAL MUST BE ONE BASE
    bit(vector<T> &v):n(v.size()){b[0] = v;
        for(int i=1; i<n; i++){
            int p = i + lsb(i);
            if(p < n) b[0][p] += b[0][i];
        }
        b[1] = b[0];
    }

    /// update the interval [l, r] with value 'v', O(log n)
    void update(int l, int r, T v){
        add(l, v);
        add(r+1, -v);
    }

    /// get the value at a specific index;
    T get(int i){return sum(i,0)-sum(i-1,1);}
};

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    bit<int> t(v);

    t.update(1, 3, 2);
    for(int i=1; i<=5; i++)
        cout << i << " " << t.get(i) << '\n';

    return 0;
}
