#include <bits/stdc++.h>

using namespace std;

//전역 변수이기 때문에 자동으로 0으로 초기화됨.
double freq[10]; //각 자리에 나오는 숫자들 횟수세기 위한 배열

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string roomN; // 한 자리씩 비교하기 위해 숫자지만 string 키워드 사용
    double maxN;

    cin >> roomN;

    for(auto i : roomN)
        freq[i - '0']++; // i-'0'을 통하여 문자 -> 숫자로 형변환

    freq[6] = (freq[6] + freq[9])/2;
    freq[9] = freq[6];

    //max_element함수는 iterator를 반환하므로 값을 참조하려면 * 연산자를 붙여야한다.
    maxN = *max_element(freq,freq + sizeof(freq)/sizeof(*freq));

    cout << ceil(maxN);

    return 0;

}