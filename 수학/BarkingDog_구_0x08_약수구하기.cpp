#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> divisor;

vector<int> alldivisor(int k);
vector<int> alldivisor2(int k); //최적화하여 시간복잡도를 O(N^1/2)로 만듬

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    divisor = alldivisor(n);

    for(auto i : divisor)
        cout << i << ' ';
    
}

vector<int> alldivisor(int k){
    vector<int> tmp;

    for(int i=1;i<=k;i++){
        if(k%i==0) tmp.push_back(i);
    }

    return tmp;
}

vector<int> alldivisor2(int k){
    vector<int> tmp;

    for(int i=1;i*i<=k;i++)
        if(k%i == 0) tmp.push_back(i);

    for(int i=tmp.size()-1;i>=0;i--){
        if(tmp[i]*tmp[i]) continue; //k가 제곱수일 경우, 약수에는 k^1/2가 하나만 들어가야 하기 때문
        tmp.push_back(k/tmp[i]);
    }

    return tmp;
}