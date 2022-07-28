#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000005];
int tracking[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    tracking[2] = 1;
    tracking[3] = 1;

    for(int i=4; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        tracking[i] = i-1;
        if((i%2 == 0) && (dp[i] > dp[i/2] + 1)) {
            dp[i] =dp[i/2] + 1;
            tracking[i] = i/2;
        }
        if((i%3 == 0) && (dp[i] > dp[i/3] + 1)) {
            dp[i] =dp[i/3] + 1;
            tracking[i] = i/3;
        }
    }

    cout << dp[n] << "\n";
    int pre = n;
    while(pre!=1){
        cout << pre << ' ';
        pre = tracking[pre];
    }
    cout << '1';
}