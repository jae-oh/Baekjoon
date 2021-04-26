#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10],input[10];

void func(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    sort(input,input+n);
    func(0);
}

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for(int i=0;i<n;i++){
        arr[k] = input[i];
        func(k+1);
    }
}