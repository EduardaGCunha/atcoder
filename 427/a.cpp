#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n/2; i++) cout << s[i];
    for(int i = n/2+1; i < n; i++) cout << s[i];
    cout << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}