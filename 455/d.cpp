#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e5+7;
int graph[MAXN];
int visited[MAXN];

signed main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    vector<int> has(n+1, 0);
    for(int i = m-1; i >= 0; i--){
        auto [a, b] = v[i];
        if(has[a]) continue;
        has[a] = 1;
        graph[b] = a;
    }

    // for(int i = 1; i <= n; i++){
    //     cout << i << " " << graph[i] << endl;
    // }

    //v, p, amnt;
    queue<tuple<int,int, int>> q;
    for(int i = 1; i <= n; i++){
        if(has[i]) continue;
        q.push({i,i, 1});
    }
    
    vector<int> ans(n+1, 0);
    while(!q.empty()){
        auto [v,p, cnt] = q.front(); q.pop();
        //cout << v << " " << graph[v] << " " << cnt << endl;
        if(graph[v] == 0){
            ans[p] = cnt;
            continue;
        }
        q.push({graph[v], p, cnt+1});
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}