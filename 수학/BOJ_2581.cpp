#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0;
vector<int> p;

bool isprime(int k);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i=n;i<=m;i++){
        if(isprime(i)){
             p.push_back(i);
             ans += i;
        }
    }

    if(!p.size()) cout << -1;
    else{
        cout << ans << '\n';
        cout << p.front();
    }
}

bool isprime(int k){
    if(k == 1) return false;
    else{
        for(int i=2;i*i<=k;i++)
            if(k%i == 0) return false;
        return true;
    }
}