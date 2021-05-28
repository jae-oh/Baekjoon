#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어 : 투포인터 알고리즘
*/
int n,m,st=0,en=0,cnt=0,sum=0;
int arr[10005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    while(1){
        if(sum >= m) sum -= arr[st++];
        else if(en == n) break;
        else sum += arr[en++];
        
        if(sum == m) cnt++;
    }
    cout << cnt;
}