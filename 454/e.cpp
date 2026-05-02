#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

void solve(){
    int n, a, b; cin >> n >> a >> b;
    if((n&1) || !((a+b)&1)){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    string s = "";
    int x = 1, y = n, x1 = 1, y2 = n;

    while(a > x + 1){
        for(int i = x1; i < y2; i++) s += 'R';
        s += 'D';   
        for(int i = y2; i > x1; i--) s += 'L';
        s += 'D';
        x += 2;
    }

    while(b > x1 + 1){
        for(int i = x; i < y; i++) s += 'D';
        s += 'R';   
        for(int i = y; i > x; i--) s += 'U';
        s += 'R';
        x1 += 2;
    }

    int h = y - x + 1;
    int posa = a - x + 1;
    int w = y2 - x1 + 1;
    int posb = b - x1 + 1;

    if(posa == 1 && posb == 2){
        for(int i = 1; i < h; i++){
            s += 'D';
            s += (i&1) ? 'R' : 'L';
        }

        if(w > 2){
            s += 'R';
            for(int j = 3; j <= w; j++){
                for(int i = 1; i < h; i++){
                    s += (j&1) ? 'U' : 'D';
                }
                if (j < w) s += 'R';
            }
        }
    }else{
        for(int i = 1; i < w; i++){
            s += 'R';
            s += (i&1)? 'D' : 'U';
        }

        if(h > 2){
            s += 'D';
            for(int i = 3; i <= h; i++){
                for(int j = 1; j < w; j++){
                    s += (i&1) ? 'L' : 'R';
                }
                if(i < h) s += 'D';
            }
        }
    }
    cout << s << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--) solve();
}