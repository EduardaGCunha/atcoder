#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, m; cin >> n >> m;
    vector<int> type(m, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        type[x]++;
    }

    int diff = 1, all = 1;
    for(int i = 0; i < m; i++){
        if(type[i] > 1) diff = 0;
        if(!type[i]) all = 0;
    }
    
    if(diff) cout << "Yes\n";
    else cout << "No\n";

    if(all) cout << "Yes\n";
    else cout << "No\n";
}