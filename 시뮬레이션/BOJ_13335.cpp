#include <bits/stdc++.h>
using namespace std;

int n,w,l;//n:트럭수 , w:다리길이, l:다리하중
int truck[1005];
int idx,t,cur_weight;
//Q는 다리위에 있는 트럭을 나타낸다.(FIFO)성질 이용
queue<pair<int,int>> Q; //Q.first에는 무게, second에는 진입시간+다리길이를 넣어준다.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w >> l;
    for(int i=0;i<n;i++)
        cin >> truck[i];
    
    t=1;
    Q.push({truck[0],1+w});
    cur_weight=truck[0];
    idx=1;
    while(!Q.empty()){
        t++;
        if(Q.front().second == t){ //현재 시간이 다리위에 맨 앞의 트럭의 진입시간+다리길이만큼 되었다면 Q를 빠져나온다(다리를 빠져나온다.)
            cur_weight -= Q.front().first;
            Q.pop();
        }
        if(cur_weight+truck[idx] <= l && idx < n){ //현재 다리위의 트럭들 무게 합과 들어갈려는 트럭의 무게 합이 다리의 하중보다 낮거나 같으면 다리로 진입한다.(Q에 넣어준다.)
            Q.push({truck[idx],t+w});
            cur_weight += truck[idx];
            idx++; //다음 순서의 트럭
        }
    }
    cout << t;
}