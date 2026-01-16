#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){

}

signed main(){
	fastio;
	int t; cin >> t;
	int cnt = 0;
	while(t--){
		//solve();
		int a, b; cin >> a >> b;
		if(b > a) cnt++;
	}
	cout << cnt << endl;
}