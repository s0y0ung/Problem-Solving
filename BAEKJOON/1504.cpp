#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int n, e, v1, v2;
vector<pair<int, int>> adj[805];
int d[805];

void dijkstra(int start){
    fill(d,d+805,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[start] = 0;
    pq.push({d[start], start});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(cur.first != d[cur.second]) continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;

    // 정점1에서 출발
    dijkstra(1);
    int one_v1 = d[v1], one_v2 = d[v2];
    // 정점v1에서 출발
    dijkstra(v1);
    int v1_v2 = d[v2], v1_n = d[n];
    // 정점v2에서 출발 
    dijkstra(v2);
    int v2_v1 = d[v1], v2_n = d[n];

    int route1 = one_v1 + v1_v2 + v2_n, route2 = one_v2 + v2_v1 + v1_n;
    if(one_v1 == INF || v1_v2 == INF || v2_n == INF)
        route1 = INF;
    if(one_v2 == INF || v2_v1 == INF || v1_n == INF)
        route2 = INF;

    if(route1 == INF && route2 == INF) cout << -1;
    else
        cout << min(route1, route2);
}