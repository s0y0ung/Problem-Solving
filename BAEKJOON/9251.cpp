#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005][1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.length(); 
    int m = b.length();

    // 편의상 dp는 1-based index 사용
    for(int i=1 ; i<= n; i++){
        for(int j=1; j<= m; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[n][m];
}