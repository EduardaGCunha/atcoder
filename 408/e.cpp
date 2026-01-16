#include <bits/stdc++.h>
using namespace std;

/*
we're going to force the ith bit to be 0 
then we connect all vertices that has that ith bit set to 0
if 1 and N are connected in the end, then that ith bit can be 0
otherwise the ith bit must be 1, so we add them our answer
*/
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL)

struct DSU{
    int n;
    vector<int> p; 
    vector<int> r;
    DSU(int _n){
        n = _n; 
        p.resize(n);
        r.resize(n);
    }

    void reset(){
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
        }
    }

    int find(int x){
        return (p[x] == x? x : p[x] = find(p[x]));
    }

    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a] += r[b];
            p[b] = a;
        }else{
            r[b] += r[a];
            p[a] = b;
        }
    }
    
};

struct edges{
    int a, b, w; 
};

int main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<edges> v;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        v.push_back({a, b, w});
    }

    DSU dsu(n);
    int ans = 0;
    int forbidden = 0;
    for(int i = 29; i >= 0; i--){
        //todos os bits q nao podem estar ativos
        int forbid = ((1 << i) | (forbidden));
        
        dsu.reset();
        for(auto u : v){
            //se nenhum dos bits ja desligados estiver ligado
            if(!((u.w)&(forbid))) dsu.unite(u.a, u.b);
        }

        if(dsu.find(0) != dsu.find(n-1)){
            ans |= (1 << i);
        }else{
            //esse bit nao pode estar ligado
            forbidden |= (1 << i);
        }
    }

    cout << ans << endl;
}