#include <bits/stdc++.h>
using namespace std;

/*
#이친수의 개수는 피보나치 수열로 계산할 수 있다.
- 이유 : dp[i]는 dp[i-1]의 원소 개수 + 0의 개수인데(맨 뒤가 1인 원소는 그 뒤에 0만 붙일 수 있고, 맨 뒤가 0인 원소는 그 뒤에 1,0을 붙일 수 있기 때문), dp[i-1]의 0의 개수는 dp[i-2]의 원소개수와 똑같기 때문이다.
        (dp[i-2]의 모든 원소 뒤에 0을 붙일 수 있기 때문이다.)
*/

int n;
long long dp[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    cout << dp[n];
}