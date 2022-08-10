#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
bool vis[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    int u,v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int num = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        queue <int> q;
        q.push(i);
        vis[i] = true;
        num++;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << num;
}