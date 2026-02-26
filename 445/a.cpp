#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    string s; cin >> s;
    if(s[0] == s[s.size()-1]) cout << "Yes\n";
    else cout << "No\n";
}