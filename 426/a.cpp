#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    string x, y; cin >> y >> x;

    string arr[] = {"Ocelot", "Serval", "Lynx"};
    if(x == y) cout << "Yes\n";
    else if((arr[0] == x && arr[1] == y) || (arr[0] == x && arr[2] == y) || (arr[1] == x && arr[2] == y)){
        cout << "Yes\n";
    }else cout << "No\n";
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}