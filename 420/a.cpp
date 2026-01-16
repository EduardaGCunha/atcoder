#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;
    if(s == "red") cout << "SSS\n";
    else if(s == "blue") cout << "FFF\n";
    else if(s == "green") cout << "MMM\n";
    else cout << "Unknown\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
