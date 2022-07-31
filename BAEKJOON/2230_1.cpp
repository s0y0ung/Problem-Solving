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

    int ans = 0x7fffffff, idx;
    for(int i=0; i<n; i++){
        idx = lower_bound(a, a+n, m + a[i]) - a;
        if(idx != n)
            ans = min(ans, a[idx] - a[i]);
    }
    cout << ans;
}