#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, k; cin >> n >> k;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        string s = to_string(i);
        int sum = 0;
        for(int j = 0; j < s.size(); j++){
            sum += (s[j]-'0');
        }
        if(sum == k) ans++;
    }
    cout << ans << endl;
}