#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];

void func(int k,int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    func(0,1);
}

void func(int k,int a){
    if(k==m){
        for(int i=0;i<m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for(int i=a;i<=n;i++){
        arr[k] = i;
        func(k+1,i);
    }

}