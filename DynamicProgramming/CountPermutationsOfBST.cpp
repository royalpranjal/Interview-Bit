#include <bits/stdc++.h>
using namespace std;

using ll = long long

const ll MOD = 1e9+7;
const ll INF = 1e18;
const ll N = 2e2+5;

#define S second
#define F first
#define vt vector
#define rep(i, st, en) for(ll i = (st); i < (en); ++i)
#define repr(i, en, st) for(ll i = (en); i >= (st); --i)

int Solution::cntPermBST(int a, int b) {

	if (b >= a) {
		return 0;
	}

	
	vt<ll> fac(N), ifac(N);
	fac[0] = 1;
	rep(i, 1, N) {
		fac[i] = (fac[i-1]*i)%MOD;
	}

	auto bpow = [](ll x, ll p, ll m) -> ll {
		ll r = 1;
		while (p) {
			if (p&1) {
				r = (r*x)%m;
			}
			p >>= 1;
			x = x*x%m;
		}
		return r;
	};

	ifac[N-1] = bpow(fac[N-1], MOD-2, MOD);
	repr(i, N-2, 0) {
		ifac[i] = (ifac[i+1]*(i+1))%MOD;
	}

	auto ncr = [&](ll n, ll r, ll m) -> ll {
		if (r > n) {
			return 0;
		}
		ll x = fac[n]*ifac[r]%m*ifac[n-r]%m;
		return x;
	};


	vt<vt<ll>> dp(a+1, vt<ll>(a+1, 0)); // length of perm, height of tree
	vt<vt<ll>> ps(a+1, vt<ll>(a+1, 0)); 
	// stores number of valid such permutations for insertion
	
	dp[1][0] = 1;
	dp[0][0] = 1;

	rep(i, 0, a+1) {
		ps[1][i] = ps[0][i] = 1; // presum
	}

	rep(i, 2, a+1) {
		rep(j, 1, i) {// height can be from 1 to i-1
			// split can be made on a point 1 to i
			
			// add 0 length tree case first
			// 0 on left i-1 on right
			dp[i][j] = (dp[i][j] + 2*dp[i-1][j-1])%MOD;
			
			rep(k, 2, i) {
				ll add = ps[k-1][j-1]*ps[i-k][j-1]%MOD;
				ll sub = 0;
				if (j-2 >= 0) {
					sub = ps[k-1][j-2]*ps[i-k][j-2]%MOD;
				}
				ll c = (add - sub + MOD) % MOD;
				
				ll comb = ncr(i-1, k-1, MOD);
				dp[i][j] = (dp[i][j] + comb*c%MOD)%MOD;
				
			}

			
		}
		rep(j, 1, a+1) {
			ps[i][j] = (ps[i][j-1]+dp[i][j])%MOD;
		}
	}

	return dp[a][b];
}
