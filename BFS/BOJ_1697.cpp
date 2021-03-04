#include<bits/stdc++.h>

using namespace std;

int board[200001];
int dist[200001];
int n,m;//n:수빈이 위치, m:동생 위치
int dx[3]={1,-1,2};

//수빈이와 동생은 0과 100000사이에 있다. 하지만 그렇다고 수빈이가 0에서 100000사이만 이동할 수 있는건 아니다
//이 점을 유의해서 문제들을 자세히 보자!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> Q;

    cin >> n >> m;

    fill(dist,dist+sizeof(dist)/sizeof(int),-1);
    dist[n] =0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int dir=0;dir<3;dir++){
            int nx;
            if(dir== 0 || dir ==1)
                nx = cur+dx[dir];
            else
                nx = cur*dx[dir];
            
            if(nx<0 || nx>200000)
                continue;
            if(dist[nx] >= 0)
                continue;
            dist[nx] = dist[cur]+1;
            Q.push(nx);
        }
    }

    cout << dist[m]; //수빈이와 동생의 위치가 같을 때, 출력해줘야하므로 위에서 출력하면 안된다.

}