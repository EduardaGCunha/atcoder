#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

//nxt = A*j + B*i

const int MX = 1e6+7;

signed main(){
    int n, a, b; cin >> n >> a >> b;

    vector<vector<int>> graph(MX);
    queue<int> q;
    vector<bool> bad(MX, false);
    //montar o grafo
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            int w = (a*j + b*i)%n;
            int cur = (i*n) + j;
            int nxt = (j*n) + w;
            graph[nxt].push_back(cur);
            if(i == 0 || j == 0){
                if(!bad[cur]){
                    bad[cur] = true;
                    q.push(cur);
                }
            }
        }
    }

    while(!q.empty()){
        auto v = q.front(); q.pop();
        ///cout << v << endl;
        for(auto u : graph[v]){
            if(!bad[u]){
                bad[u] = true;
                q.push(u);
            }
        }
    }
    int n2 = n*n;
    int ans = 0;
    for(int i = 0; i < n2; i++){
        if(!bad[i]) ans++;
    }

    cout << ans << endl;
}