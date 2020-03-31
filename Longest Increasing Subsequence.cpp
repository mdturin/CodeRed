#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define pb push_back    
#define mem(a,v) memset(a,v,sizeof a) 
const int mod = 1e9 + 7;
const int mx  = 2e5+5;
using vi = vector<int>;

int n = 7;
int ara[] = {7, 1, 2, 4, 8, 9, 2};

/// 1. Complexity : O(n*n)
///    Space      : O(n)

int dp[mx];
int lis(){
    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++)
            if(ara[j]<ara[i])
                dp[i] = max(dp[i], dp[j]+1);
    }
    return *max_element(dp, dp+n);
}

void printLis(){
    auto it = max_element(dp, dp+n) - dp;
    vi ans; ans.pb(it); it--;
    while(it>=0){
        if(dp[it]+1 == dp[ans.back()])
            ans.pb(it);
        it--;
    }
    reverse(all(ans));
    for(int i=0; i<ans.size(); i++)
        cout << ara[ans[i]] << " ";
    cout << "\n";
}

/// 2. Complexity : O(n * log n)
///    Space      : O(n)

int tail[mx], len;
int findPos(int x){
    int lw=0, hh=len-1, pos=0;
    while(lw<=hh){
        int mid = (lw+hh)/2;
        if(tail[mid] >= x)
            pos = mid, hh=mid-1;
        else lw=mid+1;
    }
    return pos;
}

int lis2(){
    len = 1; tail[0] = ara[0];
    for(int i=1; i<n; i++){
        if(ara[i] < tail[0]) tail[0] = ara[i];
        else if(ara[i] > tail[len-1]) tail[len++] = ara[i];
        else tail[findPos(ara[i])] = ara[i];
    }
    return len;
}

int pre[mx];
int getPos(int x){
    int lw=-1, hh=len-1, ans=0;
    while(hh-lw>1){
        int m = lw + (hh-lw)/2;
        if(ara[tail[m]] >= x)
            hh = m;
        else lw = m;
    }
    return hh;
}

int lis2Construct(){
    mem(tail, 0); mem(pre, -1); len = 1;
    for(int i=1; i<n; i++){
        if(ara[i] < ara[tail[0]]) tail[0] = i;
        else if(ara[i] > ara[tail[len-1]]){
            pre[i] = tail[len-1];
            tail[len++] = i;
        }
        else{
            int p = getPos(ara[i]);
            pre[i] = tail[p-1];
            tail[p] = i;
        }
    }
    return len;
}

void lis2Print(){
    /// in reverse order
    for(int i=tail[len-1]; i>=0; i=pre[i])
        cout << ara[i] << " ";
    cout << endl;
}

int main(){
    cout << lis() << "\n"; 
    printLis(); cout << "\n";

    cout << lis2Construct() << "\n"; 
    lis2Print(); cout << "\n";

    return 0;
}

