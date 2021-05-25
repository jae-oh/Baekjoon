#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
1. 10xn배열로 DP로 풀면 쉽게 정답이 나온다.
2. DP는 DP답게!!!
*/

int n,arr[10][105],ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<10;i++){
        arr[i][1] = 1;
    }

    for(int j=2;j<101;j++){
        for(int i=0;i<10;i++){
            if(i==0){
                arr[0][j] = arr[1][j-1]%1000000000;  
            }else if(i==9){
                arr[9][j] = arr[8][j-1]%1000000000;
            }else{
                arr[i][j] = (arr[i-1][j-1] + arr[i+1][j-1])%1000000000;
            }
        }
    }

    for(int i=0;i<10;i++){
        ans = (ans+arr[i][n])%1000000000; // ans와 arr[i][n]을 더한 후 10억이 넘을 수 있으니 이렇게 나머지를 구해야한다.
    }

    cout << ans;
}