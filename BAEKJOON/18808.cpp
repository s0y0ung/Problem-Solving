#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[45][45];
int sticker[45][45];
int cnt = 0;
int sr, sc;

void printboard(){
    cout << "===========\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

void printsticker(){
    cout << "===========\n";
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++)
            cout << sticker[i][j] << " ";
        cout << "\n";
    }
}

void rotate(){
    int tmp[45][45];
    for(int r=0; r<sr; r++){
        for(int c=0; c<sc; c++)
            tmp[r][c] = sticker[r][c];
    }

    for(int a = 0; a<45; a++)
        fill(sticker[a], sticker[a]+45, 0);

    for(int r=0; r<sr; r++){
        for(int c=0; c<sc; c++)
            sticker[c][sr-1-r] = tmp[r][c];
    }
    swap(sr, sc);
}

bool check_attach(int br, int bc, int sr, int sc){
    // 스티커가 보드 크기 넘어감
    if(br+sr > n || bc+sc > m) return false;
    
    for(int i=0; i<sr; i++){
        for(int j=0; j<sc; j++){
            // 스티커 붙여야 되는데 이미 다른 스티커 붙어 있음
            if(sticker[i][j] && board[i+br][j+bc]) return false;
        }
    }
    return true;
}

void attach(int br, int bc, int sr, int sc){
    for(int i=0; i<sr; i++){
        for(int j=0; j<sc; j++){
            if(sticker[i][j]){
                board[i+br][j+bc] = sticker[i][j];
                cnt++;
            }
        }
    }
}

bool find(int sr, int sc){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 붙일 수 있으면 
            if(check_attach(i, j, sr, sc)){
                attach(i, j, sr, sc);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<k; i++){
        cin >> sr >> sc;
        // 스티커 배열 초기화
        for(int a = 0; a<45; a++)
            fill(sticker[a], sticker[a]+45, 0);

        for(int r=0; r<sr; r++){
            for(int c=0; c<sc; c++){
                cin >> sticker[r][c];
            }
        }
        // 스티커 붙이기
        for(int turn = 0; turn<4; turn++){
            if(find(sr, sc))
                    break;
            rotate();
        }
    }
    cout << cnt;
}