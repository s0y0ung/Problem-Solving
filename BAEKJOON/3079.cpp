#include <bits/stdc++.h>
using namespace std;

long long n, m;

bool check(long long mid, vector<long long> time){
    long long can = 0;
    for(auto i : time){
        can += (mid/i);
    }
    
    return can >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    vector<long long> time(n);
    long long maxtime = 1;
    for(int i=0; i<n; i++){
        cin >> time[i];
        maxtime = max(maxtime, time[i]);
    }

    long long l = 0, r = maxtime*m;
    long long ans;

    while (l <= r){
        long long mid = l + (r-l)/2;
        if(check(mid, time)){
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;

    }
    
    cout << ans;
}