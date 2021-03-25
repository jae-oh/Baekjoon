#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> st;
string s;

//**cmp함수 짜는 법
/*
bool 함수이름 (const 변수형& a, const 변수형& b){
    if(a가 b보다 앞에 올 조건) return true;
    return false;
}
*/

bool cmp(string& a,string& b); 
//비교 함수의 인자로 STL 혹은 클래스 객체를 전달시 reference를 사용
//주의점 : 비교 함수는 두 값이 같을 때는 항상 false를 반환해야한다.


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        cin >> s;
        st.push_back(s);
    }
    sort(st.begin(),st.end(),cmp);
    for(auto i : st)
        cout << i << '\n';
}

bool cmp(string& a,string& b){
    if(a.size() < b.size()) return true; //a.size가 b.size보다 작으면 a가 앞에 온다.
    else if(a.size() == b.size()){
        int cnt_a=0,cnt_b=0;
        for(int i=0;i<a.size();i++)
            if(a[i] >= '0' && a[i] <= '9')
                cnt_a += a[i] - '0';
        for(int i=0;i<b.size();i++)
            if(b[i] >= '0' && b[i] <= '9')
                cnt_b += b[i] - '0';
        if(cnt_a < cnt_b) //cnt_a가 cnt_b보다 작으면 a가 앞으로
            return true;
        else if(cnt_a == cnt_b){
            for(int i=0;i<a.size();i++){
                if(a[i] < b[i]) return true; //a[i]가 b[i]보다 작으면 a가 앞으로
                else if(a[i] == b[i]) continue;
                else return false;
            }
            return false;
        }
        else return false;
    }else return false;
}