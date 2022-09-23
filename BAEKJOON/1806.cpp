#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;

    for(int i=0; i<n; i++) cin >> a[i];

    int i = 0, j = 0, sum = 0, ans = 100005;
    for(; i<n; i++){
        while(j < n && sum + a[j]< s){
            sum+=a[j++];
        }
        if(j==n) break;
        ans = min(ans, j - i + 1);
        sum -= a[i];
    }

    if(ans == 100005) cout << "0";
    else
        cout << ans;
}