#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[105][100005];
int w[105];
int v[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            // 넣을 수 있다면
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else // 넣을 수 없다면
                dp[i][j]  = dp[i-1][j];
        }
    }

    cout << dp[n][k];
}