#include <bits/stdc++.h>
using namespace std;

int n,cnt_1=0,cnt_0=0;
string input;

/*
#문제풀이 아이디어
-0구역의 수와 1구역의 수 중 작은 구역의 수만큼 뒤집어주면 모두 같은 수로 만들 수 있는 최소값이다.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    for(int i=0;i<input.length();i++){
        if(i+1 >= input.length()){
            if(input.at(i) == '1')
                cnt_1++;
            else
                cnt_0++;
            
            break;
        }
        if(input.at(i) != input.at(i+1)){
            if(input.at(i) == '1')
                cnt_1++;
            else
                cnt_0++;
        }
    }

    cout << min(cnt_0,cnt_1);
    
}