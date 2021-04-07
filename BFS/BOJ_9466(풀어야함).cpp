#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        int student[100005];
        bool vis[100005];
        int m,cnt=0;
        cin >> m;
        for(int i=1;i<=m;i++){
            cin >> student[i];
            if(student[i] == i)
                vis[i] = true;
            else vis[i] = false;
        }
        for(int i=1;i<=m;i++){
            int tmp = i;
            while(1){
                if(vis[tmp]){
                    cnt++;
                    break;
                }
                else vis[tmp] = true;
                
                tmp = student[tmp];
            }
        }
    }
}