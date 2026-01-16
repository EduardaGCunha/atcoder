#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int q; cin >> q;
    multiset<int> st;
    while(q--){
        int x; cin >> x;
        x--;
        if(x){
            int v =*st.begin();
            cout << v  << endl;
            st.erase(st.find(v));
        }
        else{
            int v; cin >> v;
            st.insert(v);
        }
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
