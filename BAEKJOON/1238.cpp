#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define cost first
#define vertex second
using namespace std;

int n, m, x;
vector<pair<int, int>> adj[1005];
int dist[1005];
int d[1005];

void dijkstra(int st){
    fill(d, d+1005, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d[st] = 0;
    pq.push({d[st], st});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.vertex] != cur.cost) continue;
        for(auto nxt : adj[cur.vertex]){
            if(d[nxt.vertex] > d[cur.vertex] + nxt.cost){
                d[nxt.vertex] = d[cur.vertex] + nxt.cost;
                pq.push({d[nxt.vertex], nxt.vertex});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    for(int i=0; i<m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }

    for(int i=1; i<=n; i++){
        dijkstra(i);
        if(i == x){ // x에서 각자 집으로 돌아가는 길
            for(int j=1; j<=n; j++)
                dist[j] += d[j];
        }
        else // 각자 x까지 가는 비용
            dist[i] += d[x];
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
        ans = max(ans, dist[i]);
    cout << ans;   
}