#include <bits/stdc++.h>
using namespace std;

int n, s;
int nums[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    // int i = 0, j =0, sum=0;
    int len = 200000;
    // while(i <= j && j < n){
    //     if(sum < s) sum += nums[j++];
    //     else if(sum == s){

    //     }
            
    // }

    int l = 0, sum = 0;
    for(int r = 0; r<n; r++){
        sum += nums[r];

        while(sum >= s && l < n){
            len = min(len, r-l+1);
            sum -= nums[l++];
        }
    }

    if(len == 200000)
        cout << "0";
    else
        cout << len;
}