#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int arr[10];
int res[10];

void func(int len){
    // base condition
    if(len == m){
        for(int i=0; i<m; i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }

    // general condition
    for(int i=0; i<n; i++){
        if(!isused[i]){
            res[len] = arr[i];
            isused[i] = true;
            func(len + 1);
            isused[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++)
        arr[i] = i+1;

    func(0);
}