#include<bits/stdc++.h>
using namespace std;

/**
Source : Cp-Algo
Binery Index Tree
Range Query
Range Upate
*/

/// 1 base indexing please
template<typename T> class bit{
private:
    size_t n;
    vector<T> b[2];
    int lsb(int x){return (x & -x);}
    void add(int p, int i, T x){
        while(i<n){
            b[p][i] += x;
            i += lsb(i);
        }
    }
    T sum(int p, int i){
        T res = 0;
        while(i>0){
            res += b[p][i];
            i &= ~lsb(i);
        }
        return res;
    }
    T sum(int i){return sum(0,i)*i - sum(1,i);}

public:
    bit(size_t _n):n(_n){
        b[0].resize(n), b[1].resize(n);}
    bit(vector<T> &v):bit(v.size()){
        for(int i=1; i<n; i++)
            update(i, i, v[i]);
    }
    void update(int l, int r, T x){
        add(0, l, x);
        add(0, r+1, -x);
        add(1, l, x*(l-1));
        add(1, r+1, -x*r);
    }
    T query(int l, int r){return sum(r)-sum(l-1);}
};

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5};
    bit<int> b(v);
    cout << b.query(1, 5) << '\n';
    b.update(1, 3, 2);
    b.update(2, 4, -3);
    cout << b.query(1, 5) << '\n';
    return 0;
}
