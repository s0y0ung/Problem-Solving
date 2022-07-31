#include <bits/stdc++.h>
using namespace std;

int n;
int a[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    int m, target;
    cin >> m;
    while(m--){
        cin >> target;
        cout << upper_bound(a, a+n, target) - lower_bound(a, a+n, target) << " ";
    }

}