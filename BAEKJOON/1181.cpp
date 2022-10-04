#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pair<int, string>> v;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        v.push_back({str.length(), str});
    }
    
    sort(v.begin(), v.end());

    cout << v[0].second << "\n";
    string prev = v[0].second;

    for(int i=1; i<n; i++){
        if(prev.compare(v[i].second)){
            cout << v[i].second << "\n";
        }
        prev = v[i].second;
    }
}