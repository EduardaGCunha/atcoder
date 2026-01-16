#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, m, q; cin >> n >> m >> q;
    int arr[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> arr[i][j];
    }

    map<int, int> mp;
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(mp[arr[i][j]] > 0) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}