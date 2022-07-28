#include <bits/stdc++.h>
using namespace std;

int n;
int dp[305][3];
int score[305];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> score[i];

    dp[1][1] = score[1];
    dp[2][1] = score[1] + score[2]; 
    dp[2][2] = score[2]; 
    
    for(int i=3; i<=n; i++){
        dp[i][1] = dp[i-1][2] + score[i];
        dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + score[i];
    }

    cout << max(dp[n][1], dp[n][2]);
}