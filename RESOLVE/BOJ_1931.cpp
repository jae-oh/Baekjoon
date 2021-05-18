#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어
- 현재시간 이상부터 시작되는 회의 가운데, 회의 종료시간이 가장 빠른 것을 선택하면 된다.
*/

int n,ans=0,cur=0;
pair<int,int> meeting[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> meeting[i].second >> meeting[i].first; // 회의 시작시간을 second에 두는 이유는 정렬할 때, 회의 종료시간을 기준으로 하기 위하여
    
    sort(meeting,meeting+n);

    for(int i=0;i<n;i++){
        if(meeting[i].second < cur) //시작시간이 현재시간보다 앞 시간이면 그 회의는 선정 X
            continue;
        cur = meeting[i].first; //시작시간이 현재시간보다 뒷시간이고, 종료시간 순대로 오름차순으로 정렬되었으니 위의 조건을 넘어서면 무조건 회의가 진행된다.
        ans++;
    }
    cout << ans;
}