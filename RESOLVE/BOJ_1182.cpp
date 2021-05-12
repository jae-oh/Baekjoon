#include <bits/stdc++.h>
using namespace std;

int n,m,ans=0;
int input[30];
vector<int> vec;

void func(int k, int cnt, int start);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> input[i];

    func(0,0,0);
    if(m == 0)
        cout << ans-1;
    else
        cout << ans;
}

void func(int k, int cnt, int start){
    if(cnt == m){
        ans++;
    }
    if(k==n){
        return ;
    }
    for(int i=start;i<n;i++){
        cnt += input[i];
        func(k+1,cnt,i+1);
        cnt -= input[i];
    }
}

/*
#include <bits/stdc++.h>

using namespace std;

int n,ans,cnt=0;
int input[21];

void func(int cur,int tot);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> ans;
    for(int i=0;i<n;i++)
        cin >> input[i];
    func(0,0);
    if(ans==0) cnt--; //정답이 0일 경우, 공집합이 무조건 count되기 때문에, -1
    cout << cnt;
}

void func(int cur,int tot){ //cur은 현재 트리 Level, tot은 현재까지 합계
    if(cur == n){
        if(tot == ans) cnt++;
        return;
    }
    func(cur+1,tot); //현재 상태에서 값을 더하지 않았을 경우
    func(cur+1,tot+input[cur]); //현재 상태에서 값을 더했을 경우
}
*/