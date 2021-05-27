#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
-뒤에 0이 나온다는 말은 N!를 인수분해하면 10^k가 나오고 k를 구하란 말이다.
-즉, 10^k = 2^k * 5^k 이기 때문에, 1~N까지 숫자를 모두 소인수분해하여 2의 개수, 5의 개수 중 작은 개수를 구하면 정답이다. (왜냐하면 2^2 * 5^1 이면 10은 2^1 * 5^1이기 때문에)
*/

int n,ans,tmp=1;
int a=0,b=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=1;i<=n;i++){
        int tmp = i;
        while(tmp%2==0){
            a++;
            tmp /= 2;
        }
        while(tmp%5==0){
            b++;
            tmp /= 5;
        }
    }

    cout << min(a,b);
}