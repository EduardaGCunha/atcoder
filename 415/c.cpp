#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N;
        string S;
        cin >> N >> S;

        int full = (1<<N) - 1;
        vector<char> safe(1<<N, 0);
        // safe[mask] = true iff mask>0 and S[mask-1]=='0'
        for(int mask = 1; mask <= full; mask++){
            safe[mask] = (S[mask-1] == '0');
        }

        vector<char> vis(1<<N, 0);
        queue<int> q;
        vis[0] = 1;    // empty bottle is our start
        q.push(0);

        bool ok = false;
        while(!q.empty()){
            int mask = q.front(); q.pop();
            if(mask == full){
                ok = true;
                break;
            }
            // try pouring in chemical k next
            for(int k = 0; k < N; k++){
                if(!(mask & (1<<k))){
                    int nxt = mask | (1<<k);
                    if(safe[nxt] && !vis[nxt]){
                        vis[nxt] = 1;
                        q.push(nxt);
                    }
                }
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
