#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, k; cin >> n >> k;
    map<int, int> freq;
    int tot = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x] += x;
        tot += x;
    }

    vector<int> ans;
    for(auto u : freq){
        ans.push_back(u.second);
    }

    sort(ans.rbegin(), ans.rend());

    for(int i = 0; i < min(k, (int) ans.size()); i++){
        tot -= ans[i];
    }
    cout << tot << endl;
}