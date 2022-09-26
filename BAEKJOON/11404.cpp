#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int adj[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        fill(adj[i], adj[i]+1+n, INF);


    for(int i=0; i<m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a][b] = min(adj[a][b], cost);
    }

    for(int i=1; i<=n; i++){
        adj[i][i] = 0;
    }
     
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
                // adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adj[i][j] == INF) cout << "0 ";
            else 
                cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}