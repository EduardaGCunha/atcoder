#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

signed main(){
    fastio;
    string s; cin >> s;
    int ans = 0;
    for(int i = s.size()-1; i>= 0; i--){
        ans += (10 - (ans)%10 + s[i]-'0')%10;
    }
    ans += s.size();
    cout << ans << endl;
}