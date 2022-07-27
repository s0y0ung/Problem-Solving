#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr1[1000005];
int arr2[1000005];
int answer[2000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr1[i];
    for(int i=0; i<m; i++) cin >> arr2[i];
    int idx = 0;
    int a = 0, b= 0;
    // 둘 중 하나를 다 담을 때까지 반복
    while(1){
        if(a >= n || b >= m) break;
        if(arr1[a] > arr2[b]) answer[idx++] = arr2[b++];
        else
            answer[idx++] = arr1[a++];
        cout << answer[idx-1] << ' ';
    }
    // 남은 배열 처리
    if(a < n){
        for(; a<n; a++) {
            // answer[idx++] = arr1[a];
            cout << arr1[a] << ' ';
        }
    }
    if(b < m){
        for(; b<m; b++) {
            // answer[idx++] = arr2[b];
            cout << arr2[b] << ' ';
        }
    }
}