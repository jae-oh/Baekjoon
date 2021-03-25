#include <bits/stdc++.h>
using namespace std;

int n;
int stair[305];
int d[305][2]; //d[k][0]은 현재 계단을 연속으로 1번 밟아서 올라왔다는 뜻 , d[k][1]은 현재 계단을 연속해서 2번 밟았다는 뜻

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> stair[i];

    d[1][0] = stair[1];

    for(int i=2;i<=n;i++){
        d[i][0] = max(d[i-2][0]+stair[i],d[i-2][1]+stair[i]);//d[i][0]은 연속해서 한번 밟았기 때문에 즉, 2칸 전에서 바로 올라온 것을 뜻함.
        d[i][1] = d[i-1][0]+stair[i];//d[i][1]은 현재 계단을 연속해서 2번으로 밟아서 올라왔다는 뜻이기 때문에, d[i-1][1]을 사용하지 못함 (d[i-1][1]은 그전에 연속해서 2번밟았기 때문에 이번꺼까지 밟으면 3번)
    }

    cout << max(d[n][0],d[n][1]);
}
