#include <bits/stdc++.h>
using namespace std;

int n;
string str[20005];

bool cmp(string& a, string& b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> str[i];
    sort(str,str+n,cmp);
    for(int i=0;i<n;i++){
        if(str[i] == str[i+1])
            continue;
        cout << str[i] << '\n';
    }
}

bool cmp(string& a, string& b){
    if(a.size() < b.size()) return true;
    else if(a.size() == b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i] < b[i])
                return true;
            else if (a[i] == b[i])
                continue;
            else return false;
        }
        return false;
    }
    else return false;
}