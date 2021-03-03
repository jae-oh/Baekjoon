#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //https://ijsilver.tistory.com/35
    //분배법칙을 이용하자.
    //tmp 변수를 초기에 1로 두고, 괄호를 열어주는 문자가 나오면 그에 맞게 곱해주고 닫아주는 문자가 나오면 결과값에 tmp를 더해주고 tmp를 나눠준다.

    string str;
    stack<char> S;
    int tmp=1,result=0;
    bool inValid = true;

    cin >> str;

    for(int i=0;i<str.length();i++){
        if(str[i] == '('){
            S.push('(');
            tmp *= 2;
        }else if(str[i] == '['){
            S.push('[');
            tmp *= 3;
        }else if(str[i] == ')'){
            if(S.empty() || S.top() != '('){
                inValid = false;
                break;
            }
            if(str[i-1] == '(')
                result += tmp;
            S.pop();
            tmp /= 2;
        }else{
            if(S.empty() || S.top() != '['){
                inValid = false;
                break;
            }
            if(str[i-1] == '[')
                result += tmp;
            S.pop();
            tmp /= 3;
        }
    }

    if(!S.empty())
        inValid = false;

    if(inValid)
        cout << result;
    else
        cout << '0';
}