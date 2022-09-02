#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

const int mx = 1e6 + 5;
const int MOD = 1e6 + 3;

/**
 * @brief 
 * 
 * Lucas Theoram can compute
 * larger binomial coefficient
 * (NcR)%M when the modular value
 * M is small. (M <= 1e7)
 *  
 * @param P 
 */

vector<ll> Fact;
vector<ll> Invfact;

void compute(int P = MOD){
	Fact.clear();
	Fact.resize(P);
	Invfact.clear();
	Invfact.resize(P);
        
	Fact[0]=Fact[1]=1;
	Invfact[0]=Invfact[1]=1;
	
	for(int i=2;i<P;i++){
		Fact[i]=(Fact[i-1]*i)%P;
		Invfact[i]=((P-P/i)*Invfact[P%i])%P;  
	}
}

ll Lucas(ll N, ll R, int P=MOD){
	if(R<0 || R>N) return 0;    // when R is out of bound
	if(R==0 || R==N) return 1;  // when R is in the edge
	if(N >= P)                  // try lucas for only larger than MOD
		return (Lucas(N/P,R/P,P)*Lucas(N%P,R%P,P))%P;
	return (Fact[N]*(Invfact[N-R]*Invfact[R])%P)%P; // try NcR formula O(1)
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    compute();
    Lucas(10, 3, MOD);
    
    return 0;
}

