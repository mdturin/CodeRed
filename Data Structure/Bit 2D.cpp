#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class FenwickTree2D{
private: 
    int n, m; vector<vector<T>> ft;

    inline int LSB(int x){return x & (-x);}

    T Q(int x, int y){
        T sum = 0;
        for(int x_ = x; x_ > 0; x_ -= LSB(x_))
        for(int y_ = y; y_ > 0; y_ -= LSB(y_))
            sum += ft[x_][y_];
        return sum;
    }
    
public:
    T query(int x1, int y1, int x2, int y2){
        ++x1; ++y1; ++x2; ++y2;
        return Q(x2, y2) - Q(x1-1, y2) - Q(x2, y1-1) + Q(x1-1, y1-1);
    }

    void update(int x, int y, T value){
        for(int x_ = x; x_ <= n; x_ += LSB(x_))
        for(int y_ = y; y_ <= m; y_ += LSB(y_))
            ft[x_][y_] += value;
    }

    FenwickTree2D(int _n, int _m) : n(_n+1), m(_m+1){
        ft.assign(_n+5, vector<T>(_m+5, 0));
    }
};

int main(){
    int n, m, x, q;
    scanf("%d %d %d", &n, &m, &q);

    FenwickTree<int> tree(n, m);
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++){
        scanf("%d", &x);
        tree.update(i+1, j+1, x);
    }

    int x, y, xx, yy;
    while(q--){
        scanf("%d %d %d %d", &x,&y,&xx,&yy);
        printf("%d\n", tree.query(x,y,xx,yy));
    }

    return 0;
}
