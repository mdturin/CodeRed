#include<bits/stdc++.h>
using namespace std;

// Complexity - O(nodes * edges)
class KuhnImplementation{
public:
    int n, k;
    vector<int> pairs;
    vector<bool> used;
    vector<vector<int>> g;

bool kuhn(int u){
  if(used[u]) return 0; used[u] = 1;
  for(int v : g[u]){
    v -= n;
    if(pairs[v] == -1 || kuhn(pairs[v]))
      return pairs[v] = u, 1;
  }return 0;
}

vector<pair<int,int>> find_max_matching(vector<vector<int>> &_g, int _n, int _k){
  g = _g; n = _n; k = _k;
  used = vector<bool>(n, 0);
  pairs = vector<int>(k, -1);

  for(int i=0; i<n; ++i){
    fill(used.begin(), used.end(), false);
    kuhn(i);
  }

  vector<pair<int,int>> res;
  for(int i=0; i<k; ++i)
    if(pairs[i] != -1)
      res.emplace_back(pairs[i], i);

  return res;
}
};

int main(){

    int n1, n2, edges;
    cin >> n1 >> n2 >> edges;

    vector<vector<int>> g(n1);
    for(int e=0; e<edges; ++e){
        int u, v;
        cin >> u >> v;
        --u; --v; // 0 index;
        g[u].push_back(v + n1);
    }

    KuhnImplementation maximumMatching;
    auto res = maximumMatching.find_max_matching(g, n1, n2);

    cout << res.size() << "\n"; // number of maximum matching
    for(auto pairs : res)
        cout << pairs.first << " " << pairs.second << "\n";
        // printing nodes, first<n1 && second<n2;

    return 0;
}