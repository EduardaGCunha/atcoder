#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    fastio;
    int n; cin >> n;
    map<int, int> dp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        dp[x] = max(dp[x], dp[x-1]+1);
        ans = max(ans, dp[x]);
    }
    cout << ans << endl;
}