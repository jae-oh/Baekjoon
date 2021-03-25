#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++)
       dp[i] = (dp[i-1] + dp[i-2])%10007; //마지막에 %10007을 하면 이 곳에서 int overflow가 발생한다.

    cout << dp[n];

    //가장 왼쪽 위 1x1 타일을 보면 그 타일을 덮을 수 있는 가지 수는 2가지이다.
    //만약 2x1타일로 덮는다면 남는 면을 덮을 수 있는 가지수는 d[i-1]이고,
    //1x2타일로 덮는다면 밑에 타일은 항상 1x2타일로 덮어져야하기 때문에 남는 면을 덮는 가지 수는 d[i-2]이 된다.
    //그렇기 때문에 d[i] = d[i-1]+d[i-2];
    //BOJ_11726.png 참조
}