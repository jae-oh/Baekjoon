#include <bits/stdc++.h>

using namespace std;

int n,cnt = 0;
bool isused1[1000]; //열
bool isused2[1000]; //좌측하단에서 우측상단 대각선(/)
bool isused3[1000]; //좌측상단에서 우측하단 대각선(\)

void func(int cur);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    func(0);
    cout << cnt;
}

void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!isused1[i] && !isused2[cur+i] && !isused3[cur-i+n-1]){
            isused1[i] = true;
            isused2[cur+i] = true;
            isused3[cur-i+n-1] = true;
            func(cur+1);
            isused1[i] = false;
            isused2[cur+i] = false;
            isused3[cur-i+n-1] = false;
        }
    }
}