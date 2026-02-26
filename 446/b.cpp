#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    fastio;
    int n, m; cin >> n >> m;

    set<int> st;
    for(int i = 1; i <= m; i++) st.insert(i);
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        int found = 0;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            if(found != 0) continue;
            if(st.find(x) != st.end()){
                found = x;
                st.erase(x);
            }
        }
        cout << found << endl;
    }
}