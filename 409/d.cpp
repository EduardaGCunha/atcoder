#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
	string s; cin >> s;
	int l = -1;
	for(int i = 0; i < n-1; i++){
		if(s[i] > s[i+1]){
			l = i;
			break;
		}
	}
    if(l == -1){
        cout << s << endl;
        return;
    }
	int r = n;
	for(int i = l+1; i < n; i++){
		if(s[l] < s[i]){
			r = i;
			break;
		}
	}


	for(int i = 0; i < l; i++) cout << s[i];
    //cout << endl;
	for(int i = l+1; i < r; i++) cout << s[i];
    cout << s[l];
	for(int i = r; i < n; i++) cout << s[i];
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}
