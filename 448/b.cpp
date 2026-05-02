#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, m; cin >> m >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        int p, v; cin >> p >> v;
        p--;
        int k = min(arr[p], v);
        arr[p] = max(0LL, arr[p]-v);
        ans += k;
    }
    cout << ans << endl;
}