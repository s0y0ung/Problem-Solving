#include <bits/stdc++.h>
using namespace std;

int n;
int board[25][25];
int ans = 0;

void printboard(){
    cout << "==========\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

void func(int k, int prev_board[25][25]){
    // k=0부터 시작하므로
    if(k==5){
        // 최댓값 갱신
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++)
                ans = max(ans, prev_board[i][j]);
        }
        return;
    }
    for(int dir=0; dir<4; dir++){
        int tmp[25][25] = {0, };
        // 위로 올린다는 가정
        if(dir == 0){
            for(int j=0; j<n; j++){
                int prev = -1, idx = 0;
                bool first = true;
                for(int i=0; i<n; i++){
                    if(prev_board[i][j]){
                        if(first){
                            prev = prev_board[i][j];
                            first = false;
                        }
                        else if(prev_board[i][j] == prev){ // 합치기
                            tmp[idx++][j] = prev_board[i][j]*2;
                            prev = -1;
                            first = true;
                        }
                        else{
                            tmp[idx++][j] = prev;
                            prev = prev_board[i][j];
                        }
                    }
                }
                if(prev!=-1)
                    tmp[idx++][j] = prev;
            }
        }
        else if(dir == 1){ // 왼쪽으로 민다는 가정
            for(int i=0; i<n; i++){
                int prev = -1, idx = 0;
                bool first = true;
                for(int j=0; j<n; j++){
                    if(prev_board[i][j]){
                        if(first){
                            prev = prev_board[i][j];
                            first = false;
                        }
                        else if(prev_board[i][j] == prev){ // 합치기
                            tmp[i][idx++] = prev_board[i][j]*2;
                            prev = -1;
                            first = true;
                        }
                        else{
                            tmp[i][idx++] = prev;
                            prev = prev_board[i][j];
                        }
                    }
                }
                if(prev!=-1)
                    tmp[i][idx++] = prev;
            }
        }
        else if(dir == 2){ // 아래로 내린다는 가정
            for(int j=0; j<n; j++){
                int prev = -1, idx = n-1;
                bool first = true;
                for(int i=n-1; i>=0; i--){
                    if(prev_board[i][j]){
                        if(first){
                            prev = prev_board[i][j];
                            first = false;
                        }
                        else if(prev_board[i][j] == prev){ // 합치기
                            tmp[idx--][j] = prev_board[i][j]*2;
                            prev = -1;
                            first = true;
                        }
                        else{
                            tmp[idx--][j] = prev;
                            prev = prev_board[i][j];
                        }
                    }
                }
                if(prev!=-1)
                    tmp[idx--][j] = prev;
            }
        }
        else{ // 오른쪽으로 민다는 가정
            for(int i=0; i<n; i++){
                int prev = -1, idx = n-1;
                bool first = true;
                for(int j=n-1; j>=0; j--){
                    if(prev_board[i][j]){
                        if(first){
                            prev = prev_board[i][j];
                            first = false;
                        }
                        else if(prev_board[i][j] == prev){ // 합치기
                            tmp[i][idx--] = prev_board[i][j]*2;
                            prev = -1;
                            first = true;
                        }
                        else{
                            tmp[i][idx--] = prev;
                            prev = prev_board[i][j];
                        }
                    }
                }
                if(prev!=-1)
                    tmp[i][idx--] = prev;
            }
        }
        func(k+1, tmp);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> board[i][j];
    }
    
    func(0, board);
    cout << ans;
}