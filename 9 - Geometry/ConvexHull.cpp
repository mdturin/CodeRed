#include<bits/stdc++.h>
using namespace std;

#define ff first
#define se second
using pt = pair<double,double>;

int orientation(pt a, pt b, pt c){
  double v = a.ff*(b.se-c.se);
  v += b.ff*(c.se-a.se);
  v += c.ff*(a.se-b.se);
  return (v<0) ? -1 : (v>0);
}

bool counterWise(pt a, pt b, pt c, bool include_collinear){
  int o = orientation(a, b, c);
  return o<0 || (include_collinear && o==0);
}

template<typename T> T SQ(T a){return a * a;}

bool collinear(pt a, pt b, pt c){
  return orientation(a, b, c) == 0;}

vector<pt> convexHull(vector<pt> &a, bool include_collinear=false){
  pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b){
    return make_pair(a.se,a.ff) < make_pair(b.se,b.ff);
  });
  
  sort(a.begin(), a.end(), [&p0](const pt &a, const pt &b){
    int o = orientation(p0, a, b);
    if(o == 0){
      return SQ(p0.ff - a.ff) + SQ(p0.se - a.se) <
             SQ(p0.ff - b.ff) + SQ(p0.se - b.se);
    }return o < 0;
  });

  if(include_collinear){
    int i = a.size() - 1;
    while(i>=0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin()+i+1, a.end());
  }

  vector<pt> ans;
  for(int i=0; i<a.size(); ++i){
    int sz = ans.size();
    while(sz>1 && 
      !counterWise(ans[sz-2], ans[sz-1], a[i], include_collinear))
      ans.pop_back(), --sz;
    ans.push_back(a[i]);
  }

  return ans;
}

int main(){

  return 0;
}