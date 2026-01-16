#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s, t; cin >> s >> t;
    map<char, int> mp; 
    for(int i = 0; i < t.size(); i++){
        mp[t[i]]++;
    }
    
    string ans = "Yes\n";
    for(int i = 1; i < s.size(); i++){
        if(s[i-1] >= 65 && s[i-1] <= 91 && mp.find(s[i]) == mp.end()) ans = "No\n";
    }
    cout << ans;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}