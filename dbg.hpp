#include <bits/stdc++.h>
using namespace std;

#define NL "\n\n"
#define TEMP1   template<typename T>
#define TEMP2   template<typename T, typename U>
#define TEMP2A  template<typename T, typename... U>
#define OS      ostream& operator <<

TEMP1 OS(ostream &os, queue<T> q);
TEMP1 OS(ostream &os, stack<T> stk);
TEMP1 OS(ostream &os, const set<T> st);
TEMP2 OS(ostream &os, const pair<T,U> p);
TEMP1 OS(ostream &os, const vector<T> v);
TEMP2 OS(ostream &os, const map<T,U> mp);
TEMP1 OS(ostream &os, priority_queue<T> q);

TEMP2 OS(ostream &os, const pair<T,U> p){
    os << "[ " << p.first << ", " << p.second << " ]"; return os;}
TEMP1 OS(ostream &os, const vector<T> v){
    bool ok = false;
    os << "[ ";
    for(auto &u:v) {
        if(ok) os << ", ";
        os << u;
        ok = true;
    }
    os << " ]";
    return os;
}
TEMP2 OS(ostream &os, const map<T,U> mp){
    bool ok = false;
    os << "[ ";
    for(auto &it:mp){
        if(ok) os << ", ";
        os << "(";
        os << it.first;
        os << ", ";
        os << it.second;
        os << ")";
        ok = true;
    }
    os << " ]";
    return os;
}
TEMP1 OS(ostream &os, const set<T> st){
    bool ok = false;
    os << "[ ";
    for(auto &it:st){
        if(ok) os << ", ";
        os << it;
        ok = true;
    }
    os << " ]";
    return os;
}
TEMP1 OS(ostream &os, queue<T> q){
    bool ok = false;
    os << "[ ";
    while(q.size()){
        if(ok) os << ", ";
        os << q.front(); q.pop();
        ok = true;
    }
    os << " ]";
    return os;
}
TEMP1 OS(ostream &os, priority_queue<T> q){
    bool ok = false;
    os << "[ ";
    while(q.size()){
        if(ok) os << ", ";
        os << q.top(); q.pop();
        ok = true;
    }
    os << " ]";
    return os;
}
TEMP1 OS(ostream &os, stack<T> stk){
    bool ok = false;
    os << "[ ";
    while(stk.size()){
        if(ok) os << ", ";
        os << stk.top();
        stk.pop();
        ok = true;
    }
    os << " ]";
    return os;
}

void debug(){cerr<<NL;}
TEMP2A void debug(T head, U... tails){
    cerr << head;
    cerr << "\n";
    debug(tails...);
}
