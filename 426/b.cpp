#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;
    }

    int mn = s.size()+1;
    char ar = '1';
    for(auto [a, b]: mp){
        if(b < mn){
            mn = b;
            ar = a;
        }
    }

    cout << ar << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}