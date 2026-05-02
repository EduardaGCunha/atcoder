#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'


//tam, pos, caractere
int dp[20][20][30];

signed main(){
    int n; cin >> n;
    vector<pair<int, int>> queries;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        b--;
        queries.push_back({a, b});
    }

    int m; cin >> m;
    vector<string> v;
    for(int i = 0; i < m; i++){
        string s; cin >> s;
        v.push_back(s);
        for(int j = 0; j < s.size(); j++){
            dp[(int)s.size()][j][s[j]-'a']++;
        }
    }


    for(int i = 0; i < m; i++){
        string s = v[i];
        if(s.size() != n){
            cout << "No\n";
            continue;
        }
        int pos = 1;
        for(int j = 0; j < n; j++){
            auto [a, b] = queries[j];
            if(dp[a][b][s[j]-'a'] == 0) pos = 0;
        }
        if(pos) cout << "Yes\n";
        else cout << "No\n";
    }

}