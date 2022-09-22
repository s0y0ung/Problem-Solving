#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
int p[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    int u,v;
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    p[1] = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    
    for(int i=2; i<=n; i++){
        cout << p[i] << "\n";
    }
}