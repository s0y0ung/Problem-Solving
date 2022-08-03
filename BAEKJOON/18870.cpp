#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
vector<int> tmp, uni;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        tmp.push_back(a[i]);
    }

    sort(tmp.begin(), tmp.end());
    // 중복제거
    uni.push_back(tmp[0]);
    for(int i=1; i<n; i++){
        if(tmp[i-1] != tmp[i]) uni.push_back(tmp[i]);
    }

    for(int i=0; i<n; i++){
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
    }
}