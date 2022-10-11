#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005];
int pre[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    fill(pre, pre+1005, -1);
    dp[0] = 1;
    for(int i=1; i<n; i++){
        // 자기보다 작은 애들 중 dp 최대값 찾기
        int len = 0, idx = i;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(dp[j] > dp[idx]){
                    idx = j;
                    len = dp[j];
                }
            }
        }
        if(len){
            dp[i] = dp[idx] + 1;
            pre[i] = idx;
        }
        else{ // 자기가 시작점인 경우
            dp[i] = 1;
        }
    }

    // dp의 최댓값의 인덱스
    int mx = 0;
    for(int i=0; i<n; i++)
        mx = dp[mx] < dp[i] ? i : mx;
    
    cout << dp[mx] << "\n";
    vector<int> res;
    while(pre[mx]!=-1){
        res.push_back(arr[mx]);
        mx = pre[mx];
    }
    res.push_back(arr[mx]);

    for(int i=res.size()-1; i>=0; i--)
        cout << res[i] << " ";
}