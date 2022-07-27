#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> dictionary;

bool cmp(string &a, string &b){
    if (a.length() != b.length()) return a.length() < b.length();
    
    int sum1=0, sum2=0;
    for(int i=0; i<a.length(); i++){
        if(isdigit(a[i])) sum1+=(a[i]-'0');
        if(isdigit(b[i])) sum2+=(b[i]-'0');
    }
    if(sum1!=sum2) return sum1 < sum2;

    return a.compare(b) < 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        dictionary.push_back(str);
    }

    sort(dictionary.begin(), dictionary.end(), cmp);

    for(int i=0; i<n; i++) cout << dictionary[i] << "\n";
}