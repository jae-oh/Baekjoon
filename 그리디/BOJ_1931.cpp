#include <bits/stdc++.h>
using namespace std;

int n,cnt=0,cur_time=0;
pair<int,int> m_time[100005];

bool cmp(int a, int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> m_time[i].second >> m_time[i].first;
    sort(m_time,m_time+n);
    for(int i=0;i<n;i++){
        if(m_time[i].second >= cur_time){
            cnt++;
            cur_time = m_time[i].first;
        }else{
            continue;
        }
    }
    cout << cnt;
}