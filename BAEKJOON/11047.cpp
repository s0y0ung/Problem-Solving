#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> coins[i];
    }

    int cnt = 0;
    for(int i=n; i>0; i--){
        if(k >= coins[i]){
            cnt += k/coins[i];
            k %= coins[i];
        }
    }

    cout << cnt;
}