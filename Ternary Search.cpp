#include<bits/stdc++.h>
using namespace std;

const int mx=1e5+5;

int n, a[mx];

/// usual way, 
/// O(log n), base = 2/3;
int ternary(){
    int lw=0, hh=n-1, ans=-1;
    while(lw <= hh){
        int mid1 = lw + (hh-lw)/3;
        int mid2 = hh - (hh-lw)/3;
        if(can(mid1) > can(mid2))
            ans=mid1, lw=mid1+1;
        else hh=mid2-1;
    }
    return ans;
}

/// tricky way
/// O(log n), base = 2, faster
int ternary(){
    int lw=0, hh=n-1, ans=lw;
    while(lw <= hh){
        int mid1 = lw + (hh-lw)/2;
        int mid2 = min(mid1+1, hh);
        if(can(mid1) >= can(mid2))
            ans=mid1, lw=mid1+1;
        else hh=mid2-1;
    }
    return ans;
}

int main(int argc, const char** argv) {
    return 0;
}
