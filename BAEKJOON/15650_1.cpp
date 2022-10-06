#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        arr[i] = i+1;
    
    // 결국 n개 중에서 m개를 오름차순으로 조합 뽑는 것과 같음 => m개의 0 준비
    vector<int> check;
    for(int i=0; i<m; i++)
        check.push_back(0);
    for(int i = m; i<n; i++)
        check.push_back(1);

    do{
        for(int i=0; i<n; i++){
            if(check[i] == 0)
                cout << arr[i] << " ";
        }
        cout << "\n";
    }while(next_permutation(check.begin(), check.end()));
}