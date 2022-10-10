#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[25][25];
// back, top, front, bottom, left, right
int dice[7] = {0, 2, 1, 5, 6, 4, 3};
int dir, x = 0, y= 0;
int ans = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
// {1,2,3,4} 방향이 시계, 반시계로 90도 회전하면 각각 아래처럼 변함. 0은 더미값
int rotate_clock[5] = {0,4,3,1,2};
int rotate_clockwise[5] = {0,3,4,2,1};

bool OOB(int d){
    if(d==1 && y+1 >= m) return true;
    else if(d==2 && y-1 < 0) return true;
    else if(d==3 && x-1 < 0) return true;
    else if(d==4 && x+1 >= n) return true;
    return false;
}

void roll(int d){
    if(d==1){
        int tmp = dice[2];
        dice[2] = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[6];
        dice[6] = tmp;
        y++;
    }
    else if(d==2){
        int tmp = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[4];
        dice[4] = dice[5];
        dice[5] = tmp;        
        y--;
    }
    else if(d==3){
        int tmp = dice[1];
        dice[1] = dice[2];        
        dice[2] = dice[3];
        dice[3] = dice[4];
        dice[4] = tmp;
        x--;
    }
    else{
        int tmp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[2];
        dice[2] = tmp;
        x++;
    }
}

int getscore(int bottom){
    int cnt = 0;
    int vis[25][25];
    for(int i=0; i<n; i++)
        fill(vis[i], vis[i]+m, 0);
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        cnt++;
        for(int d = 0; d<4; d++){
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if(nx<0 || nx >=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny] || board[nx][ny]!=bottom) continue; // 이미 방문했거나, 바닥이랑 숫자가 다른 경우
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    return bottom*cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    }

    // 처음엔 동쪽으로 이동
    dir = 1;
    while(k--){
        if(OOB(dir)){
            if(dir==1) dir = 2;
            else if(dir==2) dir = 1;
            else if(dir==3) dir = 4;
            else
                dir = 3;
        }
        // 한 칸 굴러감
        roll(dir);
        // 점수 획득
        ans += getscore(board[x][y]);
        // 방향 정하기
        if(dice[4] > board[x][y])
            dir = rotate_clock[dir];
        else if(dice[4] < board[x][y])
            dir = rotate_clockwise[dir];
    }
     cout << ans;
}