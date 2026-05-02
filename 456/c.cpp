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
    int tam = 1, r = 1;
    int n = s.size();
    int ans = 0;
    int inv2 = fastexpo(2, MOD-2);
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i] == s[i-1]){
            ans = (ans + ((tam)*(tam-1)/2)%MOD)%MOD;
            tam = 1;
        }
        tam++;
    }

    ans = (ans + ((tam)*(tam-1)/2)%MOD)%MOD;
    cout << ans << endl;
}