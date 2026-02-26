#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, q; cin >> n >> q;
    vector<tuple<int, int, string>> v;
    for(int i = 0; i < q; i++){
        int op, pc; cin >> op >> pc;
        string s = "";
        if(op == 2) cin >> s;
        v.push_back({op, pc, s});
    }

    int opb = 3, pcb = -1;
    vector<string> ans;
    for(int i = q-1; i >= 0; i--){
        auto [op, pc, s] = v[i];
        if(opb != op){
            if(pc == pcb && opb == 2 && op == 1){
                opb = 3;
                pcb = -1;
            }
        }else if(opb == 3){
            pcb = pc;
            opb = 2;
        }else if(opb == 2 && pc == pcb){
            ans.push_back(s);
        }
    }

    string s = "";
    for(int i = ans.size()-1; i >= 0; i--){
        s += ans[i];
    }
    cout << s << endl;
}