#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;

signed main(){
    int n, m; cin >> n >> m;
    vector<int> arr(n), brr(m);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> brr[i];

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] += pref[i-1] + arr[i-1];
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        auto it = lower_bound(arr.begin(), arr.end(), brr[i]);
        if(it == arr.end()){
            //maior q todo mundo
            ans = (ans + brr[i]*n - pref[n])%MOD;
        }else{
            //tem parte maior e parte menor
            int idx = it - arr.begin();
            //cout << pref[n] - pref[idx] << " " << brr[i]*(n-idx) << " " << endl;
            //parte maior
            ans = (ans + pref[n] - pref[idx] - brr[i]*(n-idx))%MOD;
            //parte menor
            //cout << brr[i]*(idx) << " " << pref[idx] << endl;
            ans = (ans + brr[i]*(idx) - pref[idx])%MOD;
        }
    }

    cout << ans << endl;
}