#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> v[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int s, e;
    for(int i=0; i<n; i++){
        cin >> v[i].second >> v[i].first;
    }

    sort(v, v+n);

    int cnt = 0;
    e=0;
    for(int i=0; i<n; i++){
        if(v[i].second  >= e){
            e = v[i].first;
            cnt++;
        }
    }

    cout << cnt;
}