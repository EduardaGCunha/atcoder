#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

struct order{
    int a, b;
    bool operator <(order x){
        if(x.a == a) return b < x.b;
        return a > x.a;
    }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];

    //for each vote from 1 to m
    vector<int> points(n, 0);
    for(int i = 0; i < m; i++){
        //for each person
        int cnt0 = 0, cnt1 = 0;
        for(int j = 0; j < n; j++){
            if(grid[j][i] == '1') cnt1++;
            else cnt0++;
        }
        //cout << cnt1 << " " << cnt0 << " ";
        char a;
        if(!cnt0) a = '1';
        else if(!cnt1) a = '0';
        else if(cnt0 < cnt1) a = '0';
        else a = '1';
        //cout << a << endl;
        for(int j = 0; j < n; j++){
            if(grid[j][i] == a) points[j]++;
        }
    }


    vector<order> v;
    for(int i = 0; i < n; i++){
        //cout << points[i] << " " << i << endl;
        order a;
        a.a = points[i];
        a.b = i;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    int mx = v[0].a;
    for(int i = 0; i < n; i++){
        if(v[i].a < mx) break;
        cout << v[i].b + 1 << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}