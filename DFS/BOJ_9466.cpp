#include <bits/stdc++.h>
using namespace std;

/*
#문제풀이 아이디어 (사이클이 있는지 확인하는 문제)
1. 처음 사이클을 돌 때, 방문했다고 표시를 해준다.
    1)iscycle++ (즉, -1에서 ++이니 0)
    2)vis = cycle_n (지금 돌고 있는 사이클이 맞는지 확인하기 위해)
2. 두번째 사이클을 돌 때, 이 학생은 사이클안에 있다고 표시해준다.
    1)iscycle++ (즉, 0에서 1)
3. iscycle이 1인 index학생은 사이클안에 있다. 즉 그룹에 속해있다
4. 전체학생 - 그룹에 속한 학생 수 = 정답

EX)1->2->3->2면 iscycle은 0 1 1 이 된다. 왜냐하면 1은 첫 사이클에는 있지만 결국 사이클안에 없기 때문에 0에서 증가하지 않는다.
*/
int n;
int cycle_n=1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        int st_n,st[100005],iscycle[100005],ans=0,vis[100005];
        //iscycle : 사이클 몇번 돌았는지 확인하기 위한 배열 , vis : 현재 사이클이 맞는지 확인하는 배열
        cin >> st_n;
        for(int i=1;i<=st_n;i++){
            cin >> st[i];
            iscycle[i] = -1;
            vis[i] = false;
        }

        for(int i=1;i<=st_n;i++){
            if(iscycle[i] == -1){
                int next_node = st[i];
                iscycle[i]++;
                vis[i] = cycle_n;
                while(iscycle[next_node] < 0){
                    iscycle[next_node]++;
                    vis[next_node] = cycle_n;
                    next_node = st[next_node];
                }

                while(iscycle[next_node] < 1 && vis[next_node] == cycle_n){
                    iscycle[next_node]++;
                    next_node = st[next_node];
                }
                cycle_n++;
            }
        }

        for(int i=1;i<=st_n;i++){
            if(iscycle[i] == 1){
                ans++;
                //cout << i << ' ';
            }
        }

        cout << st_n-ans << '\n';
    }
}