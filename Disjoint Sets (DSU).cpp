#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int mx  = 2e5+5;

class UnionFind{
private:
    int numSets;
    vector<int> p, r;
    vector<int> setSize;
    
public:
    UnionFind(int n){
        numSets = n;
        r.assign(n, 0);
        p.assign(n, -1);
        setSize.assign(n, 1);
    }
    int findSet(int i){return p[i]==-1?i:p[i] = findSet(p[i]);}
    bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
    void unionSet(int i, int j){
        if(!isSameSet(i, j)){
            int x = findSet(i);
            int y = findSet(j);
            if(r[x] > r[y]){
                setSize[x] += setSize[y];
                p[y] = x;
            }
            else{
                setSize[y] += setSize[x];
                p[x] = y;
                if(r[x] == r[y])
                    r[y]++;
            }
            numSets--;
        }
    }
    int numDisJointSets(){return numSets;}
    int setSizeOf(int x){return setSize[findSet(x)];}
};

int main(){return 0;}

