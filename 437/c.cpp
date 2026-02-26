#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'


void solve(){
    int n; cin >> n;
    int sum = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a + b});
        sum += b;
    }

    sort(v.begin(), v.end());
    
    int ans = 0, sum2 = 0;
    for(int i = 1; i <= n; i++){
        sum2 += v[i-1];
        if(sum2 <= sum) ans = i;
    }
    cout << ans << endl; 
}

signed main(){
    int t; cin >> t;
    while(t--) solve();
}