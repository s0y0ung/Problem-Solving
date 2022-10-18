#include <bits/stdc++.h>
using namespace std;

int n, ans=0;
bool isused1[16]; // 같은 열
bool isused2[40]; // 왼쪽 아래 / 대각선
bool isused3[40]; // 오른쪽 아래 \ 대각선

void func(int row){
    if(row == n){ // n개의 퀸을 다 놓았다면
        ans++;
        return;
    }
    for(int i=0; i<n; i++){
        if(isused1[i] || isused2[i+row] || isused3[row-i+n-1]) continue; // 하나라도 잡힐 위험이 있다면 놓을 수 없음
        // 퀸 놓고 마스킹
        isused1[i] = 1;
        isused2[i+row] = 1;
        isused3[row-i+n-1] = 1;
        func(row+1);
        // 마스킹 해제
        isused1[i] = 0;
        isused2[i+row] = 0;
        isused3[row-i+n-1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << ans;
}