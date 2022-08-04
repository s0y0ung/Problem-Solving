#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> string_to_int;
string int_to_string[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    string name;
    for(int i=1; i<=n; i++){
        cin >> name;
        int_to_string[i] = name;
        string_to_int[name] = i;
    }

    string question;
    while(m--){
        cin >> question;
        if(isdigit(question[0])){ // number
            cout << int_to_string[stoi(question)] << "\n";
        }
        else{
            auto num = string_to_int.find(question);
            if(num != string_to_int.end())
                cout << num->second << "\n";
        }
    }
}