#include <bits/stdc++.h>
using namespace std;

char board[15][10],tmp_board[15][10]; //tmp_board는 터진 뿌요 위치에 .을 넣은 필드
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int num_boom=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<12;i++)
        for(int j=0;j<6;j++){
            cin >> board[i][j];
            tmp_board[i][j] = board[i][j];
        }
    
    while(1){
        int isused[15][10];
        bool isboom = false;
        vector<pair<int,int>> vec; //뿌요가 4개이상 터진 곳의 좌표를 넣기 위한 vector

        for(int i=0;i<15;i++)
            for(int j=0;j<10;j++)
                isused[i][j] = 0;
        
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(!isused[i][j] && board[i][j] != '.'){
                    queue<pair<int,int>> Q;
                    int color_num=1; //bfs로 찾은 구역의 넓이(뿌요가 모여있는 수)
                    isused[i][j] = 1;
                    Q.push({i,j});
                    while(!Q.empty()){
                        pair<int,int> cur = Q.front();
                        Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx= cur.first + dx[dir];
                            int ny= cur.second + dy[dir];
                            if(nx<0||nx>=12||ny<0||ny>6)
                                continue;
                            if(isused[nx][ny] || board[nx][ny] != board[cur.first][cur.second])//간 적있는 곳이거나 뿌요의 색깔이 지금색깔과 다를경우
                                continue;
                            Q.push({nx,ny});
                            isused[nx][ny] = 1;
                            color_num++;

                            if(color_num >= 4){ //뿌요가 4개이상 모여있으면, 모여있는 좌표를 vector에 넣어주고 반복문끝
                                vec.push_back({nx,ny});
                                isboom =true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        for(int i=0;i<15;i++)
            for(int j=0;j<10;j++)
                isused[i][j] = 0;
        
        if(isboom== true){ //만약에 4개이상 모여있는 뿌요가 있다면, 아까 vec안에 저장해둔 좌표를 bfs돌려 그 구역을 .으로 만들어줌
            num_boom++;
            for(auto i : vec){
                queue<pair<int,int>> Q;
                Q.push({i.first,i.second});
                isused[i.first][i.second];
                tmp_board[i.first][i.second] = '.'; //그냥 board를 bfs돌리면 그 다음 구역의 색깔과 비교를 못하기 때문에 tmp_board에 그 구역 .으로 저장
                while(!Q.empty()){
                        pair<int,int> cur = Q.front();
                        Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx= cur.first + dx[dir];
                            int ny= cur.second + dy[dir];
                            if(nx<0||nx>=12||ny<0||ny>6)
                                continue;
                            if(isused[nx][ny] || board[nx][ny] != board[cur.first][cur.second])
                                continue;
                            Q.push({nx,ny});
                            isused[nx][ny] = 1;
                            tmp_board[nx][ny] = '.'; //터진 뿌요구역에 .으로 저장
                        }
                    }
            }
            for(int i=0;i<6;i++){ //뿌요들을 빈공간없게 밑으로 정렬하는 for문
                for(int j=15;j>=0;j--){
                    if(tmp_board[j][i] == '.'){
                        for(int k=j-1;k>=0;k--){
                            if(tmp_board[k][i] != '.'){
                                swap(tmp_board[k][i],tmp_board[j][i]);
                                break;
                            }
                        }
                    }
                }
            }

            for(int i=0;i<12;i++){
                for(int j=0;j<6;j++){
                    if(tmp_board[i][j] != board[i][j])
                        board[i][j] = tmp_board[i][j];
                }   
            }
        }else{
            break;
        }
    }
    cout << num_boom;
}