#include <bits/stdc++.h>
using namespace std;

int n, m, start;
vector<int> adj[1005];
bool vis[1005];

void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs(){
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    } 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> start;
    
    int u,v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 번호가 작은 것부터 방문하기 위해 정렬
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    // DFS
    dfs(start);    

    fill(vis, vis+n+1, false);    
    cout << "\n";

    // BFS
    bfs();   

}