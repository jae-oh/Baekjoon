#include <bits/stdc++.h>
using namespace std;

/*
증명 : https://blog.encrypted.gg/757?category=773649 참조
*/
int n;
vector<int> p;

vector<int> prime_factorization1(int k);
vector<int> prime_factorization2(int k); //최적화해서 시간복잡도 O(N^1/2)로 만든 것

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    p = prime_factorization2(n);

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

vector<int> prime_factorization2(int k){
    vector<int> tmp;

    for(int i=2;i*i<=k;i++){
        while(k%i==0){
            tmp.push_back(i);
            k /= i;
        }
    }

    if(k != 1) tmp.push_back(k);

    return tmp;
}