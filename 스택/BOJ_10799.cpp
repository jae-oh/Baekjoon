#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char input[100000]; //입력
    stack<char> S; //여는 괄호를 담을 stack
    int n=0; //총 쇠막대기 조각 개수

    cin >> input;
    
    for(int i=0;i<strlen(input);i++){      
        if(input[i] == '('){
            if(input[i+1] == ')'){ //레이저일 경우, 그 때 stack사이즈를 더해줌
                i++;//i++을 안해주면 다음 인덱스일 때, else if문으로 감
                n += S.size();
                continue;
            }
            S.push(input[i]); //레이저가 아닐 경우, stack에 push (쇠막대기 시작)
        }else if(input[i] == ')'){ //쇠막대기의 끝
            if(S.empty())
                break;
            S.pop();
            n++;// 쇠막대기 끝일 경우, n에 ++;
        }
    }

    cout << n << "\n";
}