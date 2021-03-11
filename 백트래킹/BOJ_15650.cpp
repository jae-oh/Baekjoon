#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int cur);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    func(0);
}

void func(int cur){
    if(cur == m){
        for(int i=1;i<=m;i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i=arr[cur];i<=n;i++){
        if(!isused[i] && i){
            arr[cur+1] = i; //arr[cur+1]이 다음엔 arr[cur]가 될 것이기 때문에, arr[cur+1]에 i를 넣어준다. (오름차순)
            isused[i] = true;
            func(cur+1);
            isused[i] = false;
        }
    }
}