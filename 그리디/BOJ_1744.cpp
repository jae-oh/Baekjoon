#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
1. 양의 정수는 큰거부터 2개씩 곱해서 더한다.
2. 음의 정수는 작은거부터 2개씩 곱해서 더한다.
3. 만약 양의 정수가 1이라면 곱하지 않고 더한다.
4. 만약 음의 정수가 하나 남고, arr에 0이 있다면 하나 남은 음의 정수에 0을 곱한다.
5. 만약 양의 정수가 하나 남았다면, 그 양의 정수는 그냥 더한다.

#다른 사람 아이디어
- 이럴 때는 배열이나 벡터를 양의 정수,음의 정수(0포함) 따로 만들어서 문제를 접근하는게 좋을 듯함.
https://www.acmicpc.net/source/28972665 참조
*/

int n,cnt_zero=0,ans=0,idx1,idx2;
int arr[10005];

bool cmp(int a,int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n,cmp); //내림차순

    for(int i=0;i<n;i++){
        if(arr[i+1] > 1){
            ans += arr[i] * arr[i+1];
            i++;
        }else if(arr[i] == 1){
            ans += 1;
        }else if(arr[i]>1 && arr[i+1] ==1){
            ans += arr[i] + 1;
            i++;
        }else if(arr[i] > 1 && arr[i+1] <= 0){
            ans += arr[i];
            break;
        }else break;
    }
    sort(arr,arr+n); //오름차순

    for(int i=0;i<n;i++){
        if(arr[i+1] <= 0 && i+1 <n){
            ans += arr[i] * arr[i+1];
            i++;
        }else if(arr[i] < 0){
            ans += arr[i];
            break;
        }else break;
    }

    cout << ans;
}

bool cmp(int a,int b){
    if(a > b) return true;
    else return false;
}
