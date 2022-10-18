#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    vector<pair<int, int>> class_info(n);
    for(int i=0; i<n; i++){
        cin >> class_info[i].first >> class_info[i].second;
    }

    // 시작 시간 오름차순 정렬 필요 (pq에는 끝 시간만 담을거기 때문)
    sort(class_info.begin(), class_info.end());

    // 끝나는 시간만 저장 => 끝나는 시간이 빠른 순으로 정렬 = 최소힙
    priority_queue<int, vector<int>, greater<int>> room;
    room.push(class_info[0].second);

    for(int i=1; i<n; i++){
        // 연강 가능
        if(room.top() <= class_info[i].first){
            room.pop();
            room.push(class_info[i].second);
        }
        // 연강 불가능
        else{
            room.push(class_info[i].second);
        }
    }

    cout << room.size();

}