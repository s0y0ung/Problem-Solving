#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[25][25];
int top, bottom, front, back, l, r;

bool east(){
    // out of bound 체크
    if(y+1 >= m) return false;
    y++;
    int tmp = top;
    int tmp2 = bottom;
    top = r;
    bottom = l;
    l = tmp;
    r = tmp2;
    return true;
}

bool west(){
    // out of bound 체크
    if(y-1 < 0) return false;
    y--;
    int tmp = top;
    int tmp2 = bottom;
    top = l;
    bottom = r;
    l = tmp2;
    r = tmp;
    return true;
}

bool north(){
    // out of bound 체크
    if(x-1 < 0) return false;
    x--;
    int tmp = top;
    int tmp2 = bottom;
    top = back;
    bottom = front;
    back = tmp2;
    front = tmp;
    return true;
}

bool south(){
    // out of bound 체크
    if(x+1 >= n) return false;
    x++;
    int tmp = top;
    int tmp2 = bottom;
    top = front;
    bottom = back;
    back = tmp;
    front = tmp2;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> board[i][j];
    }

    while(k--){
        int dir;
        cin >> dir;
        bool cango = 0;
        if(dir==1){
            cango = east();        
        }
        else if(dir==2){
            cango = west();
        }
        else if(dir==3){
            cango = north();
        }
        else{
            cango = south();
        }

        // 바닥 혹은 칸 값 변경
        if(!cango) continue;
        if(board[x][y]){
            bottom = board[x][y];
            board[x][y] = 0;
        }
        else
            board[x][y] = bottom;
        cout << top << "\n";
    }
    
}