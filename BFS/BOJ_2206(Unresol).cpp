#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[1005][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            char ch;
            cin >> ch;
            if(ch == '0')
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }

    
}