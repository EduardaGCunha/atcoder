#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
toda vez q mudar o numero nesse caractere, eu zero a soma e comeco dnv
*/

void solve(){
    string s; cin >> s;
    int n = s.size();
    int pref[n], suf[n];
    pref[0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]) pref[i] = pref[i-1] + 1;
        else pref[i] = 1;
    }
    suf[n-1] = 1;
    for(int i = n-2; i >=0; i--){
        if(s[i] == s[i+1]) suf[i] = suf[i+1] + 1;
        else suf[i] = 1;
    }

    // for(int i = 0; i < n; i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    
    // for(int i = 0; i < n; i++){
    //     cout << suf[i] << " ";
    // }
    // cout << endl;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1] && ((s[i+1] - '0') == ((s[i]-'0') + 1))){
            ans += min(pref[i], suf[i+1]);
        }
    }

    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}