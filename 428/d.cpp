#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int c, d; cin >> c >> d;
    int pot = 1;
    int ans = 0;
    for(int i = 1; i <= 10; i++){
        int p = pot*10;

        int l = pot - c; 
        int r = p - 1 - c;
        l = max(1LL, l);
        r = min(d, r);
        if(l > r){
            pot *= 10;
            continue;
        }

        int low = (long long) ceil(sqrtl((long double)(p*c + c + l)));
        int high = (long long) floor(sqrtl((long double)(p*c + c + r)));
        if(high >= low) ans += (high - low + 1);
        pot *= 10;
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}