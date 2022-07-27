#include <bits/stdc++.h>
using namespace std;

int offset = 1000000;
int freq[2000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, tmp;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tmp;
        freq[tmp+offset]++;
    }

    for(int i=0; i<2000005; i++){
        if(freq[i] > 0){
            while(freq[i]){
                cout << i-offset << '\n';
                freq[i]--;
            }
        }
    }
}