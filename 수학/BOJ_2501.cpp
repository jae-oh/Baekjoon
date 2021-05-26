#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> divisor;

vector<int> alldivisor(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    divisor = alldivisor(n);

    if(divisor.size() < m) cout << 0;
    else cout << divisor[m-1];
}

vector<int> alldivisor(int k){
    vector<int> tmp;

    for(int i=1;i<=k;i++){
        if(k%i==0) tmp.push_back(i);
    }

    return tmp;
}
