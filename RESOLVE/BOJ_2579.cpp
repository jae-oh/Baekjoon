#include <bits/stdc++.h>
using namespace std;

/*
#DP문제풀이법
1.테이블 정의
2.점화식 찾기
3.초기값 설정
*/

int n,ans;
int stair[305],dp[305][2]; //dp[k][0]은 연속해서 1번째 밟았을때, dp[k][1]은 연속해서 2번째 밟았을때

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> stair[i];
    
    dp[1][0] = stair[1];
    dp[1][1] = 0;
    ans = stair[1];

    for(int i=2;i<=n;i++){
        int maxi=0;
        for(int j=1;j<=i-2;j++){ //dp[i][0]는 연속해서 1번째 밟았을 때이기에, 바로 전칸은 밟을 수 없다. 그렇기에 1번째칸에서 i-2칸까지 중에 가장 큰값을 구해준다.
            if(maxi < max(dp[j][0],dp[j][1]));
                maxi = max(dp[j][0],dp[j][1]);
        }
        dp[i][0] = maxi + stair[i];
        dp[i][1] = dp[i-1][0] + stair[i]; //dp[i][1]은 연속해서 2번째 밟았을 때이기에, 무조건 전칸을 밟아야한다.

        if(i == n-1) //마지막 계단은 무조건 밟아야 한다는 조건이 있기에 dp[n-1][1]은 무조건 밟으면 안된다.
            dp[i][1] = 0;

        if(ans < max(dp[i][0],dp[i][1]))
            ans = max(dp[i][0],dp[i][1]);
    }
    
    cout << ans;
}