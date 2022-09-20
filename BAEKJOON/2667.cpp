#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[30][30];
bool vis[30][30];
vector<int> cntVec;
int n;
int cnt = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    for(int j = 0; j < n; j++)
      board[i][j] = str[j] -'0';
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){    
        if(board[i][j] == 0 || vis[i][j]) continue;
        cnt = 0;
        queue<pair<int,int> > Q;
        vis[i][j] = 1;
        Q.push({i,j});
        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            cnt++;
            
            for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
            }
        }
        cntVec.push_back(cnt);
    }
  }
  sort(cntVec.begin(), cntVec.end());
  cout << cntVec.size() << '\n';
  for(int i=0; i<cntVec.size(); i++)
    cout << cntVec[i] << '\n';
}