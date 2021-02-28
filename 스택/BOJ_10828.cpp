#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x; // 명령어 개수, 원소의 값
    string c; // 명령어
    stack<int> stack;

    cin >> n;

    for(int i=0 ;i<n ;i++){
        cin >> c;
        //strcmp : 문자열이 같다면 0을 반환, 다르면 음수 혹은 향수(str1 < str2 음수, str1 > str2 양수)
        //strncmp(str1,str2,n) : 매개 변수 3개가 들어가는데, 마지막 n은 문자열의 길이를 의미한다.
        //주의 : string 함수의 대부분은 char형태로 사용해야한다.
        //string 타입의 비교는 =로 가능하다.
        if(c == "push"){
            cin >> x;
            stack.push(x);
            continue;
        }else if(c == "pop"){
            if(stack.empty()){ //stack이 비어있을 때, pop하면 error
                cout << -1 << "\n";
                continue;
            }
            cout << stack.top();
            stack.pop();
        }else if(c == "size"){
            cout << stack.size();
        }else if(c == "empty"){
            cout << stack.empty();
        }else if(c == "top"){
             if(stack.empty()){ //stack이 비어있을 때, top하면 error
                cout << -1 << "\n";
                continue;
            }
            cout << stack.top();
        }else{
            break;
        }
        cout << "\n";
    }
}