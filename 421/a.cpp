#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int x; 
    string s; 
    cin >> x >> s;
    x--;
    if(v[x] == s) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
