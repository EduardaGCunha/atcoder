#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<string, int> freq;
    for(int i = 0; i <= n-k; i++){
        string str = s.substr(i, k); 
        freq[str]++;
    }
    int mx = 0;
    for(auto u : freq){
        mx = max(mx, u.second);
    }

    for(auto [a, b] : freq){
        if(b == mx) cout << a << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}