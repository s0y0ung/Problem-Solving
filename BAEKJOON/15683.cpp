#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;
int board1[10][10];
int board2[10][10];
vector<pair<int,int> > cctv;

bool OOB(int x, int y){ // check Out of Bound
    return x >= n || x < 0 || y >= m || y < 0;
}

void upd(int x, int y, int dir){ // (x,y)에서 dir 방향으로 진행하면서 벽을 만날 때까지 지나치는 모든 빈칸을 7로 바꿔버림
    dir%=4;
    while(1){
        x += dy[dir];
        y += dx[dir];
        
        if(OOB(x,y) || board2[x][y]==6) return; // out of bound이거나 벽을 만난 경우 함수 탈출
        if(board2[x][y] != 0) continue; // (x,y)가 cctv인 경우 pass
        board2[x][y] = 7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board1[i][j];
            if(board1[i][j] != 0 && board1[i][j] != 6) cctv.push_back({i,j});
            if(board1[i][j]==0) answer++;
        }
    }
    
    for(int tmp=0; tmp < (1<<(2*cctv.size())); tmp++){
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                board2[i][j] = board1[i][j];
            }
        }
        int brute = tmp;
        for(int i=0; i<cctv.size(); i++){
            int dir = brute%4;
            brute /=4;
            int x = cctv[i].X;
            int y = cctv[i].Y;

            if(board1[x][y]==1){
                upd(x,y,dir);
            }
            else if(board1[x][y]==2){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }
            else if(board1[x][y]==3){
                upd(x,y,dir);
                upd(x,y,dir+1);
            }
            else if(board1[x][y]==4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            else{ // board1[x][y] == 5
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cnt += (board2[i][j]==0);
        answer = min(answer, cnt);
    }
    cout << answer;
}