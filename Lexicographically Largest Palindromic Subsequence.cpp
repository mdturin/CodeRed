#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5+5;

/// Lexicographically Largest Palindromic Subsequence

string s = "asvaweoinczzoihefnosjidfzoeitjh";
int n = s.size();

string fun(){
    string ans = ""; char ch = 'a';
    for(int i=0; s[i]; i++)
        ch = max(ch, s[i]);
    for(int i=0; s[i]; i++)
        if(ch == s[i])
            ans += ch;
    return ans;
}

int main(){
    cout << fun() << "\n";
    return 0;
}

