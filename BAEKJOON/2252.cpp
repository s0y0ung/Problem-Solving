#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32005];
int deg[32005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << "\n";
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) q.push(nxt);
        }
    }
}