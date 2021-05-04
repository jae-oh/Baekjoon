#include <bits/stdc++.h>
using namespace std;

int n,maxi;
pair<int,int> sch[20];
int dp[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> sch[i].first >> sch[i].second;
    
    for(int i=1;i<=n;i++){
        for(int j=i+sch[i].first;j<=n+1;j++){
            if(dp[j] < dp[i] + sch[i].second)
                dp[j] = dp[i] + sch[i].second;
        }
    }

    sort(dp,dp+n+2);
    cout << dp[n+1];
}