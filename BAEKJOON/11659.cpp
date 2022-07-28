#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> dp[i];
        dp[i] += dp[i-1];
    }

    int i, j;
    while(m--){
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << "\n";
    }
}