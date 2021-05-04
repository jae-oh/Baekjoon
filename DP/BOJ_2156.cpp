#include <bits/stdc++.h>
using namespace std;

int n,maxi;
int board[10005];
int dp[10005][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> board[i];
    }

    dp[0][0] = board[0];
    dp[0][1] = 0;
    dp[1][0] = board[1];
    dp[1][1] = dp[0][0] + board[1];

    maxi = max(dp[0][0],dp[1][1]);

    for(int i=2;i<n;i++){
        int maxi_0=0;
        for(int j=0;j<i-1;j++)
            if(maxi_0 < max(dp[j][1], dp[j][0]))
                maxi_0 = max(dp[j][1],dp[j][0]);
        dp[i][0] = maxi_0 + board[i];
        dp[i][1] = dp[i-1][0] + board[i];

        if(max(dp[i][0],dp[i][1]) > maxi)
            maxi = max(dp[i][0],dp[i][1]);
    }

    cout << maxi;
}