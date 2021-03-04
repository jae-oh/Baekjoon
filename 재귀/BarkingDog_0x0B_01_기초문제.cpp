#include <bits/stdc++.h>

using namespace std;

void func1(int n);
int func2(int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    func1(10);
    cout << '\n' << func2(10);
}

void func1(int n){ //n부터 1까지 출력하는 재귀function
    if(n==0) return;
    cout << n << ' ';
    func1(n-1);
}

int func2(int n){ //1부터 n까지 합을 구하는 재귀function
    if(n==0) return 0;
    return func2(n-1) + n;
} 