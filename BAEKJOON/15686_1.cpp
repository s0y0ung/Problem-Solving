#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
int board[55][55];
int dist[55][55];
int dx[4] = {1, 0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
int ans = 0x7f7f7f7f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j]==2)
                chickens.push_back({i, j});
            else if(board[i][j]==1)
                houses.push_back({i, j});
        }
    }

    // m개의 집 조합
    vector<int> combi(chickens.size(), 1);
    fill(combi.begin(), combi.begin()+chickens.size()-m, 0);
    do{
        int sum = 0;
        for(int j=0; j<houses.size(); j++){
            int mn = 0x7f7f7f7f; 
            for(int i=0; i<chickens.size(); i++){
                if(combi[i] == 0) continue;
                mn = min(mn, abs(houses[j].X - chickens[i].X) + abs(houses[j].Y - chickens[i].Y));
            }
            sum += mn;
        }
        ans = min(ans, sum);
    }while(next_permutation(combi.begin(), combi.end()));
    cout << ans;
}