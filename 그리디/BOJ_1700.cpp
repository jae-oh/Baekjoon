#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
1. 빈공간이 없도록 모두 채워준다.
2. 현재 멀티탭 배열(cur)에 없는 것이 들어오면, 현재 멀티탭 배열 원소 중, 이 후 가장 늦게 들어오거나 사용하지 않는 것을 빼준다.
*/
int n,m,ans=0;
int cur[105],arr[105],chk[105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<m;i++)
        cin >> arr[i];
    
    for(int i=0;i<m;i++){
        bool isused = false;
        fill(chk,chk+n,0);

        for(int j=0;j<n;j++){ //현재 멀티탭에 빈 공간이 있으면 꽂기
            if(cur[j] == arr[i]){ //현재 꼽혀 있기 때문에 꽂을 필요가 없다.
                isused = true;
                break;
            }
            
            if(cur[j] == 0){
                cur[j] = arr[i];
                isused = true;
                break;
            }
        }

        if(!isused){ //만약 빈공간이 없고 꼽혀 있는 플러그들 중 꽂을 플러그가 없을 때
            for(int j=0;j<n;j++){ // 이 후에 사용횟수가 없거나 가장 늦게 사용되는 것들 구별 (사용횟수가 없으면 cnt가 최대값이 된다.)
                for(int k=i+1;k<m;k++){
                    if(cur[j] != arr[k])
                        chk[j]++;
                    else
                        break;
                }
            }

            int era_val = *max_element(chk,chk+n); //꼽혀 있는 플러그 중 이 후 가장 늦게 다시 사용되는 경우를 빼준다.
            for(int j=0;j<n;j++){
               if(chk[j] == era_val){ //현재부터 가장 멀리 있는 플러그를 빼줌
                   cur[j] = arr[i];
                   ans++;
                   break;
               }
            }
        }
    }

    cout << ans;
}