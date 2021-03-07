/*
1.함수의 정의
int func(int n, int r, int c)
2^n X 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수

2.base condition
n=0일 때, return 0;

3.재귀 식
(r,c)가 1번 사각형일 때 return func(n-1,r,c);
(r,c)가 2번 사각형일 때 return func(n-1,r,c-half);
(r,c)가 3번 사각형일 때 return func(n-1,r-half,c);
(r,c)가 4번 사각형일 때 return func(n-1,r-half,c-half);
-->여기서 half는 한변 길이의 절반, 즉 2^(n-1). 
*/

#include <bits/stdc++.h>

using namespace std;

int func(int n,int r,int c);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,r,c;

    cin >> n >> r >> c;
    cout << func(n,r,c);
}

int func(int n, int r, int c){
    if(n==0) return 0;
    int half = 1<<(n-1); //2^n-1
    if(r < half && c < half) return func(n-1,r,c);
    if(r < half && c >= half ) return half*half + func(n-1,r,c-half);
    if(r >= half && c<half) return 2*half*half + func(n-1,r-half,c);
    return 3*half*half + func(n-1,r-half,c-half); //if(r >= half && c >= half)
}
