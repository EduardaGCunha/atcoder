#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<int> prefa(n+1, 0), prefb(m+1, 0);
    int ans1 = 0; 

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        prefa[i] = (x + prefa[i-1])%MOD;
        //ai * i
        int k = (x*i)%MOD;
        ans1 = (ans1 + k)%MOD;
    }
    //ans1 => somatorio de ai*i
    int ans2 = 0;
    for(int j = 1; j <= m; j++){
        int x; cin >> x;
        prefb[j] = (x + prefb[j-1])%MOD;

        //(bj * j)
        int k = (x*j)%MOD;

        int sum = 0;
        //todos os possiveis valores de resultado da divisao i/j
        for(int res = 1; j*res <= n; res++){
            //[j*res, (res+1)*j - 1]
            int l = res*j; 
            int r = min((res+1)*j-1, n);
            //ai*(i/j)
            sum = (sum + (((prefa[r] - prefa[l-1] + MOD)%MOD)*res)%MOD)%MOD;
        }

        ans2 = (ans2 + sum*k)%MOD;
    }

    //(somatorio de ai*i)*)(somatorio de bj) sum(ai*i) * sum(bj)
    ans1 = (ans1*prefb[m])%MOD;

    cout << ((ans1 - ans2 + MOD)%MOD) << endl;
    
}