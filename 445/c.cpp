#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 5e5+7;
int graph[MAXN];
int comp[MAXN], lst = 0, c = 0;

void dfs(int v){
    comp[v] = c;
    lst = v;
    if(graph[v] != v) dfs(graph[v]);
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> graph[i];
    }
    vector<int> com;
    for(int i = 1; i <= n; i++){
        if(comp[i] == 0){
            c++;
            dfs(i);
            com.push_back(lst);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << com[comp[i]-1] << " ";
    }
    cout << endl;
    
}