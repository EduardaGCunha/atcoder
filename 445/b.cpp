#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n; cin >> n;
    vector<string> v;
    int mx = 0;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        v.push_back(s);
        mx = max((int)s.size(), mx);
    }
    //cout << mx << endl;
    for(int i = 0; i < n; i++){
        int add = mx - (int)v[i].size();
        for(int j = 0; j < add/2; j++) cout << ".";
        cout << v[i];
        for(int j = 0; j < add/2; j++) cout << ".";
        cout << endl;
    }
}