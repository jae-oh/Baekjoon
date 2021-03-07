#include <bits/stdc++.h>

using namespace std;

/*하노이탑
- n-1개의 원판은 기둥 1에서 기둥 2로 옮긴다
- n번 원판을 기둥 1에서 기둥 3으로 옮긴다.
- n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다.
--> 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 때에도 옮길 수 있다.

1.원판이 1개일 때 원판을 내가 원하는 곳으로 옮길 수 있다.
2.원판이 k개일 때 옮길 수 있으면 원판이 k+1개일 때에도 옮길 수 있다.
--> 귀납적 사고 가능. 즉, 재귀 사용 가능
*/

/*
1.함수의 정의
(x)void func(int n) : 원판 n개를 기둥 1에서 기둥 3으로 옮기는 방법을 출력하는 함수
--> 사용불가능, 그 이유는 원판 n-1개는 기둥 2로 옮겨야 하기 때문에
(o)void func(int a, int b, int n) : 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수

2.base condition
n=1일 때 cout << a << ' ' << b << '\n' : n=1일 때, a에서 b로 옮긴다.

3.재귀 식
n-1개의 원판은 기둥 a에서 기둥 6-a-b로 옮긴다. (기둥 1+2+3 = 6이기 때문에)
--> func(a,6-a-b,n-1);
n번 원판을 기둥 a에서 기둥 b로 옮긴다.
--> cout << a << ' ' << b << '\n'
n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
--> func(6-a-b, b, n-1);
*/
int ct;

void func1(int a, int b, int n);
void func2(int a, int b, int n);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    func1(1,3,n);
    cout << ct << '\n';
    func2(1,3,n);
}

void func1(int a, int b, int n){
    if(n==1){
        ct++;
        return;
    }
    func1(a,6-a-b,n-1);
    ct++;
    func1(6-a-b, b, n-1);
}

void func2(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    func2(a,6-a-b,n-1);
    cout << a << ' ' << b << '\n';
    func2(6-a-b, b, n-1);
}