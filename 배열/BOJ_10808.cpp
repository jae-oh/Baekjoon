#include <bits/stdc++.h>
using namespace std;

//전역변수는 초기화하지 않아도 0으로 배열이 초기화된다.

int main(){
    ios::sync_with_stdio(false); //C stream과 C++ stream 동기화 끊기
    cin.tie(nullptr); // cin 명령을 수행하기 전 cout 버퍼를 비우지 않도록 하기 (시간상 이점)

    char input[101];
    int alpha[26];

    // 1번째 위치(alpha)부터 끝(alpha+sizeof(alpha)/sizeof(*alpha))까지 0으로 할당
    // 주의점 : int형은 4byte이기때문에 초기화하기 위한 배열 전체 길이로 만들려면 sizeof(*alpha)로 만들어 줘야함
    fill(alpha,alpha+sizeof(alpha)/sizeof(*alpha),0);

    /*
    for(int i = 0 ; i < 26 ; i++)
        alpha[i] = 0;
    */

    cin >> input;
    
    for(int i = 0 ; i < strlen(input) ; i++){
        for(int j = 0 ; j < 26 ; j++ ){
            if(input[i] == 'a' + j){
                alpha[j]++;
                break;
            }
        }
    }

    //auto 키워드는 초긱값 형식에 맞춰 선언하는 변수의 형식이 '자동'으로 결정된다.
    for(auto i : alpha) 
        cout << i << ' ';

    return 0;

}

/*
바킹독 풀이 
-0으로 초기화된 배열 하나를 만들고 인덱스 자체를 a~z까지로 보고 string하나씩 볼 때마다 a~z에 맞는 배열[인덱스]를 ++해준다.
-시간복잡도가 내가 짠 코드는 O(n의 제곱)이지만, 이 풀이는 O(n)이 걸린다

#include <bits/stdc++.h>
using namespace std;

int freq[26];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s)
    freq[c-'a']++;
  for(int i = 0; i < 26; i++)
    cout << freq[i] << ' ';
}
*/