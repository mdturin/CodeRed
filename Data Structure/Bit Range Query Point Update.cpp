#include<bits/stdc++.h>
using namespace std;

template<typename T> class Bit{
private:
    size_t n; vector<T> b;

    inline int lsb(int x){
        return (x & -x);}

    T sum(int i){
        T res = 0;
        while(i > 0){
            res += b[i];
            i -= lsb(i);
        }return res;
    }

public:
    Bit(size_t _n):n(_n+1){
        b.resize(n+5, 0);}

    T sum(int l, int r){
        return sum(r+1) - sum(l);}

    void add(int i, T v){
        for(++i; i<=n; i+=lsb(i))
            b[i] += v;
    }
};

int main(){return 0;}
