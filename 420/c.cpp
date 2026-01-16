#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    int ans =0;
    ans = max((int)(x[n-1] - x[0]+1)/2, (int)(y[n-1] - y[0]+1)/2);
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
