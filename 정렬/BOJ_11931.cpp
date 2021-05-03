#include <bits/stdc++.h>
using namespace std;

//**cmp함수 짜는 법
/*
bool 함수이름 (const 변수형& a, const 변수형& b){
    if(a가 b보다 앞에 올 조건) return true;
    return false;
}
*/

int n,arr[1000005];

bool cmp(const int a,const int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n,cmp);

    for(int i=0;i<n;i++)
        cout << arr[i] << '\n';
}

bool cmp(const int a,const int b){
    if(a > b) return true;
    return false;
}