#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n), brr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];
    
	int ans = 0;
    for(int i = 0; i < n; i++){
		ans += min(arr[i], brr[i]);
	}

	while(q--){
		char a;
		int x, v; 
		cin >> a >> x >> v;
		x--;
		ans -= min(arr[x],  brr[x]);
		if(a == 'A') arr[x] = v;
		else brr[x] = v;
		ans += min(arr[x], brr[x]);
		cout << ans << endl;
	}
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}

