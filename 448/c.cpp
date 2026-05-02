#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, q; cin >> n >> q;
    multiset<int> ms;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        ms.insert(v);
        mp[i] = v;
    }

    while(q--){
        int k; cin >> k;
        vector<int> rem;
        for(int i = 0; i < k; i++){
            int x; cin >> x;
            x--;
            ms.erase(ms.find(mp[x]));
            rem.push_back(mp[x]);
        }
        cout << *(ms.begin()) << endl;
        for(auto u : rem) ms.insert(u);
    }
}