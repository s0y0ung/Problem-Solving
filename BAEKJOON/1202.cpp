#include <bits/stdc++.h>
using namespace std;

int n, k;
pair<int, int> stuff[300005];
multiset<int> bags;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> stuff[i].second >> stuff[i].first;
    }

    sort(stuff, stuff+n);

    for(int i=0; i<k; i++){
        int c;
        cin >> c;
        bags.insert(c);
    }

    long long ans = 0;
    for(int i=n-1; i>=0; i--){
        auto item = bags.lower_bound(stuff[i].second);
        if(item == bags.end()) continue;
        ans += stuff[i].first;
        bags.erase(item);
        // if(item != bags.end()){
        //     ans += stuff[i].first;
        //     bags.erase(item);
        // }
    }
    cout << ans;
}