#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    string s; cin >> s;
    int n = s.size();
    int ca = 0, cb = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            ca++;
        }else if(s[i] == 'B' && ca > 0){
            ca--;
            cb++;
        }else if(s[i] == 'C' && cb > 0){
            cb--;
            ans++;
        }
    }
    cout << ans << endl;
}