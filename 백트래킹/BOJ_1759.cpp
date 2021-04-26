#include <bits/stdc++.h>
using namespace std;

int n,m; // n : 암호길이 , m : 암호가 될 수 있는 알파벳 수
string arr,input;
int isused[20];

void func(int k,int isprev);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        char ch;
        cin >> ch;
        input.push_back(ch);
    }
    sort(input.begin(),input.end());
    
    func(0,0);
    
}

void func(int k,int isprev){
    if(k == n){
        int num_vowel=0,num_conso=0; // num_vowel : 모음 수 , num_conso : 자음 수
        
        for(int i=0;i<n;i++){
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                num_vowel++;
            }else num_conso++;
        }
        if(num_vowel >= 1 && num_conso >= 2){
            for(int i=0;i<n;i++)
                cout << arr[i];
            cout << '\n';
        }
        return ;
    }
    for(int i=isprev;i<m;i++){
        if(!isused[i]){
            isused[i] = 1;
            arr[k] = input[i]; 
            //위처럼 string 인덱스로만 원소를 추가하면 공간이 할당되지 않아서 출력할 때, 직접 index를 참조해서 출력해야한다.
            //인덱스로만 원소를 추가하면 string size가 0이다.
            func(k+1,i+1);
            isused[i] = 0;
        }
    }
}