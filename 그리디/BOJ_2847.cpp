#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어 : 점수조정하는 법이 1씩 감소시키는 방법밖에 없다.
-> 그러므로 마지막단계의 점수 값은 항상 고정이다.
-> 점수 내리는 것을 최소화할려면 i단계의 점수와 i+1단계의 점수 차이가 1이 나는 것이 좋다.
-> 왜냐하면 i단계는 점수를 최대한 높여서 i-1단계에서 점수를 덜 깍을 수 있도록 해야하기 때문이다. 
*/

int n,cnt=0;
int arr[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    for(int i=n;i>0;i--){
        if(i==1)
            break;
        if(arr[i-1] >= arr[i]){
            cnt += arr[i-1] - arr[i] +1;
            arr[i-1] = arr[i] -1;
        }
    }
    cout << cnt;
}