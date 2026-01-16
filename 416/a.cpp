#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, l, r; cin >> n >> l >> r;
    l--, r--;
    string s; cin >> s;
    for(int i = l; i <= r; i++){
        if(s[i] == 'x'){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}