#include <bits/stdc++.h>
using namespace std;

int n,m,sum=0;
deque<int> deq1;
deque<int> deq2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        deq1.push_back(i);
        deq2.push_back(i);
    }
    while(m--){
        int k,cnt1=0,cnt2=0;
        cin >> k;
        while(deq1.front()!=k){
            deq1.push_back(deq1.front());
            deq1.pop_front();
            cnt1++;
        }
        while(deq2.front()!=k){
            deq2.push_front(deq2.back());
            deq2.pop_back();
            cnt2++;
        }
        if(cnt1 < cnt2){
            deq1.pop_front();
            sum += cnt1;
            deq2.clear();
            for(auto i: deq1)
                deq2.push_back(i);
        }else{
            deq2.pop_front();
            sum += cnt2;
            deq1.clear();
            for(auto i: deq2)
                deq1.push_back(i);
        }
    }
    cout << sum;

}