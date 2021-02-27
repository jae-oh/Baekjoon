#include <bits/stdc++.h>

using namespace std;

int freq[1000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x; //n: 수열의 크기 , x : 두 수의 합이 되야하는 수
    int arr[100001];
    int cont = 0 ;//쌍의 수

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    cin >> x;

    for(int i = 0 ; i<n;i++){
        if(arr[i]>x) //두 수의 합이 되야하는 수가 수열의 수보다 작으면 OutOfBounds에러가 발생
            continue;
        if(freq[x-arr[i]])//두 수의 합이 되야하는 수가 수열의 수보다 작으면 OutOfBounds에러가 발생
            cont++;
    }

    cout << cont/2; //2를 나누는 이유는 만약 x가 13이면 5를 계산할 때 한번, 8을 계산할 때 한번, 이렇게 한쌍인데도 cont는 2가 증가하기 때문이다.
}