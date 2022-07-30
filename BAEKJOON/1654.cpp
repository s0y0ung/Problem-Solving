#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int k, n;
int a[10005];

bool check(ll len){
    ll cnt = 0;
    for(int i=0; i<k; i++){
        cnt += a[i]/len;
    }
    return cnt >= n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;

    for(int i=0; i<k; i++) cin >> a[i];

    sort(a, a+k);

    // 가능한 길이는 1이거나 가장 긴 랜선
    ll l=1, r=0x7fffffff;
    int len;
    while(l<=r){
        ll mid = l + (r-l)/2;
        if(check(mid)){ // 더 큰 랜선의 길이가 가능할 수도 있음
            len = mid;
            l = mid + 1;
        }
        else
            r = mid-1;
    }
    cout << len;
}