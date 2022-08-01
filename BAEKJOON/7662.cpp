#include <bits/stdc++.h>
using namespace std;

int t, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    char op;
    int n;
    while(t--){
        cin >> k;
        multiset<int> s;
        while(k--){
            cin >> op >> n;
            if(op == 'I') s.insert(n);
            else{ // OP = 'D'
                if(s.empty()) continue;
                if(n == -1){
                    auto item = s.begin();
                    s.erase(item);
                }
                else{
                    auto item = prev(s.end());
                    s.erase(item);
                }
            }
        }

        if(s.empty())   cout << "EMPTY\n";
        else{
            cout << *prev(s.end()) << ' ' << *s.begin() << "\n";
        }
    }
}