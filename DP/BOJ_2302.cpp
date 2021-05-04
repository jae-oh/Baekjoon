#include <bits/stdc++.h>
using namespace std;

/*
#n좌석이 모두 꽉차있을 때, 옆좌석과 바꿔서 앉을 수 있는 경우의 수를 dp[n]으로 정의한다.
-첫번째 좌석에는 1,2가 올 수 있다.
-1이 왔을 경우, dp[i-1] : 왜냐하면 첫번째 좌석은 1로 고정이기 때문
-2가 왔을 경우, dp[i-2] : 왜냐하면 첫번째,두번째 좌석은 2,1로 고정이기 때문

#그 다음 고정석으로 나누어진 구역의 좌석 수들을 구하고, 그 때의 dp[좌석수]를 모두 곱해주면 고정석으로 나누어져 있을 때, 앉을 수 있는 경우의 수가 나온다.
-경우의 수들을 곱하면 전체 경우의 수가 나오기 때문
*/
int n,cons_n,mid_n,ans=1;
int dp[45];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> cons_n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    while(cons_n--){
        int cons_num;
        cin >> cons_num;
        ans *= dp[cons_num-mid_n-1];
        mid_n = cons_num;
    }
    ans *= dp[n-mid_n]; //한번 더 해주는 이유는 위의 while문에서는 마지막부터 마지막 고정석까지의 구역을 계산하지 않았기 때문이다.

    cout << ans;
}