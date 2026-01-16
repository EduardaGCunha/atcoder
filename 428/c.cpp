#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
if its an ( i put in the stack

*/

void solve(){
    int q; cin >> q;
    vector<int> a, b;
    a.push_back(0);
    b.push_back(0);
    while(q--){
        int op; cin >> op;
        op--;
        if(op){
            a.pop_back();
            b.pop_back();
        }else{
            char c; cin >> c;
            a.push_back(a.back() + (c == '(' ? 1 : -1));
            b.push_back(min(a.back(), b.back()));
        }
        cout << (a.back() == 0 && b.back() == 0 ? "Yes\n" : "No\n");
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}