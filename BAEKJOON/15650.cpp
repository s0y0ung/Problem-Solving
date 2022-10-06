#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int arr[10];
int res[10];

void func(int len, int st){
    // base condition
    if(len == m){
        for(int i=0; i<m; i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }
    // arr가 이미 오름차순으로 정렬되어 있다는 가정하에
    for(int i=st; i<n; i++){ 
        if(!isused[i]){
            res[len] = arr[i];
            isused[i] = true;
            func(len + 1, i); // 다음 수를 정할 때, i부터 봄. 사실상 i+1부터 확인함.
            isused[i] = false;
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        arr[i] = i+1;

    func(0, 0);
}