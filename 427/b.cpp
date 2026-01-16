#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int sum(int n){
    string s = to_string(n);
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += (s[i]-'0');
    }
    return sum;
}


void solve(){
    int n; cin >> n;
    vector<int> fx(n+2, 0);
    fx[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            fx[i] += sum(fx[j]);
        }
    }

    cout << fx[n] << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}