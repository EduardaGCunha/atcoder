#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 21;
vector<int> graph[MAXN];
int val[MAXN];
int h, w, n;
int ans = 0;

//used eh uma bitmask
void dfs(int used, int res){
    //se todos as 20 possibilidades foram usadas, ent retorne
    if(used == (1<<n) - 1){
        ans = max(ans, res);
        return;
    }

    //primeiro cara q nao foi usado
    int i = 0;
    for(; i < n; i++){
        if(!(used&(1<<i))) break;
    }

    //explorando se eu escolher nao marcar esse cara
    dfs(used | (1<<i), res ^ (val[i]));

    for(auto u : graph[i]){
        //se esse cara nao foi visitado
        //ent eu visito ele como se tivesse marcando ele
        if(!(used & (1<<u))){
            dfs(used | (1<<u) | (1<<i), res);
        }
    }
}

signed main(){
    cin >> h >> w;
    n = h*w;
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }

    for(int i = 0; i < n; i++){
        int x = i/w, y = i%w;
        if(y + 1 < w) graph[i].push_back(i+1);
        if(x + 1 < h) graph[i].push_back(i+w);
    }

    int mask = 0, res = 0;
    dfs(mask, res);
    cout << ans << endl;
}