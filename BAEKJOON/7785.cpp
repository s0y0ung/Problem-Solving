#include <bits/stdc++.h>
using namespace std;

int n;
set<string> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string name, status;

    while(n--){
        cin >> name >> status;
        if(!status.compare("enter")){
            s.insert(name);
        }
        else
            s.erase(name);
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto e : ans) cout << e << '\n';
}