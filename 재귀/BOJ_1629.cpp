#include <bits/stdc++.h>

using namespace std;

long long func1(long long a,long long b,long long c);

//큰수들의 곱에서 일의 자리수를 구하기 위해서는 일의 자리수들을 곱해서 얻는다.
//EX)23123 * 53451 * 1524126의 일의자리수를 구하면 3,1,6의 곱으로 일의자리수를 구한다.
//즉, 큰 수들의 곱에서 m으로 나눈 나머지를 구하려면 각 수들을 m으로 나눈 나머지를 곱하고, 그 수의 m의 나머지를 구하면 더욱 빠르다.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,b,c;

    cin >> a >> b >> c;
    cout << func1(a,b,c);
}

//귀납적 사고
//1. 1승을 계산할 수 있다.
//2. K승을 계산했으면 2K승과 2K+1승도 O(1)에 계산할 수 있다.
long long func1(long long a,long long b, long long c){
    if(b==1) return a%c;
    long long val = func1(a,b/2,c);//K승
    val = val*val%c;//2K승
    if(b%2==0) return val; //b가 짝수일 때
    else return val*a%c; //b가 홀수일 때는 2로 나누면 제대로 안나누어지기 때문에 a를 한번더 곱해준다.
}