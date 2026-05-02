#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);

signed main(){
    fastio;
    string s;
    int n, l, r; cin >> n >> l >> r >> s;
    vector<vector<int>> pref(26, vector<int>(n + 1, 0));
    for(int i = 0; i < 26; i++){
        char cur = i + 'a';
        for(int j = 0; j < n; j++){
            pref[i][j+1] = pref[i][j] + (s[j] == cur ? 1 : 0);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int cur = s[i] - 'a';
        int rs = i + l; 
        int re = i + r;

        if (rs >= n) continue;
        re = min(re, n - 1);
        ans += pref[cur][re + 1] - pref[cur][rs];
    }
    cout << ans << endl;
    return 0;
}