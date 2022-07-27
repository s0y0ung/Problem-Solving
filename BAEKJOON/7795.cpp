#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[20005];
int b[20005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--){ // count test case
        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        sort(a, a+n);
        sort(b, b+m);

        int cnt=0, answer=0, j=0;
        for(int i=0; i<n; i++){
            while((j < m) && (a[i] > b[j])) {cnt++; j++;}
                answer+=cnt;
        }

        cout << answer << "\n";
    }
}