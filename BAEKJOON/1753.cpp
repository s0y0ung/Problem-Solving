#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int v, e, st;
vector<pair<int, int>> adj[20005];
int d[20005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> st;
    fill(d,d+v+1,INF);
    
    for(int i=0; i<e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    d[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        // 해당 거리가 최단 거리 테이블에 있는 값과 다를 경우 넘어감
        if(d[cur] != cost) continue;
        for(auto nxt : adj[cur]){
            // 거쳐 가는게 더 작을 때만 업데이트
            if(d[nxt.second] > d[cur] + nxt.first){
                d[nxt.second] = d[cur] + nxt.first;
                pq.push({d[nxt.second], nxt.second});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(d[i] == INF) cout << "INF\n";
        else
            cout << d[i] << "\n";
    }

}