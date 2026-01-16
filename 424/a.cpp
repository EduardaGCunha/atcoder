#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int a, b, c; cin >> a >> b >> c;
    if(a == b || a == c || b == c) cout << "Yes\n";
    else cout << "No\n";

}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}