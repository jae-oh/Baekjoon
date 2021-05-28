#include <bits/stdc++.h>
using namespace std;

int n,m,g_divisor=0,l_multiple=0;

int gcd(int a,int b); //유클리드 호제법을 사용한 최대공약수 구하는 함수
int lcm(int a,int b,int gcd); //최소공배수는 (A * B / GCD) 로 구할 수 있다.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    g_divisor = gcd(n,m);
    cout << g_divisor;
    
    l_multiple = lcm(n,m,g_divisor);
    cout << '\n' << l_multiple;
}

int gcd(int a,int b){ //대소비교를 안해도 되는 이유 : 큰 값이 뒤로가서 유클리드 호제법을 사용하면 큰값과 작은 값 순서가 바뀐다.
    if(b == 0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b,int gcd){
    return a*b/gcd;
}