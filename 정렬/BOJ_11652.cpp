#include <bits/stdc++.h>
using namespace std;

//POINT : 정렬을 하면 같은 수는 인접해진다는 성질

int n,maxi; //maxi : 가장 많이 가지고 있는 정수의 횟수
long long arr[100005]; //숫자가 들어있는 배열
int freq[100005];//정렬된 배열에서 횟수를 나타내는 배열

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);//오름차순으로 정렬
    for(int i=1;i<n;i++){
        if(arr[i] == arr[i-1])//오름차순으로 정렬되어있기때문에 index-1하고 현재 index의 값하고 같다면 똑같은 수가 나왔다는 뜻이다.
            freq[i] = freq[i-1] + 1; 
    }
    for(int i=0;i<n;i++){
        if(freq[i] > maxi) //가장 많이 나온 횟수 구하기
            maxi = freq[i];
    }
    for(int i=0;i<n;i++){
        if(freq[i] == maxi){ //가장 많이 나온 횟수(maxi)에 대응하는 숫자 출력 (arr를 오름차순으로 정렬했기때문에 처음으로 maxi와 같은 횟수를 가진 값이 그 중에서 가장 작은 수)
            cout << arr[i];
            break;
        }
    }
}