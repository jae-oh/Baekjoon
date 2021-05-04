#include <bits/stdc++.h>
using namespace std;

int n,maxi;
int board[1005];
int dp[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> board[i];
    
    dp[0] = 1;
    maxi = dp[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(board[i] > board[j] && dp[i] <= dp[j])
                dp[i] = dp[j]+1;
        }
        if(!dp[i]) dp[i] = 1; //위에 조건에서 앞에 수열이 모두 만족하지 않을 수 있으므로 이 문장을 넣어줘야 한다.
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    cout << maxi;
}