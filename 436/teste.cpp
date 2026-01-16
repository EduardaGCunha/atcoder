#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
int c = 0;

void dfs(int v){
    visited[v] = 1;
    c++;
    for(auto u : graph[v]) if(!visited[u]) dfs(u);
}

int solve(int idx, int sum ){
    if(idx == 5){
        return (sum == 27 ? 1 : 0);
    }

    int ans = 0;
    for(int i = 1; i <= 6; i++){
        ans += solve(idx+1, sum + i);
    }
    return ans;
}

signed main(){
	cout << solve(0, 0) << endl;
} 