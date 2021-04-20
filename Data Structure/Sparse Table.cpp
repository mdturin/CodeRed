#include<bits/stdc++.h>
using namespace std;

const int mxn = 1e5;
const int mxk = 20;

int n;
int a[mxn];
int st[mxn][21];

/// required function
inline int fun(int a, int b){return min(a,b);}

/// build sparse table in O(n log n)
void build(){
    for(int i=0; i<n; i++) st[i][0] = a[i];
    for(int j=1; j<=mxk; j++)
    for(int i=0; i+(1<<j)<=n; i++)
        st[i][j] = fun(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

/// query in O(log n)
int query(int l, int r){
    int sum = INT_MAX;
    for(int j=mxk; ~j; j--)
    if((1<<j) <= (r-l+1)){
        sum = fun(st[l][j], sum);
        l += (1 << j);
    }
    return sum;
}

/// faster query for finding min max only O(1)
int minMax(int l, int r){
    int j = log2((r-l+1));
    return fun(st[l][j], st[r-(1<<j)+1][j]);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
        
    build();

    for(int i=0; i<n; i++)
    for(int j=i; j<n; j++)
        cout << i << " " 
             << j << " " 
             << minMax(i, j) << "\n";
}
