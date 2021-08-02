#include<bits/stdc++.h>
using namespace std;

struct node{
    int isEnd;
    unordered_map<char, node*> child;
    node():isEnd(0){child.clear();}
} *root = new node();

void insert(string &s){
    node *cur = root;
    for(int i=0; s[i]; i++){
        int v = s[i];
        if(!cur->child[v])
            cur->child[v] = new node();
        cur = cur->child[v];
    }
    cur->isEnd++;
}

bool search(string &s){
    node *cur = root;
    for(int i=0; s[i]; i++){
        int v = s[i];
        if(!cur->child[v])
            return false;
        cur = cur->child[v];
    }
    return cur->isEnd>0;
}

bool isEmpty(node *cur){
    if(cur->isEnd) return false;
    return cur->child.empty()==true;;
}

node* remove(node *cur, string &s, int i){
    if(cur == NULL) return NULL;
    if(i == int(s.size())){
        if(cur->isEnd) cur->isEnd--;
        if(isEmpty(cur))
            delete(cur), cur = NULL;
        return cur;
    }

    int v = s[i];
    cur->child[v]
        = remove(cur->child[v], s, i+1);
    if(isEmpty(cur))
        delete(cur), cur = NULL;
    return cur;
}

void clearAll(node *cur){
    if(!cur) return;
    for(auto &it:cur->child)
        clearAll(it.second);
    cur = NULL;
    delete(cur);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;

    s = "Turin";    insert(s);
    s = "Turbo";    insert(s);
    s = "Mujahid";  insert(s);

    s = "Turin"; cout << s << ' ' << search(s) << '\n';
    s = "Turin"; remove(root, s, 0);

    s = "Turin";    cout << s << ' ' << search(s) << '\n';
    s = "Turbo";    cout << s << ' ' << search(s) << '\n';
    s = "Mujahid";  cout << s << ' ' << search(s) << '\n';

    clearAll(root);

    return 0;
}

