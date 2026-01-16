#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 5e5+7;
int arr[MAXN];

void solve(){
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        arr[l]++;
        arr[r+1]--;
    }
    
    int cur = 0;
    for(int i = 0; i < n; i++){
        cur += arr[i];
        if((cur&1)) cout << t[i];
        else cout << s[i];
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
