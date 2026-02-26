#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;

void solve(){
    int n; cin >> n;
    vector<int> pref(n, 1), suf(n, 1);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    pref[0] = arr[0];
    for(int i = 1; i < n; i++){
        pref[i] = lcm(pref[i-1], arr[i]);
    }
    suf[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        suf[i] = lcm(suf[i+1], arr[i]);
    }

    vector<int> ans;
    for(int i = 0; i < n; i++){
        int v = 1;
        if(i == 0) v = suf[1];
        else if(i == n-1) v = pref[n-2];
        else v = lcm(pref[i-1], suf[i+1]);
        cout << v%MOD << " ";
    }
    cout << endl;
}

signed main(){
    int t; cin >> t;
    while(t--) solve();
}