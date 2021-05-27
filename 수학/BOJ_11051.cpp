#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
-nCk(조합) = n! / (n-k)!k!를 쓰고 싶지만, 최대 1000!을 int나 long long에 담을 수 없다.
-우리는 n!, (n-k)!, k!을 10007로 나눈 나머지는 알 수 있으나 합동식 안에서 나눗셈은 성립되지 않는다.
-그러므로 nCk(조합) = n-1Ck + n-1Ck-1;을 이용하여야 한다.
*/

int a,b;
int combi[1005][1005]; //nCk 조합 : combi[n][k]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b;
    for(int i=1;i<=1000;i++)
        combi[i][0] = combi[i][i] = 1; //nC0(조합) 은 1이다.

    for(int i=2;i<=1000;i++){
        for(int j=1;j<=i;j++){
            combi[i][j] = (combi[i-1][j] + combi[i-1][j-1])%10007;
        }
    }

    cout << combi[a][b];
}