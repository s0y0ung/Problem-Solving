#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10][10];
int tmp[10][10];
int vis[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans;
vector<pair<int, int> > blank;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j]==0)
                blank.push_back({i, j});
        }
    }
    
    // 빈 칸 중에서 벽이 될 좌표 3개 조합
    vector<int>brute(blank.size(), 1);
    fill(brute.begin(), brute.begin()+blank.size()-3, 0);
    do{
        // tmp 배열 복사, vis 배열 초기화, 바이러스 좌표 큐에 담기
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            fill(vis[i], vis[i]+10, 0);
            for(int j=0; j<m; j++){
                tmp[i][j] = board[i][j];
                if(board[i][j]==2){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        // 새로운 벽 3개 추가
        for(int i =0; i<blank.size(); i++){
            if(brute[i]==0) continue;
            auto wall = blank[i];
            tmp[wall.first][wall.second] = 1;
        }
        // bfs
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(vis[nx][ny] || tmp[nx][ny]!=0) continue;
                q.push({nx, ny});
                vis[nx][ny] = 1;
                tmp[nx][ny] = 2;
            }
        }
        // 안전 영역 최솟값 갱신
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(tmp[i][j]==0)
                    cnt++;
            }
        }
        ans = max(ans, cnt);

    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans;
}