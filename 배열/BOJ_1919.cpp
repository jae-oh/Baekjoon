#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int str1_alpha[500],str2_alpha[500];
int cnt=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str1 >> str2;
    for(int i=0;i<str1.size();i++)
        str1_alpha[str1[i]-'0']++;
    for(int i=0;i<str2.size();i++)
        str2_alpha[str2[i]-'0']++;

    for(int i='a'-'0';i<='z'-'0';i++){
        if(str1_alpha[i] > str2_alpha[i]){
            while(str1_alpha[i] != str2_alpha[i]){
                str1_alpha[i]--;
                cnt++;
            }
        }else if(str2_alpha[i] > str1_alpha[i]){
            while(str1_alpha[i] != str2_alpha[i]){
                str2_alpha[i]--;
                cnt++;
            }
        }
    }
    cout << cnt;
}