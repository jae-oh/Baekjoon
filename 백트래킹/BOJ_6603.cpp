#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15],isused[15],input[15];

void func(int k , int isprev);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        cin >> n;
        if(!n)
            break;
        fill(input,input+15,0);
        fill(isused,isused+15,0);
        for(int i=0;i<n;i++)
            cin >> input[i];
        sort(input,input+n);

        func(0,0);
        cout <<'\n';
    }
}

void func(int k, int isprev){
    if(k==6){
        for(int i=0;i<6;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for(int i=isprev;i<n;i++){
        if(!isused[i]){
            isused[i] = 1;
            arr[k] = input[i];
            func(k+1,i+1);
            isused[i] = 0;
        }
    }
}