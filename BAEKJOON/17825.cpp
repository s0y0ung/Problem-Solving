#include <bits/stdc++.h>
using namespace std;

int nxt[55];
int score[55];
int dice[10];
int pos[4];
int ans = 0;

vector<int> res(10);
vector<int> answer(10);

int move(int p, int m){
    int st = pos[p]; bool fin = false; bool blue = false;
    if(st == 5 || st==10 || st ==15){
        st = nxt[st]-1;
        blue = true;
    }
    // 이동
    for(int i=0; i<m; i++){
        if(st >= 21 && st < 28){ // 도착
            fin = true;
            break;
        }
        if(!blue && (st == 5 || st==10 || st ==15)) st++;
        else if(!nxt[st]) st++;
        else
            st = nxt[st];
    }
    if(fin){
        pos[p] = st;
        return 0;
    }
    // 해당 칸에 이미 말이 있는지 확인
    for(int i=0; i<4; i++){
        if(i!=p && pos[i] == st) // 말 이동 불가
            return -1;
    }
    pos[p] = st;
    return score[st];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<10; i++)
        cin >> dice[i];
    
    nxt[5] = 30; nxt[10] = 35; nxt[15] = 40; 
    nxt[32] = nxt[36] = nxt[42] = 50; nxt[52] = 20;
    for(int i=0; i<21; i++)
        score[i] = i*2;
    score[30] = 13; score[31] = 16; score[32] = 19; score[35] = 22; score[36] = 24;
    score[40] = 28; score[41] = 27; score[42] = 26; score[50] = 25; score[51] = 30; score[52] = 35;

    // 4개의 말에 대해 중복순열
    int brute = (1 << 20);
    for(int i=0; i<brute; i++){
        int tmp = i; 
        bool can = true;
        int sum = 0, s, idx = 0;
        fill(pos, pos+4, 0);
        while(idx < 10){
            // 이동
            s = move(tmp%4, dice[idx++]);
            // 점수 업데이트
            if(s==-1){ // 이미 다른 말이 있기 때문에 이동할 수 없음
                can = false;
                break;
            }
            sum += s;
            tmp = tmp/4;
        }
        if(can)
            ans = max(ans, sum);
    }
    cout << ans;
}