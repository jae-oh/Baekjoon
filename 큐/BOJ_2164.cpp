#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++)
        q.push(i);
    while(q.size()!=1){
        int temp;
        q.pop();
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front();
}