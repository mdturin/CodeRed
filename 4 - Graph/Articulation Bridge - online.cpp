#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
const int mx = 1e6 + 5;

int bridges;
int lca_iteration;
vector<int> last_visit;
vector<int> par, dsu_2ecc;
vector<int> dsu_cc, dsu_cc_size;

void init(int n){
  bridges = 0;
  par.resize(n);
  dsu_cc.resize(n);
  lca_iteration = 0;
  dsu_2ecc.resize(n);
  dsu_cc_size.resize(n);
  last_visit.assign(n, 0);
  for(int i=0; i<n; ++i){
    par[i] = -1;
    dsu_cc[i] = i;
    dsu_2ecc[i] = i;
    dsu_cc_size[i] = 1;
  }
}

int find_2ecc(int v){
  if(v == -1) return -1;
  if(dsu_2ecc[v] == v) return v;
  return dsu_2ecc[v] = find_2ecc(dsu_2ecc[v]);
}

int find_cc(int v){
  v = find_2ecc(v);
  if(dsu_cc[v] == v) return v;
  return dsu_cc[v] = find_cc(dsu_cc[v]);
}

void make_root(int v){
  v = find_2ecc(v);
  int root = v;
  int child = -1;
  while (v != -1) {
    int p = find_2ecc(par[v]);
    par[v] = child;
    dsu_cc[v] = root;
    child = v; v = p;
  }dsu_cc_size[root] = dsu_cc_size[child];
}

void merge_path(int a, int b){
  int lca = -1;
  ++lca_iteration;
  vector<int> path_a, path_b;
  while(lca == -1){
    if(a != -1){
      a = find_2ecc(a);
      path_a.push_back(a);
      if (last_visit[a] == lca_iteration){
        lca = a; break;
      }last_visit[a] = lca_iteration;
      a = par[a];
    }if(b != -1){
      b = find_2ecc(b);
      path_b.push_back(b);
      if (last_visit[b] == lca_iteration){
        lca = b; break;
      }last_visit[b] = lca_iteration;
      b = par[b];
    }
  }

  for (int v : path_a){
    dsu_2ecc[v] = lca;
    if (v == lca) break;
    --bridges;
  }

  for (int v : path_b){
    dsu_2ecc[v] = lca;
    if (v == lca) break;
    --bridges;
  }
}

void add_edge(int a, int b){
  a = find_2ecc(a);
  b = find_2ecc(b);
  if (a == b) return;

  int ca = find_cc(a);
  int cb = find_cc(b);

  if(ca != cb){
    ++bridges;
    if (dsu_cc_size[ca] > dsu_cc_size[cb]) {
      swap(a, b); swap(ca, cb);
    }make_root(a);
    par[a] = dsu_cc[a] = b;
    dsu_cc_size[cb] += dsu_cc_size[a];
  }else{
    merge_path(a, b);
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);


  int n, m; 
  cin >> n >> m;
  
  init(n);

  while(m--){
    int u, v;
    cin >> u >> v;
    --u; --v;
    add_edge(u, v);
    cout << bridges << "\n";
  }
  
  return 0;
}