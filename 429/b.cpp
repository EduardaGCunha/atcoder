#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tot += arr[i];
    }

    for(int i = 0; i < n; i++){
        if(tot-arr[i] == m){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}