#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;
int board[55][55];
int vis[55][55];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        int ans = 0;
        fill(&vis[0][0], &vis[54][54], 0);
        fill(&board[0][0], &board[54][54], 0);

        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!board[i][j] || vis[i][j]) continue;
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;

                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir<4; dir++){
                        int x = cur.first + dx[dir];
                        int y = cur.second + dy[dir];
                        if(x <0 || x >= m || y<0 || y >= n) continue;
                        if(!board[x][y] || vis[x][y]) continue;
                        q.push({x, y});
                        vis[x][y] = 1;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}