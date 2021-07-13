#include<bits/stdc++.h>
using namespace std;

int n, BLK, a[100], b[10];
void build(){
    BLK = (int)sqrt(n) + 1;
    for (int i=0; i<n; ++i)
        b[i / BLK] += a[i];
}

int query(int l, int r){
    int sum(0), cl=l/BLK, cr=r/BLK;
    if (cl == cr)
        for (int i=l; i<=r; ++i)
            sum += a[i];
    else{
        for(int i=l, j=(cl+1)*BLK; i<j; ++i)
            sum += a[i];
        for(int i=cl+1; i<cr; ++i) sum += b[i];
        for(int i=cr*BLK; i<=r; ++i) sum += a[i];
    }
    return sum;
}

int main(){return 0;}