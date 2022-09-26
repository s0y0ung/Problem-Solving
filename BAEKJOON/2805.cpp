#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> tree;

bool check(long long mid){
    long long take = 0;
    for(int i=0; i<n; i++){
        if(tree[i] - mid > 0)
            take += (tree[i] - mid);
    }

    return take >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int len;
        cin >> len;
        tree.push_back(len);
    }

    sort(tree.begin(), tree.end());

    // 절단할 높이는 나무 기준이기 때문에 l, r은 나무 높이 기준
    long long l = 0, r = 1000000000;
    long long ans;
    while(l <= r){
        long long mid = l + (r-l)/2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ans;
    
}