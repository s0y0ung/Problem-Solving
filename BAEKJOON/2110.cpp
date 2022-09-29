#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<long long> v;

bool check(int mid){
    int cnt = 0, s = 0;
    for(int i = 1; i<n; i++){
        if(v[i] - v[s] >= mid){
            s = i;
            cnt++;
        }
    }

    if(cnt >= c-1) return true;
    else
        return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        v.push_back(h);
    }

    sort(v.begin(), v.end());

    // 가능한 길이는 1이거나 가장 긴 랜선
    long long l=1, r=1000000000;
    int len;
    while(l<=r){
        long long mid = l + (r-l)/2;
        if(check(mid)){
            len = mid;
            l = mid + 1;
        }
        else
            r = mid-1;
    }
    cout << len;
}