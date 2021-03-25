#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000005];
int prevIdx[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp[1] = 0;
    prevIdx[1] = 0;
    for(int i=2;i<=n;i++){
        if(i%3==0 && i%2 ==0){
            dp[i] = min({dp[i/3],dp[i/2],dp[i-1]})+1;
            if(min({dp[i/3],dp[i/2],dp[i-1]}) == dp[i/3]){
                prevIdx[i] = i/3;
            }else if(min({dp[i/3],dp[i/2],dp[i-1]}) == dp[i/2]){
                prevIdx[i] = i/2;
            }else{
                prevIdx[i] = i-1;
            }
        }
        else if(i%3==0){
            dp[i] = min(dp[i/3],dp[i-1])+1;
            if(dp[i/3] > dp[i-1])
                prevIdx[i] = i-1;
            else
                prevIdx[i] = i/3;
        }
        else if(i%2==0){
            dp[i] = min(dp[i/2],dp[i-1])+1;
            if(dp[i/2] > dp[i-1])
                prevIdx[i] = i-1;
            else
                prevIdx[i] = i/2;
        }
        else{
            dp[i] = dp[i-1]+1;
            prevIdx[i] = i-1;
        }
    }

    cout << dp[n] << '\n';
    cout << n << ' ';
    for(int i=n;i != 1;i=prevIdx[i])
        cout << prevIdx[i] << ' ';
}

/*바킹독 풀이
-for문안에 조건이 간결함

// http://boj.kr/da0497aabb26436c9ae613785cb439f7
#include <bits/stdc++.h>
using namespace std;

int d[1000005];
int pre[1000005];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  d[1] = 0;
  for(int i = 2; i <= n; i++){
    d[i] = d[i-1] + 1;
    pre[i] = i-1;
    if(i%2 == 0 && d[i] > d[i/2] + 1){
      d[i] = d[i/2] + 1;
      pre[i] = i/2;
    }
    if(i%3 == 0 && d[i] > d[i/3] + 1){
      d[i] = d[i/3] + 1;
      pre[i] = i/3;
    }
  }
  cout << d[n] << '\n';
  int cur = n;
  while(true){
    cout << cur << ' ';
    if(cur == 1) break;
    cur = pre[cur];    
  }
}

*/