#include <bits/stdc++.h>
using namespace std;

int n,ans;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(!a) s.pop();
        else s.push(a);
    }
    int siz = s.size();
    for(int i=0;i<siz;i++){
        ans += s.top();
        s.pop();
    }
    //while(!s.empty());로 프린트하면 더 깔끔
    cout << ans;
}