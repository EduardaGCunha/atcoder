#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n, m; cin >> n >> m;
    vector<set<int>> conn(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        conn[a].insert(b);
    }

    int ans = 1e5;
    for(int mask = 0; mask < (1<<n); mask++){
        vector<int> b, w; 
        for(int i = 0; i < n; i++){
            if(mask&(1<<i)) b.push_back(i);
            else w.push_back(i);
        }
        int cnt1 = 0;
        for(int i = 0; i < b.size(); i++){
            for(int j = i+1; j < b.size(); j++){
                if(conn[b[i]].find(b[j]) != conn[b[i]].end()) cnt1++;
            }
        }
  
        int cnt2 = 0;
        for(int i = 0; i < w.size(); i++){
            for(int j = i+1; j < w.size(); j++){
                if(conn[w[i]].find(w[j]) != conn[w[i]].end()) cnt2++;
            }
        }

        ans = min({ans, cnt1 + cnt2});
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}