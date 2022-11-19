#include<bits/stdc++.h>
using namespace std;

template<typename T> class Bit{
private:
  size_t n; vector<T> b[2];

  inline int lsb(int x){
    return (x & -x);}

  void add(int p, int i, T x){
    while(i<=n){
      b[p][i] += x;
      i += lsb(i);
    }
  }

  T sum(int p, int i){
    T res = 0;
    while(i>0){
      res += b[p][i];
      i -= lsb(i);
    }return res;
  }

  T sum(int i){
    return 1LL*sum(0,i)*i - sum(1,i);}

public:
  Bit(size_t _n) : n(_n+1){
    b[0].resize(n+5);
    b[1].resize(n+5);
  }

  void update(int l, int r, T x){
    ++l; ++r;
    add(0, l, x);
    add(0, r+1, -x);
    add(1, l, x*(l-1));
    add(1, r+1, -x*r);
  }

  T query(int l, int r){
    return sum(r+1) - sum(l);}
};

int main(){return 0;}
