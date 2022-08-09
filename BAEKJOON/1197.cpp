#include <bits/stdc++.h>
using namespace std;

int v, e;
tuple<int, int, int> edge[100005];
int p[100005];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);
    if(u == v) return false;
    p[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    
    for(int i=1; i<=v; i++) p[i] = i;

    sort(edge, edge+e);

    int cnt = 0, sum =0;
    for(int i=0; i<e; i++){
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        cnt++;
        sum += cost;
        if(cnt == v-1) break;
    }

    cout << sum;
}