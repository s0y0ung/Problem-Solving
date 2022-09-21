#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1005];
int b[1005];
vector<int> as, bs;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    for(int i=0; i<m; i++) cin >> b[i];

    // a의 모든 부분합
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            as.push_back(sum);
        }
    }

    // b의 모든 부분합
    for(int i=0; i<m; i++){
        int sum = 0;
        for(int j=i; j<m; j++){
            sum += b[j];
            bs.push_back(sum);
        }
    }

    sort(bs.begin(), bs.end());

    long long ans = 0;
    for(int i=0; i<as.size(); i++){
        int target = t - as[i];
        ans += upper_bound(bs.begin(), bs.end(), target) - lower_bound(bs.begin(), bs.end(), target);
    }

    cout << ans;
}