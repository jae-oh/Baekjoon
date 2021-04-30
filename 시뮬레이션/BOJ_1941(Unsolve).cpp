#include <bits/stdc++.h>
using namespace std;

int board[7][7]; //1은 이다솜 , 2은 임도연
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans=0;
vector<pair<int,int>> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            char ch;
            cin >> ch;
            if(ch=='S')
                board[i][j] = 1;
            else
                board[i][j] = 2;
        }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int isused[7][7];
            for(int k=0;k<5;k++)
                for(int t=0;t<5;t++)
                    isused[k][t] = 0;

            //if(board[i][j] == 1){
                queue<tuple<int,int,int>> Q;
                Q.push({i,j,0});
                isused[i][j] = 1;
                while(!Q.empty()){
                    bool isagain = false;
                    tuple<int,int,int> cur = Q.front();
                    Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = get<0>(cur) + dx[dir];
                        int ny = get<1>(cur) + dy[dir];
                        int num_yun = get<2>(cur);
                        if(nx<0||nx>=5||ny<0||ny>=5)
                            continue;
                        if(isused[nx][ny])
                            continue;
                        
                        if(board[nx][ny] == 2){
                            if(get<2>(cur)+1 >3)
                                continue;
                            else
                                num_yun = get<2>(cur) +1;
                        }else{
                            for(auto k : vec)
                                if(k.first == nx && k.second == ny){
                                    isagain = true;
                                }
                            
                            if(isagain) continue;
                        }

                        Q.push({nx,ny,num_yun});
                        isused[nx][ny] = isused[get<0>(cur)][get<1>(cur)]+1;
                        if(isused[nx][ny] == 7)
                            ans++;
                    }
                }
                //vec.push_back({i,j});
                /*for(int k=0;k<5;k++){
                    for(int t=0;t<5;t++)
                        cout << isused[k][t] << ' ';
                    cout << '\n';
                }
                cout << '\n';*/
            //}
        }
    }

    cout << ans;
}