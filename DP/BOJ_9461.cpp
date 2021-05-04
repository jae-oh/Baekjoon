#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for(int i=6;i<101;i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
    while(n--){
        int testN;
        cin >> testN;
        cout << dp[testN] << '\n';
    }
}