#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    fastio;
    int n; cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];

    int mxi = arr[1];
    for(int i = 2; i <= n; i++){
        //cout << arr[i] << " ";
        if(mxi < i) break;
        mxi = max(arr[i] + i - 1, mxi);
    }
    cout << min(mxi, n) << endl;
}