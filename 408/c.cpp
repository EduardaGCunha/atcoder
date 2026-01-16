#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6+1;
int arr[MAXN];

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        arr[l]++;
        arr[r+1]--;
    }

    int ans = LLONG_MAX;
    for(int i = 0; i < n; i++){
        arr[i] += arr[i-1];
        ans = min(arr[i], ans);
    }
    cout << ans << endl;

}