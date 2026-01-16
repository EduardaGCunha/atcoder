#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    int k; cin >> k;
    if(mp[k] > 0) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}