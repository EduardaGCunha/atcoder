#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1) res = (a*res)%MOD;
        a = (a*a)%MOD;
        b >>=1; 
    }
    return res;
}

/*
se forem diferentes
    ans += tam
    tam++
se forem iguais
    ans++ (so contribui 1 vez)

abccccccc
ans = 1 + 2 + 3
*/

signed main(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for(int i = 1; i <= n; i++){
        int idx = s[i-1]-'a';
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];
        dp[i][idx] = (dp[i-1][idx] + dp[i-1][(idx+1)%3] + dp[i-1][(idx+2)%3] + 1)%MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2])%MOD << endl;
}