#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    int j = 0, diff = 0, ans = 0x7fffffff;
    for(int i=0; i<n; i++){
        while(j < n && a[j] - a[i] < m) j++;
        if(j == n) break;
        diff = a[j] - a[i];
        ans = min(ans, diff);
    }

    cout << ans;
}