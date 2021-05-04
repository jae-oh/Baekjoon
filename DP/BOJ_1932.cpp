#include <bits/stdc++.h>
using namespace std;

int n;
int board[600][600],dp[600];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> board[i][j];
        }
    }

    dp[0] = board[0][0];

    for(int i=1;i<n;i++){
        int maxi = board[i][0];
        for(int j=0;j<=i;j++){
            if(j==0)
                board[i][j] = board[i][j] + board[i-1][j];
            else if(j==i)
                board[i][j] = board[i][j] + board[i-1][j-1];
            else{
                board[i][j] = max(board[i][j]+board[i-1][j] , board[i][j] + board[i-1][j-1]);
            }

            if(board[i][j] > maxi)
                maxi = board[i][j];
        }
        dp[i] = maxi;
    }

    cout << dp[n-1];
}