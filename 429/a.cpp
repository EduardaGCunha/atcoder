#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        if(i < m) cout << "OK\n";
        else cout << "Too Many Requests\n";
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}