#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string s; cin >> s;    
    vector<int> pos;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '#'){
            pos.push_back(i+1);
        }
    }
    for(int i = 0; i < pos.size(); i+=2){
        cout << pos[i] << "," << pos[i+1] << endl;
    }
}

signed main(){
	//fastio;
	int t = 1;
	while(t--){
		solve();
	}
}