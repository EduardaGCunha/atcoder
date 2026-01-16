#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int INF = 1e12;

signed main(){
    int t; cin >> t;
    while(t--){
        int n, w; cin >> n >> w;
        vector<int> arr(n);
        map<int, int> mp;
        int v = 2*w;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            mp[(i+1)%v] += arr[i];
        }

        int sum = 0;
        for(int i = 0; i < w; i++){
            sum += mp[i];
        }

        //cout << sum << endl;
        int ans = sum;
        for(int i = 1; i < v; i++){
            sum = sum - mp[i-1] + mp[(i+w-1)%v];
            //cout << sum << " "; 
            ans = min(ans, sum);
        }
        cout << endl;
        cout << ans << endl;
    }
    
}