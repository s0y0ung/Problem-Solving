#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<pair<int, int>> adj[10005];
bool check[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    
    int cnt = 0, sum = 0;

    // {비용, 정점1, 정점2}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for(auto nxt : adj[1]){
        pq.push({nxt.first, 1, nxt.second});
    }
    check[1] = true;
    while(cnt < v-1){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if(check[b]) continue;
        check[b] = true;
        sum += cost;
        cnt++;
        for(auto nxt : adj[b]){
            if(check[nxt.second]) continue;
            pq.push({nxt.first, b, nxt.second});
        }
    }
    cout << sum;
}