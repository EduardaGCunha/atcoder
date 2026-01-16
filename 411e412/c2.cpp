#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
O(n) approach
we iterate through all values, as soon as we find someone that no longer 
is at most 2*s[i], then we ask if the last value * 2 is at most the lst,
if not we increase the loop
ill go one by one
    first check if we multiply this value by 2 
*/

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    if(arr[0]*2 >= arr[n-1]){
        cout << 2 << endl;
        return;
    }

    multiset<int> ms;
    for(int i = 1; i < n-1; i++) ms.insert(arr[i]);

    int cur = arr[0], ans = 0;
    while(cur*2 < arr[n-1]){
        //pegar o melhor 
        auto it = ms.upper_bound(cur*2);
        if(it == ms.begin()){
            cout << -1 << endl;
            return;
        }
        --it;
        cur = *it;
        ms.erase(it);
        ans++;
    }
    cout << ans + 2 << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}