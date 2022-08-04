#include <bits/stdc++.h>
using namespace std;

int t, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--){
        cin >> k;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=0; i<k; i++){
            int n;
            cin >> n;
            pq.push(n);
        }

        long long ans = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a+b);
        }

        cout << ans << "\n";
    }
}