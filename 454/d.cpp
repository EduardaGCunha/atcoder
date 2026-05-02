#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
int cnt = 0;

string res(string s){
    string t = "";
    for(int i = 0; i < s.size(); i++){
        auto u = s[i];
        if(u == 'x') t += "x";
        else if(u == ')'){
            int idx = t.size();
            if(idx >= 3 && t[idx-1] == 'x' && t[idx-2] == 'x' && t[idx-3] == '('){
                t.pop_back(); 
                t.pop_back(); 
                t.pop_back(); 
                t += "xx";
            } else t += ")";
        }else t += "(";
    }
    return t;
}

void solve(){
    string s, t; cin >> s >> t;
    string a = res(s);
    string b = res(t);
    if(a == b) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--) solve();
}