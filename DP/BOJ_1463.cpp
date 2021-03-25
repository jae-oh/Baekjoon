#include <bits/stdc++.h>
using namespace std;

int n;
int d[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    d[1] = 0;
    cin >> n;
    for(int i=2;i<=n;i++){
        if(i%3 == 0 && i%2 == 0) d[i] = min({d[i/3]+1,d[i/2]+1,d[i-1]+1});
        else if(i%3 == 0) d[i] = min(d[i/3]+1, d[i-1]+1);
        else if(i%2 == 0) d[i] = min(d[i/2]+1, d[i-1]+1);
        else d[i] = d[i-1]+1;
    }
    cout << d[n];
}