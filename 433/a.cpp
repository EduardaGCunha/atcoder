#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int x, y, z; cin >> x >> y >> z;
    for(int i = 0; i < 300; i++){
        if(x + i == (y + i)*z){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}