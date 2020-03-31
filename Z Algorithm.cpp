#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps=3e-8;
const int mx = 1e5+5;

vector<int> zAlgo(string &s){
    int n = (int)s.size();
    vector< int > z(n);
    for(int i=1, l=0, r=0; i<n; i++){
        if(i <= r) z[i] = min(r-i+1, z[i-l]);
        while(i+z[i]<n && s[z[i]] == s[i+z[i]])
            z[i]++;
        if(i+z[i]-1 > r) l = i, r = i + z[i] - 1;
    }
    return move(z);
}

int stringMatching(string &pat, string &text){
    string modifiedTest = pat + '$' + text;
    auto ans = zAlgo(modifiedTest);
    int res = 0;
    for(int u:ans)
        if(u == pat.size())
            res++;
    return res;
}

int main(){
    string pat = "hello";
    string text = "helloWorldhello!!";
    printf("%d\n", stringMatching(pat,text));

//    string modifyText = pat + "$" + text;
//
//    /** "$" is a unique character
//    to separate pattarn and text */
//
//    auto ans = zAlgo(modifyText);
//
//    /** zAlgo function return the 'Z Array'
//    where for each index i, it store the longest
//    length that match with pattarn. so when any
//    index value is equal to the pattern size it match.
//    */
//
//    int res = 0;
//    for(int u:ans)
//        if(u == pat.size())
//            res++;
//    PF("%d\n", res); /// res is the total match
    return 0;
}
