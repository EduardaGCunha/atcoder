#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    vector<int> brr(n);
    multiset<int> arr;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
    }
    for(int i = 0; i < n; i++) cin >> brr[i];

    sort(brr.rbegin(), brr.rend());

    int ans = 0;
    for(int i = 0; i < n; i++){
        int x = m - brr[i];
        //cout << brr[i] << " " << x << " ";
        auto it = arr.lower_bound(x);
        if(it == arr.end()){
            //cout << *arr.begin() << endl;
            if(!arr.empty()){
                ans += (*arr.begin() + brr[i])%m;
                arr.erase(arr.begin());
            }
        }else{
            //cout << *it << endl;
            ans += (*it + brr[i])%m;
            arr.erase(it);
        }
    }

    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}