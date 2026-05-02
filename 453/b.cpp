#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    fastio;
    int n, k; cin >> n >> k;
    int prev = 0;
    for(int i = 0; i <= n; i++){
        int x; cin >> x;
        if(i == 0){
            prev = x;
            cout << i << " " << x << endl;
        }else if(abs(prev-x) >= k){
            cout << i << " " << x << endl;
            prev = x;
        }
    }
}