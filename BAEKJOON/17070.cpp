#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int ans = 0;

// 이동할 때 파이프의 끝점만 필요, dir은 현재 파이프가 놓여있는 방향
void func(int r, int c, int dir){
    // (n,n)에 도달. 0-based index
    if(r == n-1 && c == n-1){
        ans++;
        return;
    }
    if(dir == 0){ // 가로
        // 가로 이동
        if(c+1 < n && !board[r][c+1]){
            func(r, c+1, 0);
        }
        // 대각선 이동
        if(c+1 < n && r+1 < n && !board[r+1][c+1] && !board[r][c+1] && !board[r+1][c])
            func(r+1, c+1, 2);
    }
    else if(dir==1){ // 세로
        // 세로 이동
        if(r+1 < n && !board[r+1][c])
            func(r+1, c, 1);
        // 대각선 이동
        if(c+1 < n && r+1 < n && !board[r+1][c+1] && !board[r][c+1] && !board[r+1][c])
            func(r+1, c+1, 2);
    }
    else{ // 대각선
        // 가로 이동
        if(c+1 < n && !board[r][c+1])
            func(r, c+1, 0);
        // 세로 이동
        if(r+1 < n && !board[r+1][c])
            func(r+1, c, 1);
        // 대각선 이동
        if(c+1 < n && r+1 < n && !board[r+1][c+1] && !board[r][c+1] && !board[r+1][c])
            func(r+1, c+1, 2);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    }
    // 0-based index이고 시작할 때 파이프는 가로 방향으로 누워있음
    func(0, 1 ,0);
    cout << ans;
}