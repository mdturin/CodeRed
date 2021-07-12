#include<bits/stdc++.h>
using namespace std;

/**
Source : WiiliamFiset
Binery Index Tree
Range Query
Point Upate
*/

template<typename T> class bit{
private:
    size_t n; vector<T> b;
    inline int lsb(int x){return (x & -x);}
    T sum(int i){
        T res = 0;
        for(; i; res+=b[i], i-=lsb(i));
        return res;
    }
public:
    bit(size_t _n):n(_n){b.resize(n,0);}
    // 'V' MUST BE ONE BASE & v[0] should be 0;
    bit(vector<T> &v):n(v.size()),b(v){
        for(int i=1; i<n; i++){
            int p = i + lsb(i);
            if(p<n) b[p] += b[i];
        }
    }
    T sum(int l, int r){return sum(r)-sum(l-1);}
    void add(int i, T v){
        for(; i<n; i+=lsb(i))
            b[i] += v;
    }
};

int main(){
    
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++)
        cin >> v[i];

    bit<int> b(v);
    cout << b.sum(1, 5) << '\n';
    cout << b.sum(5, 5) << '\n';

    b.add(4, 4);
    cout << b.sum(3, 5) << '\n';

    return 0;
}
