#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        if(k < x){
            x = k;
            cout << 1 << endl;
        }else cout << 0 << endl;
    }
}