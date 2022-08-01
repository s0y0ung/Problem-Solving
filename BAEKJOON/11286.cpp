#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        else
            return a > b;
    }
};

int n;
priority_queue<int, vector<int>, cmp> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int op;
    while(n--){
        cin >> op;
        if(op==0){
            if(pq.empty()){
                cout << "0\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
        else
            pq.push(op);
    }
}