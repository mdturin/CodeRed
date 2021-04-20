#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5+5;

/**
    Maximum Subarray and Sub-sequence
    Complexity : O(n)
    Space : O(1)
*/

int a[] = {-1, 7, 8, -6, 4, -21, 12, 3};
int n = sizeof(a)/4;

/// Kadane's Algorithm
/// maximum sub-array
int maxSubArraySum(){
    int maxAns = INT_MIN, maxCur = 0;
    for(int i=0; i<n; i++){
        maxAns = max(maxAns, maxCur+a[i]);
        maxCur = max(0, maxCur+a[i]);
    }
    return maxAns;
}

/// normal implemantation
/// maximum sub-sequence array
int maxSubSeSum(){
    int ans = 0, cnt = 0, maxV = INT_MIN;
    for(int i=0; i<n; i++){
        maxV = max(maxV, a[i]);
        ans = max(ans, ans+a[i]);
    }
    if(maxV<0) ans = maxV;
    return ans;
}

int main(){
    cout << maxSubArraySum() << "\n";
    cout << maxSubSeSum() << "\n";
    return 0;
}

