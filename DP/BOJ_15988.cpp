#include <bits/stdc++.h>
using namespace std;

/*
#어떤 값을 1,2,3의 합으로 표현하는 가지수이기 때문에, 처음은 1,2,3으로 시작할 수 밖에 없다.
- 1로 시작하는 경우 : dp[i-1] (왜냐하면 dp[i-1]이 i-1을 표현하는 모든 경우의 수이기 때문이다.)
- 2로 시작하는 경우 : dp[i-2]
- 3으로 시작하는 경우 : dp[i-3]
= dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

#초기값 : dp[1], dp[2], dp[3]
*/

int n;
long long dp[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp[1] =1;
    dp[2] =2;
    dp[3] =4;
    for(int i=4;i<=1000000;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        if(dp[i] >= 1000000009)
            dp[i] %= 1000000009;
    }

    while(n--){
        int testN;
        cin >> testN;
        cout << dp[testN] << '\n';
    }
}