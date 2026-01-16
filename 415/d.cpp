#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        v.push_back({a-b, a});
    }

    sort(v.begin(), v.end());
    int ans = 0;
    for(auto [d, a] : v){
        if(a > n) continue;
        int x = (n-a)/d + 1;
        ans += x;
        n -= x*d;
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