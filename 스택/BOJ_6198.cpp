#include <bits/stdc++.h>
using namespace std;

long long int n,sum=0;
stack<long long int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        long long int k;
        cin >> k;
        while(!s.empty()){
            if(s.top() > k) break;
            else s.pop();
        }
        sum += s.size();
        s.push(k);
    }
    cout << sum;
}   