#include <bits/stdc++.h>
using namespace std;

int n;
string expression;
int ans = INT_MIN;

int cal(int a, int b, char op){
    if(op=='+')
        return a + b;
    else if(op=='-')
        return a - b;
    
    return a * b;
}

void func(int idx, int cur){
    if(idx >= n-1){
        ans = max(ans, cur);
        return;
    }
    // 괄호 묶기
    if(idx + 4 < n){
        int a  = expression[idx + 2] - '0';
        int b  = expression[idx + 4] - '0';
        char op  = expression[idx + 3];
        int bracket = cal(a, b, op);
        int res = cal(cur, bracket, expression[idx+1]);
        func(idx + 4, res);
    }
    // 괄호 안 묶기
    int res = cal(cur, expression[idx+2]-'0', expression[idx+1]);
    func(idx+2, res);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> expression;
    func(0, expression[0] - '0');
    cout << ans;
}