#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

const int mx = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

/// minimum smallest string rotation
/// greedy approch, easy to implement
int smallestCycle(string &s){
    s += s; int os = 0, ans = 0;
    for(int i=1; i<s.size(); i++)
        if(s[i] < s[ans]) ans=i, os=0;
        else if(s[i] == s[ans+os]) os++;
        else if(s[i]  < s[ans+os])
            ans=i-os, os=0, i=ans;
        else os = 0;
    return ans;
}

int main(){
    string s; cin >> s;
    cout << smallestCycle(s) << "\n";
    return 0;
}