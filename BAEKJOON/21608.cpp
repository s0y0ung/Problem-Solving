#include <bits/stdc++.h>
using namespace std;

int n;
int board[25][25];
vector<int> adj[405];
int score[5] = {0, 1, 10, 100, 1000};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int getLike(int x, int y){
    int cnt = 0;
    int s = board[x][y];
    for(int dir = 0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx>=n || ny<0 || ny>=n) continue;
        for(int l=0; l<4; l++){
            if(adj[s][l] == board[nx][ny]) cnt++;
        }
    }
    return cnt;
}

void find_place(int s){
    int x=0, y=0;
    int blank=-1, likely=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]) continue; // 이미 학생이 있음
            int num_like=0, num_blank=0;
            // 인접한 칸(상하좌우) 탐색하면서 빈칸, 좋아하는 학생 수 카운트
            for(int dir = 0; dir<4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx>=n || ny<0 || ny>=n) continue;
                for(int l=0; l<4; l++){
                    if(adj[s][l] == board[nx][ny]) num_like++;
                }
                if(!board[nx][ny]) num_blank++;
            }
            // 좋아하는 학생 많은 순
            if(num_like > likely){
                x=i; y=j; likely=num_like; blank = num_blank;
            }
            else if(num_like == likely){
                if(num_blank > blank){ // 빈칸 많은 순
                    x=i; y=j; blank = num_blank;
                }
                else if(num_blank == blank) // 행렬 빠른 순이므로 continue
                    continue;
            }
        }
    }
    // board 배열에 학생 배치
    board[x][y] = s;
    // cout << "student " << s << " seat " << x << " " << y << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int N = n*n;
    while(N--){
        int s, a, b, c, d;
        cin >> s >> a >> b >> c >> d;
        adj[s].push_back(a);
        adj[s].push_back(b);
        adj[s].push_back(c);
        adj[s].push_back(d);

        // 자리 찾기
        find_place(s);
    }

    int ans = 0;
    // 만족도 조사
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int likely = getLike(i, j);
            ans += score[likely];
        }
    }

    cout << ans;
}