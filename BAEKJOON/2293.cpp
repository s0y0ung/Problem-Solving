#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[105];
int dp[10005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    dp[0] = 1;
    for(int j=0; j<n; j++){
        for(int i=coins[j]; i<=k; i++){
            dp[i] += dp[i-coins[j]];
        }
    }
    cout << dp[k];
}