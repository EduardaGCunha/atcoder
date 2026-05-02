#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'


signed main(){
    fastio;
    double cur = 0.5;
    int n; cin >> n;
    double arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int ans1 = 0;
    for(int mask = 0; mask < (1<<n); mask++){
        double cur = 0.5;
        int ans = 0;
        for(int i = 0; i < n; i++){
            
            if(mask&(1<<i)){
                if(cur < 0.0 && cur + arr[i] > 0.0) ans++;
                cur += arr[i];
            }else{
                if(cur > 0.0 && cur - arr[i] < 0.0) ans++;
                cur -= arr[i];
            }
        }
        ans1 = max(ans, ans1);
    }


    cout << ans1 << endl;
}