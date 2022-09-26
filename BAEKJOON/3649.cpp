#include <bits/stdc++.h>
using namespace std;

int x, n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> x){
        cin >> n;
        x = x * 10000000;
        vector<int> lego;
        for(int i=0; i<n; i++){
            int len;
            cin >> len;
            lego.push_back(len);
        }

        sort(lego.begin(), lego.end());

        bool danger = true;
        for(int i=0; i<n; i++){
            int target = x - lego[i];
            int find = lower_bound(lego.begin(), lego.end(), target) - lego.begin();
            // target을 찾았고, 자기 자신이 아닌 경우
            if(lego[find]==target && find!=i){
                danger = false;
                cout << "yes " << lego[i] << " " << target << "\n";
                break;
            }
        }
        if(danger)
            cout << "danger\n";
    }
}