#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[25];
int ans = 0;

void func(int cnt, int sum){
    if(cnt == n){
        if(sum == s) ans++;
        return;
    }
    // 부분수열에 추가하지 않았을 경우
    func(cnt + 1, sum);
    // 부분수열에 추가할 경우
    func(cnt + 1, sum+arr[cnt]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    func(0, 0);
    // 공집합인 경우 주의 (s=0인경우 공집합일 때 s==sum이 됨)
    if(s==0) ans--;
    cout << ans;
}