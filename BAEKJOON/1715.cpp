#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int k;
    for(int i=0; i<n; i++){
        cin >> k;
        pq.push(k);
    }

    int cnt = 0, a, b;
    while(pq.size() > 1){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        cnt += a+b;
        pq.push(a+b);
    }

    cout << cnt;
}