#include <bits/stdc++.h>
using namespace std;

//수의 범위가 1000만 이하일 때는 카운팅 소트가 적당하다.
//그러나 unstable sort이다.

int n;
int arr[10005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        arr[num]++;
    }

    for(int i=1;i<=10000;i++){
        if(!arr[i])
            continue;
        else{
            for(int j=0;j<arr[i];j++)
                cout << i << '\n';
        }
    }
}