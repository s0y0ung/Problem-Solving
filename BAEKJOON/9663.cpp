#include <bits/stdc++.h>
using namespace std;

int n;
int check[16][16];
int ans = 0;

void printboard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << check[i][j] << " ";
        cout << "\n";
    }
    cout << "\n\n";
}

void func(int queen){
    if(queen==n){ // 퀸을 n개 다 놓음
        ans++;
        return;
    }
    for(int i=0; i<n; i++){ // 각 열에 대해
        if(!check[queen][i]){ // 퀸을 놓을 수 있음
            check[queen][i] = queen+1; // queen = 0부터 시작이므로 queen+1로 마스킹
            int cnt = 1;
            for(int d=queen+1; d<n; d++){ // 아래, 아래 대각선 방향 마킹
                if(check[d][i]==0) check[d][i] = queen+1; // 아래
                if(i-cnt >= 0 && check[d][i-cnt]==0) check[d][i-cnt] = queen+1; // 아래 왼쪽 대각선
                if(i+cnt < n && check[d][i+cnt]==0) check[d][i+cnt] = queen+1; // 아래 오른쪽 대각선
                cnt++;
            }
            func(queen + 1);
            // 마스킹 복귀
            check[queen][i] = 0;
            cnt = 1;
            for(int d=queen+1; d<n; d++){ // 아래, 아래 대각선 방향 마킹
                if(check[d][i]==queen+1) check[d][i] = 0; // 아래
                if(i-cnt >= 0 && check[d][i-cnt]==queen+1) check[d][i-cnt] = 0; // 아래 왼쪽 대각선
                if(i+cnt < n && check[d][i+cnt]==queen+1) check[d][i+cnt] = 0; // 아래 오른쪽 대각선
                cnt++;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << ans;
}
