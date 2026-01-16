#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, l; cin >> n >> l; 
    map<int, int> mp;
    int prev = 0; 
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x; 
        y = (prev + x)%l;
        mp[y]++;
        prev = y;
    }

    if((l%3)){
        cout << 0 << endl;
        return;
    }


    int d = l/3, ans = 0;
    //cout << d << endl;
    mp[0]++;
    for(auto [u, c] : mp){
        if(u >= d) break;
        int a = (u+d), b = (u+d+d);
        if(mp[a] > 0 && mp[b] > 0){
            ans = (ans + c*mp[a]*mp[b]);
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