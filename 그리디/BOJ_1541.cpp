#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어 : '-'부호 뒤로 괄호를 씌워서 큰 숫자가 되게 해야한다
-> 즉, -부호 뒤로 +면 계속 빼주고, 만약에 -부호 뒤로 가다가 -부호가 나오면 멈추고, 또 다시 -부호 뒤로 +면 계속 빼준다.
-> 예시) 43-43+45-45 => 43-(43+45)-45 이렇게 만들어 준다.

#수와 부호 배열을 따로 만들어서 관리한다.
- 첫번째 수는 무조건 양수이기에 +로 저장한다.
*/

int ans=0,arr_n[100],cnt=0;
string str,arr_s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;
    arr_s.push_back('+'); //첫번째 수는 무조건 +이기에 저장(수 배열과 부호 배열의 인덱스 크기를 같게해줘야하기 때문)
    for(int i=0;i<str.length();i++){
        string num;
        int a=0;
        if('0' <=str[i] && str[i] <= '9'){ //수가 나오면 string에 뒤로 추가를 해서 숫자만으로 이루어진 string을 만든다.
            while(1){
                num.push_back(str[i]);

                if('0' <=str[i+1] && str[i+1] <= '9')
                    i++;
                else
                    break;
            }
            arr_n[cnt++] = stoi(num);//숫자만으로 이루어진 string을 stoi로 수로 만들어준다.
        }else{//부호가 나오면 부호 배열에 저장
            arr_s.push_back(str[i]);
        }
    }

   for(int i=0;i<arr_s.length();i++){
       int num=0;
       if(arr_s[i] == '+'){
            ans += arr_n[i];
       }else{ //arr_s[i] = '-'
            while(1){ //'-'부호가 나오면 뒤에 '-'부호가 나올 때까지 수를 빼준다.
                num += arr_n[i];
                if(arr_s[i+1] == '+' && i+1 < arr_s.length())
                    i++;
                else
                    break;
            }
            ans -= num;
       }
   }

    cout << ans;
}