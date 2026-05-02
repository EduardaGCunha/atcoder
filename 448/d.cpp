#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 2e5+7;
vector<int> graph[MAXN];
bool res[MAXN];
int arr[MAXN];

void dfs(int v, int p, multiset<int>& ms){
    res[v] |= res[p];
    bool mine = true;
    if(ms.find(arr[v]) != ms.end()){
        res[v] = true;
        mine = false;
    }else ms.insert(arr[v]);
    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v, ms);
    }
    if(mine) ms.erase(ms.find(arr[v]));
}

signed main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    multiset<int> ms;
    dfs(0, 0, ms);

    for(int i = 0; i < n; i++){
        if(res[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}