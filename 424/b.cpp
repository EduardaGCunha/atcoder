#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<int> p(n+1, 0), ans;
    while(k--){
        int x, a; cin >> x >> a;
        p[x]++;
        if(p[x] == m){
            cout << x << " ";
        }
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