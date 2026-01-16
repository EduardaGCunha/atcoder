#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, q; cin >> n >> q;
    int cnt = 0;
    vector<int> arr(n+2, 0); 
    while(q--){
        int x; cin >> x;
        int esq = arr[x-1];
        int dir = arr[x+1];

        if (arr[x]) { 
            if (esq == 0 && dir == 0) {
                cnt--;
            } else if (esq == 1 && dir == 1) {
                cnt++;
            }
        } else { 
            if (esq == 0 && dir == 0) {
                cnt++;
            } else if (esq == 1 && dir == 1) {
                cnt--;
            }
        }

        arr[x] = !arr[x];
        cout << cnt << endl;
    }
}

signed main(){
    fastio;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}