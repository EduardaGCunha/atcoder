#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < 3; i++){
        cout << v[i].second+1 << " ";
    }
    cout << endl;
}