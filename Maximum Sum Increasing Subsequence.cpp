#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back

const int mod = 1e9 + 7;
const int mx  = 1000;

/**
    Maximum Sum Increasing Subsequence
    Given an array of n positive integers.
    Write a program to find the sum of maximum
    sum subsequence of the given array such that
    the integers in the subsequence are sorted
    in increasing order. For example, if input
    is {1, 101, 2, 3, 100, 4, 5}, then output should
    be 106 (1 + 2 + 3 + 100), if the input array is
    {3, 4, 5, 10}, then output should be 22
    (3 + 4 + 5 + 10) and if the input array is
    {10, 5, 4, 3}, then output should be 10
*/

int a[] = {1, 101, 2, 3, 100, 4, 5};
int n = sizeof(a)/4;

/**
    Iterative Method :
        Complexity : O(n*n)
        Space : O(n)
*/

int dp[mx];
int maxSumIncSubIte(){
    for(int i=0; i<n; i++) dp[i] = a[i];
    for(int i=1; i<n; i++)
    for(int j=0; j<i; j++)
        if(a[i] > a[j])
            dp[i] = max(dp[i], dp[j]+a[i]);
    return *max_element(dp, dp+n);
}

/// For printing values

vector< ll > vec[mx];
ll findSum(int p){
    ll sum = 0;
    for(auto x:vec[p])
        sum += x;
    return sum;
}

ll sum[mx];
void printMaxSumIncSub(){
    vec[0].pb(a[0]); sum[0] = findSum(0);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++)
            if(a[i]>a[j] && sum[i] < sum[j])
                vec[i] = vec[j], sum[i] = sum[j];
        vec[i].pb(a[i]);
        sum[i] += a[i];
    }

    int p = 0;
    for(int i=1; i<n; i++)
        if(sum[p] < sum[i])
            p = i;

    for(auto x:vec[p])
        cout << x << " ";
    cout << "\n";
}

int main(){
    cout << maxSumIncSubIte() << "\n";
    printMaxSumIncSub();
    return 0;
}

