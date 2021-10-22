#include<bits/stdc++.h>
using namespace std;
#define tplate template<typename T>
#define hplate template<typename T,typename ...U>

namespace io {int f, qr;
	const int SIZE = (1<<21)+1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE];
	char *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
	#define gc() (iS==iT ? (iT=(iS=ibuf) + fread(ibuf,1,SIZE,stdin), \
                 (iS==iT ? EOF : *iS++)) : *iS++)
	inline void flush(){fwrite(obuf, 1, oS - obuf, stdout); oS = obuf;}
	inline void putc(char x) {*oS ++ = x; if (oS == oT) flush ();}
	tplate inline bool read (T &x){
		for (f=1, c=gc(); c<'0' || c>'9'; c=gc()) if (c=='-') f=-1; else if(c==EOF) return 0;
		for (x=0; c<='9' && c>='0'; c=gc()) x=x*10 + (c&15); x*=f; return 1;}
	inline bool read(char &x) {while((x=gc())==' '||x=='\n' || x=='\r'); return x!=EOF;}
	inline bool read(char *x){ while((*x=gc())=='\n' || *x==' '||*x=='\r'); if(*x==EOF)return 0;
		while(!(*x=='\n'||*x==' '||*x=='\r'||*x==EOF))*(++x)=gc(); *x=0; return 1;}
	hplate inline bool read(T &x,U &...y){return read(x)&&read(y...);}
	tplate inline bool write (T x) {if(!x)putc('0'); if(x<0) putc ('-'), x=-x;
		while(x) qu[++qr]=x%10+'0',x /= 10; while(qr)putc(qu[qr--]); return 0;}
	inline bool write (char x) { putc(x);return 0;}
	inline bool write(const char *x){while(*x){putc(*x);++x;}return 0;}
	inline bool write(char *x){while(*x){putc(*x);++x;}return 0;}
	hplate inline bool write(T x,U ...y){return write(x)||write(y...);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}using io::read; using io::write; using io::putc;

int main(){

    int n; read(n);
    char s[n]; read(s);

    write(n, ' ', s, '\n');
    return 0;
}
