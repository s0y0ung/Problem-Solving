#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int time = 0;
    for(int i=0; i<n; i++)
        time += v[i] * (n - i);

    cout << time;
}