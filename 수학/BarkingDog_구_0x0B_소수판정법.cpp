#include <bits/stdc++.h>
using namespace std;

/*
https://blog.encrypted.gg/757?category=773649 참조
*/

int n;
vector<int> p; 
bool isprime(int k);//시간복잡도 O(N)
bool isprime2(int k);//시간복잡도 O(N^1/2)
vector<int> allprime(int k);//에라토스테네스의 체 : N이하의 모든 소수 찾기

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if(isprime(n)) cout << "PRIME" << '\n';
    else    cout << "NO PRIME" << '\n';

    if(isprime2(n)) cout << "PRIME" << '\n';
    else    cout << "NO PRIME" << '\n';

    p = allprime(n);
    for(auto i : p)
        cout << i << ' ';
    cout << '\n';
}

bool isprime(int k){
    if(k == 1) return false;
    else{
        for(int i=2;i<k-1;i++){
            if(k%i == 0)
                return false;
        }
        return true;
    }
}

bool isprime2(int k){ 
    if(k == 1) return false;
    else{
        for(int i=2;i*i<=k;i++){
            if(k%i == 0)
                return false;
        }
        return true;
    }
}

vector<int> allprime(int k){
    vector<int> ret;  //prime
    vector<bool> state(10000,true); // 최적화3. int배열은 하나당 4byte,bool 배열은 하나당 1byte, bool vector는 하나당 1bit를 잡아먹음
    state[1] = false;
    for(int i=2;i*i<=k;i++){ //최적화2. i -> i*i
        if(!state[i]) continue; //이미 소수가 아닌 것으로 판명되었으면 건너뛴다.
        for(int j=i*i;j<=k;j+=i) state[j] = false; //최적화3.2*i -> i*i
    }
    for(int i=1;i<=k;i++)
        if(state[i]) ret.push_back(i);
    
    return ret;
}