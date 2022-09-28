#include <bits/stdc++.h>
using namespace std;

#define min3(a, b, c) (min(a, min(b, c)))
#define max3(a, b, c) (max(a, max(b, c)))

int n;
int a[100005][3];
int maximum[3];
int minimum[3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }

    int maximum1, maximum2, maximum3, minimum1, minimum2, minimum3;
    for(int j=0; j<3; j++){
        maximum[j] = a[0][j];
        minimum[j] = a[0][j];
    }

    for(int i=1; i<n; i++){
        maximum1 = max(maximum[0], maximum[1]) + a[i][0];
        minimum1 = min(minimum[0], minimum[1]) + a[i][0];

        maximum2 = max3(maximum[0], maximum[1], maximum[2]) + a[i][1];
        minimum2 = min3(minimum[0], minimum[1], minimum[2]) + a[i][1];

        maximum3 = max(maximum[1], maximum[2]) + a[i][2];
        minimum3 = min(minimum[1], minimum[2]) + a[i][2];


        maximum[0] = maximum1; maximum[1] = maximum2; maximum[2] = maximum3;
        minimum[0] = minimum1; minimum[1] = minimum2; minimum[2] = minimum3;

    }

    cout << max3(maximum[0], maximum[1], maximum[2]) << ' ' << min3(minimum[0], minimum[1], minimum[2]) << '\n';
}