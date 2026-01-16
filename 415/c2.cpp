#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int tot = (1<<n)-1;
    vector<int> safe(tot+1, 0), visited(tot+1, 0);
    for(int i = 1; i <= tot; i++){
        safe[i] = (s[i-1] == '0');
    }

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        //cout << v << endl;
        if(v == tot){
            cout << "Yes\n";
            return;
        }

        for(int i = 0; i < n; i++){
            if(!(v & (1<<i))){
                int u = v | (1<<i);
                if(safe[u] && !visited[u]){
                    visited[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    cout << "No\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}