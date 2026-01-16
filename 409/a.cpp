#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    string s, t; cin >> s >> t;
    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o' && t[i] == 'o') a = 1;
        //if(s[i] == 'x' && t[i] == 'o') b = 1;
    }
    if(a) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}