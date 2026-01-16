#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;
    int pode = 1;
    string t = s; 
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '#'){
            pode = 1;
            continue;
        }
        if(pode){
            t[i] = 'o';
            pode = 0;
        }
    }
    cout << t << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}