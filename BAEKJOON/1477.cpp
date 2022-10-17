#include <bits/stdc++.h>
using namespace std;

int n, m, L;
vector<int> building;
vector<int> dist;
int ans;

bool check(int mid){
    int cnt = 0;
    for(int i=0; i<dist.size(); i++){
        cnt += dist[i]/mid;
        // 나눠 떨어지는 경우 하나 빼줘야 함
        // ex) 201(시작), 271, 341, 411(끝)
        if(dist[i]%mid == 0){ 
            cnt -= 1;
        }   
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> L;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        building.push_back(a);
    }
    building.push_back(0);
    building.push_back(L);

    sort(building.begin(), building.end());
    for(int i=0; i<building.size()-1; i++){
        dist.push_back(building[i+1] - building[i]);
    }

    int l = 1, r = 1000;
    while (l <= r){
        int mid = l + (r-l)/2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}