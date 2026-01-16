#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i = 0; i <= n; i++){
        int x = lower_bound(arr.begin(), arr.end(), i)-arr.begin();
        if((n - x) >= i){
            ans = i;
        }
    }
    cout << ans << endl;

}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}