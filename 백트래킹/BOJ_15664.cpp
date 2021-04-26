#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10],input[10],isused[10];

void func(int k, int isprev);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> input[i];
    sort(input,input+n);
    func(0,0);
}

void func(int k, int isprev){
    if(k==m){
        for(int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int isbefore =-1;
    for(int i=0;i<n;i++){
        if(!isused[i] && isbefore != input[i] && i >= isprev){
            isused[i] = 1;
            arr[k] = input[i];
            isbefore = input[i];
            func(k+1,i);
            isused[i] = 0;
        }
    }
}