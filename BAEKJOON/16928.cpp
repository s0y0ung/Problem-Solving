#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[101];
int dist[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i < n + m; i++){
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    fill(dist, dist+101, -1);

    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=1; i<=6; i++){
            int nxt = cur + i;
            if(nxt > 100) continue;
            if(board[nxt]) nxt = board[nxt];
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    cout << dist[100];
}