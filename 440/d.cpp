#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> val(n, 0);
    for(int i = 0; i < n; i++){
        val[i] = arr[i] - (i+1); 
    }

    // for(int i = 0; i < n; i++){
    //     cout << val[i] << " ";
    // }
    // cout << endl;
    while(q--){
        int x, y; cin >> x >> y;
        int idx1 = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        //cout << idx1 << " " << (x-1) - idx1 << endl;
        int idx2 = lower_bound(val.begin(), val.end(), x-1 - idx1 + y) - val.begin();
        cout << idx2 + x-1 - idx1 + y << endl;
    }
}