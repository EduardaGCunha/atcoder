#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

/*
i will fix 1
then, i will go for every vertex i such that i > 1
and look at all distances from from to j
if there is one distance such that dist 1,p + p, j = dist 1, j, then p is the parent of j
we will take the maximum of all of these
*/

const int INF = 1e9;
const int MAXN = 3e3+7;
vector<pair<int, int>> graph[MAXN];
int visited[MAXN], dist[MAXN][MAXN];

signed main(){
    int n; cin >>n;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int x; cin >> x;
            dist[i][j] = x;
            dist[j][i] = x;
        }
    }
    //cada valor i
    for(int i = 1; i < n; i++){
        int mx = -1, cand = -1;
        for(int p = 0; p < n; p++){
            if(i == p) continue;
            if(dist[0][p] + dist[p][i] == dist[0][i] && mx < dist[0][p]){
                mx = dist[0][p];
                cand = p;
            }
        }
        if(cand == -1 || dist[cand][i] <= 0){
            cout << "No\n";
            return 0;
        }
        graph[i].push_back({cand, dist[cand][i]});
        graph[cand].push_back({i, dist[cand][i]});
    }

    /*
    for each starting node we will check if the distance from it to all other nodes match
    */

    for(int st = 0; st < n; st++){
        queue<int> q;
        q.push(st);
        vector<int> distance(n+1, -1);
        distance[st] = 0;
        while(!q.empty()){
            auto v = q.front(); q.pop();
            if(distance[v] != dist[st][v]){
                cout << "No\n";
                return 0;
            }
            for(auto [u, w] : graph[v]){
                if(distance[u] == -1){
                    distance[u] = distance[v] + w;
                    q.push(u);
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(distance[i] == -1){
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}