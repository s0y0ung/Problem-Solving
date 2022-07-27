#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    long long answer = 0, max=0, cnt;
    int e;
    for(int s=0; s<n; s++){
        e = s;
        cnt = 0;
        while(arr[s] == arr[e] && e<n) {
            cnt++; 
            e++; 
        }
        if(cnt > max) {
            max = cnt; 
            answer = arr[s];
        }
        s = e-1;
    }

    cout << answer;
}