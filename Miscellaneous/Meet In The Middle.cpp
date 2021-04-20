#include "bits/stdc++.h"
using namespace std;

#define pb push_back 

int val, n;
vector<int> v;

int meetInTheMiddle(){
    vector<int> va, vb, allSubsetA, allSubsetB;
    for(int i=0; i<n; i++){
        if(i & 1) va.pb(v[i]);
        else vb.pb(v[i]);
    }

    int totalSubsetA = (1 << int(va.size()));
    int totalSubsetB = (1 << int(vb.size()));
    
    for(int i=0; i<totalSubsetA; i++){
        int sum = 0;
        for(int j=0; j<int(va.size()); j++)
            if(i & (1<<j))
                sum += va[j];
        allSubsetA.pb(sum);
    }

    for(int i=0; i<totalSubsetB; i++){
        int sum = 0;
        for(int j=0; j<int(vb.size()); j++)
            if(i & (1<<j))
                sum += vb[j];
        allSubsetB.pb(sum);
    }
    sort(allSubsetB.begin(), allSubsetB.end());

    int ans = 0;
    for(int &u:allSubsetA){
        int w = val - u;
        auto it = upper_bound(allSubsetB.begin(), allSubsetB.end(), w); it--;
        int val2 = (u + *it);
        if(val2 <= val)
            ans = max(ans, u+(*it));
    }
    return ans;
}

int main(int argc, const char** argv) {

    v = {45, 34, 4, 12, 5, 2}; val = 42; n = 6;
    cout << meetInTheMiddle() << '\n';

    v = {3, 34, 4, 12, 5, 2}; val = 10; n = 6;
    cout << meetInTheMiddle() << "\n";

    return 0;
}