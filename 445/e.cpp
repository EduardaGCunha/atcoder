#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;
const int MAXN = 1e7+7;
int spf[MAXN];

void crivo(){
    for (int i = 2; i <= MAXN; i++)  spf[i] = i;

    for(int i = 2; i < MAXN; i++){
        if(spf[i] == i){
            for(int j = i*i; j < MAXN; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int fastexpo(int a, int b){
    int res= 1;
    a %= MOD;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    map<int, int> mx, sec, freq;
    int arr[n];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i] = x;
        while(x>1){
            int k = spf[x];
            int cnt = 0;
            while(!(x%k)){
                x /= k;
                cnt++;
            }
            if(cnt > mx[k]){
                sec[k] = mx[k];
                mx[k] = cnt;
                int v = fastexpo(k, cnt);
                freq[v]++;
            }else if(cnt > sec[k]){
                sec[k] = cnt;
            }
        }
    }

    // for(auto [a, b]: mx){
    //     cout << a << " " << b << endl;
    // }

    // for(auto [a, b]: sec){
    //     cout << a << " " << b << endl;
    // }

    int glcm = 1;
    for(auto [a, b] : mx){
        glcm = (glcm * fastexpo(a, b))%MOD;
    }
    //cout << glcm << endl;

    for(int i = 0; i < n; i++){
        int x = arr[i];
        int res = glcm;
        while(x>1){
            int k = spf[x];
            int cnt = 0;
            while(!(x%k)){
                x /= k;
                cnt++;
            }
            int v = fastexpo(k, cnt);
            if(freq[v] == 1 && cnt >= mx[k]){
                int inv = fastexpo(k, mx[k] - sec[k]);
                inv = fastexpo(inv, MOD-2);
                res = (res*inv)%MOD;
            }
        }
        cout << res << " ";
    }
    cout << endl;
}

signed main(){
    int t; cin >> t;
    crivo();
    while(t--) solve();
}