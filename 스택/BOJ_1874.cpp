#include <bits/stdc++.h>
using namespace std;

int n,cnt=1;
bool isVal=true;
string str;
stack<int> s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        while(1){
            if(cnt >= n+2){
                isVal = false;
                break;
            }
            if(!s.empty() && s.top() == a){
                s.pop();
                str.push_back('-');
                break;
            }else{
                s.push(cnt++);
                str.push_back('+');
            }
        }
    }
    if(!isVal)
        cout << "NO";
    else
        for(auto i : str)
            cout << i << '\n';
}