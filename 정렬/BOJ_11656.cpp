#include <bits/stdc++.h>
using namespace std;

string word;
string str[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> word;
    for(int i=0;i<word.size();i++){
        for(int j=0;j<=i;j++){
            str[j].push_back(word[i]);
        }
    }
    sort(str,str+word.size());
    for(int i=0;i<word.size();i++)
        cout << str[i] << '\n';
}