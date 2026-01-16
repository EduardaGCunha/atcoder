#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
    }
    int ans = INT_MAX;
    if(freq['0'] == 0) ans = min(ans, freq['1']);
    if(freq['1'] == 0) ans = min(ans, freq['0']);
    for(int i = 0; i < n; i++){
        //cout << i << " " << s[i] << " ";
        int j = i;
        while(j < n && s[j] == s[i]) j++; 
        char op = '0' + (1-(s[i]-'0'));
        //cout << s[i] << " " << freq[s[i]] << " " << freq[op] << " " << (freq[s[i]]-j-i)*2 << endl;
        ans = min(ans, (freq[s[i]]-(j-i))*2 + freq[op]);
        // cout << i << " " << j << " " << s[i] << " " << s[j] << " " << (freq[s[i]]-(j-i))*2 + freq[op] << endl;
        //cout << j << endl;
        i = j-1;
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}