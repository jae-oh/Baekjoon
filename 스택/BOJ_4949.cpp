#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    stack<char> stack;
    bool isValid;
    //입력값에 공백이 존재하기 때문에 getline함수를 사용한다. (getline 함수 2개)
    //마지막 인자인 delim은 생략 가능하고, 만약에 생략하면 default로 "\n"이 들어간다.
    //1.getline(istream& is, string& str, char delim);
    //is : 입력스트림 오브젝트 (cin 등등), str : 입력받은 문자열을 저장할 string 객체, delim : 제한자로써 이 문자에 도달시 입력 중단
    //2.cin.getline(char* s, streamsize n, char delim);
    //s : C형식 문자열을 저장할 배열을 가리키는 포인터 , n :  저장할 문자의 최대 개수, delim : 제한자로써 이 문자에 도달시 입력 중단
    getline(cin,str);

    while(str != "."){
        isValid = true;
        for(auto i : str){
            if(i == '(' || i == '['){
                stack.push(i);
            }else if(i == ')'){
                if(stack.empty() || stack.top() != '('){
                    isValid = false;
                    break;
                }else{
                    stack.pop(); //pop할 때는 항상 stack.empty 확인하기
                }
            }else if(i == ']'){
                if(stack.empty() || stack.top() != '['){
                    isValid = false;
                    break;
                }else{
                    stack.pop();
                }
            }else{
                continue;
            }
        }
        if(!stack.empty()){ //문자열을 다 검사하고 나왔을 때, stack이 비어있지 않으면 괄호쌍이 다 맞지 않았다는 뜻
            isValid = false;
        }
        if(isValid){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
        while(!stack.empty())
            stack.pop();
        getline(cin,str);
    }

}