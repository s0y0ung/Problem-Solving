#include <bits/stdc++.h>
using namespace std;

int n, h;
int low[500005];
int high[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    for(int i=0; i<n/2; i++){
        cin >> low[i] >> high[i];
    }

    sort(low, low+n/2);
    sort(high, high+n/2);

    int num = n, section = 0;
    for(int i=1; i<=h; i++){
        // 높이가 i일 때 파괴해야 하는 장애물 수
        // low의 경우 높이보다 크거나 같다면 부딪힘, high의 경우 (h - 높이)보다 클 때 부딪힘
        int low_destory = lower_bound(low, low+n/2, i) - low;
        int high_destory = upper_bound(high, high+n/2, h-i) - high;

        int destory = (n/2 - low_destory) + (n/2 - high_destory);

        // 장애물 최솟값이 더 작다면
        if(num > destory){
            num = destory;
            section=1;
        }
        // 장애물 최솟값이 같다면 section++
        else if(num == destory){
            section++;
        }
    }

    cout << num << " " << section << "\n";
}