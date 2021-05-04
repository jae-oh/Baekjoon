#include <bits/stdc++.h>
using namespace std;

int n,maxi;
int board[100005];
long long dp[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >>n;
    for(int i=0;i<n;i++)
        cin >> board[i];
    
    dp[0] = board[0];
    maxi = board[0];

    for(int i=1;i<n;i++){
        if(dp[i-1] >= 0)
            dp[i] = dp[i-1] + board[i];
        else
            dp[i] = board[i];
        
        if(dp[i] > maxi)
            maxi = dp[i];
    }

    cout << maxi;
}