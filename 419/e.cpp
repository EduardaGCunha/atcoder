#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct DSU{
    int n;
    vector<int> p;
    vector<int> r;
    vector<int> cnt; 
    DSU(int _n){
        n = _n;
        p.resize(n);
        r.resize(n);
        cnt.resize(n);
        init();
    }

	void init(){
		for(int i = 0; i < n; i++){
			p[i] = i;
			r[i] = 0;
			cnt[i] = 0;
		}
	}
	
	//use some count to find how many black vertices are here
	int find(int x){
		return (p[x] == x ? x : p[x] = find(p[x]));
	}

	void unite(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(r[a] == r[b]) r[a]++;
		if(r[a] > r[b]){
			r[a] += r[b];
			//updating how many blacks are here
			cnt[a] += cnt[b];
			p[b] = a;
		}else{
			r[b] += r[a];
			cnt[b] += cnt[a];
			p[a] = b;
		}
	}
};

/*
if type 2, then I must find the parent and update the black cnt amount
I must also keep track of how many blacks and whites are there by using some local vector variable
*/

void solve(){
	int n, q; cin >> n >> q;
	DSU dsu(n);
	vector<int> blacks(n, 0);
	while(q--){
		int t; cin >> t;
		if(t == 1){
			int u, v; cin >> u >> v;
			u--, v--;
			dsu.unite(u, v);
		}else if(t == 2){
			int v; cin >> v;
			v--;
			int aumenta = -1;
			if(blacks[v]) blacks[v] = 0;
			else{
				blacks[v] = 1;
				aumenta = 1;
			}
			int x = dsu.find(v);
			dsu.cnt[x] += aumenta;
		}else{
			int v; cin >> v;
			v--;
			int x = dsu.find(v);
			if(dsu.cnt[x]) cout << "Yes\n";
			else cout << "No\n";
		}
	}

}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
