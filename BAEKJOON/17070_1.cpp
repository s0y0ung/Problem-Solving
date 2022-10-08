#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int dp[20][20][3];
int ans = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    }

    // 벽을 만나기 전까지 가로로 쭉 밀 수 있음
    for(int i=1; i<n; i++){
        if(board[0][i]) break;
        dp[0][i][0] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            // 벽인 경우 이동 불가
            if(board[i][j]) continue;
            // 가로로 온 경우: 가로->가로, 대각선->가로
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
            // 세로
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
            // 대각선
            // 대각선으로 오기 위해서는 자기 자리만 비어있으면 안됨. 2자리 추가로 더 비어있어야 함.
            if(board[i-1][j] || board[i][j-1]) continue;
            dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }

    ans = dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2];
    cout << ans;
}