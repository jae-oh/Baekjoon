#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> L;
    list<char>::iterator t = L.begin();
    int n;
    string s;

    cin >> n;

    for(int i=0 ;i<n ;i++){
        cin >> s;
        for(auto j : s){
            if(j == '>'){
                if(t == L.end())
                    continue;
                t++;
            }else if(j == '<'){
                if(t == L.begin())
                    continue;
                t--;
            }else if(j == '-'){
                if(L.empty() || t == L.begin())
                    continue;
                t--;
                t = L.erase(t);
            }else{
                L.insert(t,j);
            }
        }
        for(auto k : L)
            cout << k;
        cout<< "\n";
        L.clear(); //리스트 초기화
        t = L.begin(); //왠지 모르겠지만 list<char>::iterator t = L.begin();을 여기다 쓰면 런타임에러(segfault)가 일어난다.
    }

    return 0;
}