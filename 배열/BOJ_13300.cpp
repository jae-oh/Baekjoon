#include <bits/stdc++.h>
using namespace std;

int n,k,m_cnt=0,g_cnt=0;
int m_arr[7];
int g_arr[7];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i=0;i<n;i++){
        int gender,year;
        cin >> gender >> year;
        if(gender == 0){
            g_arr[year]++;
        }else{
            m_arr[year]++;
        }
    }
    for(int i=1;i<=6;i++){
        if(g_arr[i]%k == 0)
            g_cnt += g_arr[i]/k;
        else if(g_arr[i] != 0)
            g_cnt += g_arr[i]/k+1;
            
        if(m_arr[i]%k == 0)
            m_cnt += m_arr[i]/k;
        else if(m_arr[i] != 0)
            m_cnt += m_arr[i]/k+1;
    }
    cout << m_cnt+g_cnt;
}