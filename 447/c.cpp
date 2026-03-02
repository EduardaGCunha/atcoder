#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

vector<int> solve(string v){
    vector<int> cnt;
    int c = 0;
    for(auto u : v){
        if(u == 'A') c++;
        else{
            cnt.push_back(c);
            c = 0;
        }
    }
    cnt.push_back(c);
    return cnt;
}

string solve2(string s) {
    string res = "";
    for(char c : s) if(c != 'A') res += c;
    return res;
}

signed main(){
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    string k = solve2(s);
    string k1 = solve2(t);
    if(k != k1){
        cout << -1 << endl;
    }else{
        vector<int> v1 = solve(s);
        vector<int> v2 = solve(t);
        int ans = 0;
        for(int i = 0; i < v1.size(); i++){
            ans += abs(v1[i] - v2[i]);
        }
        cout << ans << endl;
    }
}