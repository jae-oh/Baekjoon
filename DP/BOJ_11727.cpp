#include <bits/stdc++.h>
using namespace std;

/*
#3가지 경우로 나눠서 생각한다.
1. 처음에 1x2 타일로 채웠을 때 : dp[i-2] (왜냐하면 1x2타일로 채웠으면 밑에는 무조건 1x2타일이 채워져야 하기 때문)
2. 처음에 2x1 타일로 채웠을 때 : dp[i-1]
3. 처음에 2x2 타일로 채웠을 때 : dp[i-2]
= dp[i-2] + dp[i-1] + dp[i-2] = 2*d[i-2] + dp[i-1]
*/

int n;
long long dp[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    
    for(int i=3;i<=n;i++){
        dp[i] = 2*dp[i-2] + dp[i-1];
        dp[i] %= 10007;
    }

    cout << dp[n]%10007;
}