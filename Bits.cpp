#include "bits/stdc++.h"
using namespace std;

#define isopposite(a,b) bool((a^b)<0)
#define swap(a,b)       a^=b, b^=a, a^=b
#define min(x,y)        (y ^ ((x ^ y) & -(x < y)))
#define max(x,y)        (x ^ ((x ^ y) & -(x < y)))
#define isPowerOfTwo(x) ((x & (x-1))==0) 

#define set(x,p)    (x |  (1<<p))
#define unset(x,p)  (x & ~(1<<p))
#define toggle(x,p) (x ^  (1<<p))
#define test(x,p)   ((x & (1<<p)) > 0)

#define leadingZeros    __builtin_clz
#define trailingZeros   __builtin_ctz
#define numberOfSetBits __builtin_popcount

int main(int argc, const char** argv) {return 0;}