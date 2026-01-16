#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e7+1;

vector<bool> isprime(MAXN, true);
vector<int> primes;

void sieve(){
    isprime[0] = false;
    isprime[1] = false;
    for(int i = 2; i < MAXN; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j = i*i; j < MAXN; j+=i) isprime[j] = false;
        }
    }
}

int segsieve(int l, int r){
    int sz = r-l+1;
    vector<bool> seg(sz, true);
    int lm = sqrt(r);
    for(auto p : primes){
        if(p*p > r) break;
        int first = max(p*p, (l + p-1)/p * p);
        for(int i = first; i <= r; i += p) seg[i-l] = false;
    }

    int ans = 0;
    for(int i = 0; i < sz; i++) ans += (seg[i]);
    return ans; 
}

void solve(){
    sieve();
    int l, r; cin >> l >> r;
    if(l == r){
        cout << 1 << endl;
        return;
    }
    int ans = 1;
    ans += segsieve(l+1, r);
    for(auto p : primes){
        if(p*p > r) break;
        int x = p*p;
        while(x <= r){
            if(x >= l + 1) ans++;

            if(p > r/x) break;
            x*=p;
        }
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}