#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1005];
bool check[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    int ans = 0, cnt = 0;
    priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;

    check[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.first, 1, nxt.second});

    while(cnt < n-1){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if(check[b]) continue;
        check[b] = 1;
        cnt++;
        ans += cost;
        for(auto nxt : adj[b]){
            if(check[nxt.second]) continue;
            pq.push({nxt.first, b, nxt.second});
        }
    }

    cout << ans;
}