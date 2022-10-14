#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> date[10001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++){
        int d, p;
        cin >> p >> d;
        date[d].push_back(p);
    }

    int ans = 0;
    priority_queue<int> pq;
    // 날짜 기준으로
    for(int d = 10000; d>0; d--){
        for(auto p:date[d])
            pq.push(p);
        
        if(pq.empty()) continue;
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
    
}