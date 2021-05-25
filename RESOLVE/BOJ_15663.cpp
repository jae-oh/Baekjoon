#include <bits/stdc++.h>
using namespace std;

//수열을 사전순으로 출력하기 때문에, 길이가 같은 바로 직전 수열의 마지막 항만 다른지 확인하면 중복수열을 제거할 수 있다.
//백트래킹에서 문제가 안풀리면 트리구조로 그려서 규칙을 찾기

int n,m;
int arr[10],isused[10],input[10];

void func(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> input[i];
    
    sort(input,input+n);
    func(0);
}

void func(int k){
    if(k == m){
        for(int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    int xx = 0;
    for(int i=0;i<n;i++){
        if(!isused[i] && input[i] != xx){
            isused[i] = 1;
            arr[k] = input[i];
            xx = input[i];
            func(k+1);
            isused[i] = 0;
        }
    }
}