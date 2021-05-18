#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        int student_n;
        int student[100005],iscycle[100005];
        int ans=0;
        queue<int> Q;
        cin >> student_n;
        for(int i=1;i<=student_n;i++){
            cin >> student[i];
            iscycle[i] = 0 ;
        }
        
        for(int i=1;i<=student_n;i++){
            if(iscycle[i] == 0){
        }

        for(int i=1;i<=student_n;i++){
            cout << iscycle[i] << ' ';
        }

        cout << '\n';
    }
}