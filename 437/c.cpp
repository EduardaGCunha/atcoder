#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    vector<int> pref(n+1, 0), suf(n+1, 0);
    pref[0] = v[0].first;
    for(int i = 1; i < n; i++){
        pref[i] += pref[i-1] + v[i].first; 
    }
    suf[n-1] = v[n-1].second;
    for(int i = n-2; i >= 0; i--){
        suf[i] += suf[i+1] + v[i].second;
    }

    int best = 0;
    for(int i = 0; i < n; i++){
        //cout << pref[i] << " " << suf[i] << endl;
        if(pref[i] <= suf[i]){
            best = i + 1;
        }
    }
    cout << best << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}