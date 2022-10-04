#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_set<string> us;
set<string> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(n--){
        string str;
        cin >> str;
        us.insert(str);
    }

    while(m--){
        string str;
        cin >> str;
        if(us.find(str) != us.end())
            ans.insert(str);
    }

    cout << ans.size() << "\n";
    for(auto i : ans)
        cout << i << "\n";
    
}