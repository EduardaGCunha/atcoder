#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int s, a, b, x; cin >> s >> a >> b >> x;
    int ans = 0;
    while (x > a){
        ans += a*s;
        x -= a;
        x -= b;
    }
    if (x > 0) ans += x*s;
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}