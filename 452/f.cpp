#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'


struct BIT{
    int n; 
    vector<int> bit;
    void init(int x){
        n = x+1;
        bit.resize(n, 0);
    }

    void upd(int x, int v){
        for(; x <= n; x += x&(-x)){
            bit[x] += v;
        }
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= (x&(-x))){
            s += bit[x];
        }
        return s;
    }

    int query(int v){
        return sum(n) - sum(v);
    }
};


signed main(){
    int n, k; cin >> n >> k;
    int arr[n+1];
    BIT bit;
    bit.init(n+2);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int sz = 0, l = 0, ans = 0, qtd = 0;
    //enqaunto a quantidade de inversoes for menor q k, adicionar o cara
    for(int i = 0; i < n; i++){
        bit.upd(arr[i], 1);
        qtd += bit.sum(i-1);
        if(qtd == k) ans++;
        while(qtd > k){
            qtd -= bit.query(arr[l]);
            l++;
        }
    }
    cout << ans << endl;
    //se ficar maior, remover os mais a esquerda
    //se for igual, somar na resposta
}