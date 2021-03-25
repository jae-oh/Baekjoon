#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100005];
int dp[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        dp[i] = dp[i-1] + arr[i];
    }
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << '\n';
    }

    /* 
        d[i] = d[1]+d[2] ... +d[i-1]
        즉, d[i] = d[i-1] + arr[i]
        그렇다면 a[i] ~ a[j] 까지의 합을 식으로 표현해보면
        a[i]+a[i+1] ... + a[j] = (a[1]+a[2]+...+a[j]) - (a[1]+a[2]+...+a[i-1])
        =d[j] - d[i-1]; 이라는 식이 도출된다.
    */
}