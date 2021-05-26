#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p;

vector<int> prime_factorization(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    p = prime_factorization(n);

    for(auto i : p){
        cout << i << '\n';
    }
}

vector<int> prime_factorization(int k){
    vector<int> tmp;

    for(int i=2;k!=1;i++){
        while(k%i==0){
            tmp.push_back(i);
            k /= i;
        }
    }
    return tmp;
}