#include<bits/stdc++.h>
using namespace std;

#define pb push_back 
#define all(x) x.begin(),x.end()
#define mem(a,v) memset(a,v,sizeof a)

using vi = vector<int>;
const int mod = 1e9 + 7;
const int mx  = 2e5+5;

/**
    longest biotonic subsequence
    a subsequence of arr[] is called
    Bitonic if it is first increasing, then decreasing
*/

int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
int n = sizeof(a)/sizeof(a[0]);

/**
    Iterative Method
    Complexity : O(n*n)
    Space : O(n)
*/

int dp[2][mx];
int lbs(){
    for(int i=0; i<n; i++){
        dp[0][i] = 1;
        for(int j=0; j<i; j++)
            if(a[j] < a[i])
                dp[0][i] = max(dp[0][i], dp[0][j]+1);
    }

    for(int i=n-1; i>=0; i--){
        dp[1][i] = 1;
        for(int j=n-1; j>i; j--)
            if(a[i] > a[j])
                dp[1][i] = max(dp[1][i], dp[1][j]+1);
    }

    int ans = 0, p=0;
    for(int i=0; i<n; i++)
        if(ans < dp[0][i]+dp[1][i]-1)
            ans = dp[0][i]+dp[1][i]-1, p = i;

    return ans;
}

/**
    Print Function of longest biotonic subsequence
    Required lbs() function.
*/

void lbsPrint(){
    lbs();
    int ans = 0, p=0;
    for(int i=0; i<n; i++)
        if(ans < dp[0][i]+dp[1][i]-1)
            ans = dp[0][i]+dp[1][i]-1, p = i;

    vi dis; dis.pb(p);
    for(int i=p-1; i>=0; i--)
        if(dp[0][i]+1 == dp[0][dis.back()])
            dis.pb(i);
    sort(all(dis));

    for(int i=p+1; i<n; i++)
        if(dp[1][i]+1 == dp[1][dis.back()])
            dis.pb(i);

    for(int i=0; i<ans; i++)
        cout << a[dis[i]] << " ";
    cout << "\n";
}

/**
    Binery Search Method :
    Complexity : O(n log n)
*/

int inc[2][mx], tail[2][mx], in;
int getPos(int x, int p){
    int lw=0, hh=in-1, ans=-1;
    while(lw<=hh){
        int m = (lw+hh)/2;
        if(inc[p][m]>=x)
            ans=m, hh=m-1;
        else lw=m+1;
    }
    return ans;
}

int lis(int p){
    inc[p][0] = a[0]; in = 1; tail[p][0] = 0;
    for(int i=1; i<n; i++)
        if(a[i] < inc[p][i])
            tail[p][0] = 0, inc[p][0] = a[i];
        else if(inc[p][in-1] < a[i])
            tail[p][i] = in, inc[p][in++] = a[i];
        else{
            int pp = getPos(a[i], p);
            tail[p][i] = pp, inc[p][pp] = a[i];
        }
    return in;
}

int lbs2(){
    lis(0); reverse(a, a+n); lis(1);

    reverse(a, a+n);
    reverse(tail[1], tail[1]+n);

    int ans = 0;
    for(int i=0; i<n; i++)
        ans = max(ans, tail[0][i]+tail[1][i]+1);
    return ans;
}

/**
    Print Function For Binery Search Method:
    Required lbs2() function.
*/

void lbs2Print(){
    lbs2();
    int ans = 0, p=0;
    for(int i=0; i<n; i++)
        if(ans < tail[0][1]+tail[1][i]+1)
            ans = tail[0][1]+tail[1][i]+1, p = i;
    vi dis; dis.pb(p);
    for(int i=p-1; i>=0; i--)
        if(tail[0][i]+1 == tail[0][dis.back()])
            dis.pb(i);
    sort(all(dis));

    for(int i=p+1; i<n; i++)
        if(tail[1][i]+1 == tail[1][dis.back()])
            dis.pb(i);

    for(auto u:dis)
        cout << a[u] << " ";
    cout << "\n";
}

int main(){
    lbsPrint();
    lbs2Print();
    return 0;
}

