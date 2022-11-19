#include <stack>
#include <cstdio>
const int mx = 3e4+5;

int n, a[mx];
void solve(int cs){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", &a[i]);

  int best = 0, i;
  std::stack<int> s;
  for(i=0; i<n;){
    if(s.empty() || a[s.top()] <= a[i]) s.push(i++);
    else{
      int u = s.top(); s.pop();
      int len = s.size() ? i - s.top() - 1: i;
      int cur = a[u] * len;
      if(cur > best) best = cur;
    }
  }

  while(s.size() > 0){
    int u = s.top(); s.pop();
    int len = s.size() ? i - s.top() - 1: i;
    int cur = a[u] * len;
    if(cur > best) best = cur;
  }printf("Case %d: %d\n", cs, best);
}

int main(){
    int tc; scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
        solve(i);
    return 0;
}

