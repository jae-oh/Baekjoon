#include <bits/stdc++.h>
using namespace std;

/*
#규칙을 찾는 것도 중요하지만 dp는 dp답게 풀자!
https://sihyungyou.github.io/baekjoon-10844/ 참조
*/

int n,ans;
long long dp[105][11]; // col에는 N자리일 때, 마지막이 col인 것의 수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i=1;i<10;i++)
        dp[1][i] = 1;
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j==0)
                dp[i][j] = dp[i-1][j+1]%1000000000; //i자리일 때, 일의 자리가 0인 것은 i-1자리일 때, 일의 자리가 1인 것에만 영향을 받는다
            else if(j ==9)
                dp[i][j] = dp[i-1][j-1]%1000000000; //i자리일 때, 일의 자리가 9인 것은 i-1자리일 때, 일의 자리가 8인 것에만 영향을 받는다
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;////i자리일 때, 일의 자리가 1~8인 것은 i-1자리일 때, 일의 자리가 0~9인 것에 영향을 받는다.
        }
    }

    for(int i=0;i<10;i++) ans = (ans + dp[n][i])%1000000000;

    cout << ans;
}