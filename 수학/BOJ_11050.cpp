#include <bits/stdc++.h>
using namespace std;

/*
이항계수는 nCk (조합)으로 표현할 수 있다.
*/
int n,m;

int fatorial(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    cout << fatorial(n)/(fatorial(m)*fatorial(n-m));
}

int fatorial(int k){
    int tmp=1;

    for(int i=1;i<=k;i++)
        tmp *= i;
    
    return tmp;
}