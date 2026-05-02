#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int h, w, q; cin >> h >> w >> q;
    while(q--){
        int op, x; cin >> op >> x;
        op--;
        if(!op){
            cout << (x*w) << endl;
            h -= x;
        }else{ 
            cout << (x*h) << endl;
            w -= x;
        }
    }

}