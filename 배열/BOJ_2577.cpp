#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int arr[10];
long long ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c;
    ans = a*b*c;
    while(1){
        if(!ans) break;
        arr[ans%10]++;
        ans /= 10;
    }
    for(int i=0;i<10;i++)
        cout << arr[i] << '\n';

}