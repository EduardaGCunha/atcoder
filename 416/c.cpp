#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

vector<string> v;
vector<string> ans;
int n, k, x;

void generate(int cnt, string s){
    if(cnt == k){
        ans.push_back(s);
        return;
    }

    for(int i = 0; i < n; i++){
        string t = s;
        t += v[i];
        generate(cnt+1, t);
    }

}

void solve(){
    //n strings and I want at most K mashed together
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    string s = "";
    generate(0, s);
    sort(ans.begin(), ans.end());
    // for(auto u : ans){
    //     cout << u << endl;
    // }
    cout << ans[x-1] << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}