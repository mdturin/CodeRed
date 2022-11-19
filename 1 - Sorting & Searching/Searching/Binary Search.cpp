#include "bits/stdc++.h"
using namespace std;

using pii = pair<int,int>;
pii binarySearch(vector<int> a, int x){
    /// a must be sorted

    int lw = 0, hh = a.size()-1, ans=0;
    while(lw<=hh){
        int mid = lw + (hh-lw)/2;
        if(a[mid] >= x) 
            ans=mid,hh=mid-1;
        else lw = mid+1;
    }
    
    if(a[ans] != x)
        return pii(-1,-1);

    pii res(ans,-1);
    lw = 0, hh = a.size()-1;
    while(lw<=hh){
        int mid = lw + (hh-lw)/2;
        if(a[mid] <= x) 
            ans=mid,lw=mid+1;
        else hh = mid-1;
    }
    
    res.second = ans;
    return res;
}

const int EPS = 1e-9;
bool can(double x){/* do something;*/}
double binarySearchDouble(vector<double> a, double x){
    /// a must be sorted

    double lw=0,hh=100.0,ans=-1;
    while((hh-lw)>EPS){
        double mid = lw + (hh-lw)/2.0;
        if(can(mid))
            ans=mid,hh=mid;
        else lw=mid;
    }

    return ans;
}

/// Alternate way
double binarySearchDoubleAlternate(vector<double> a, double x){
    /// a must be sorted

    double lw=0,hh=100.0,ans=-1;
    int steps = 50; /// calculate steps, or found TLE
    while(steps--){
        double mid = lw + (hh-lw)/2.0;
        if(can(mid))
            ans=mid,hh=mid;
        else lw=mid;
    }

    return ans;
}

int main(int argc, const char** argv) {

    srand(time(0));
    int n = rand() % 100;
    int x = rand() % 15;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        a[i] = rand() % 15;
    sort(a.begin(), a.end());

    cout << n << ' ' << x << '\n';
    for(int i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << '\n';

    pii ans = binarySearch(a,x);
    cout << ans.first << ' ' 
         << ans.second << '\n';

    return 0;
}
