#include <bits/stdc++.h>

using namespace std;

int n,m;
int board[60][60];
int minN=INT_MAX,dist[5000];
//vector<int> combi;
vector<pair<int,int>> store;
vector<pair<int,int>> house;

void findDist(int x,int y);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt=0;

    cin >> n >> m;
    /*for(int i=0;i<n;i++){
        if(i<=m)
            combi.push_back(1);
        else
            combi.push_back(0);
    }*/

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                store.push_back({i,j});
            }else if(board[i][j] == 1){
                house.push_back({i,j});
            }
        }
    }

    vector<int> combi(store.size(), 1); //store.size()만큼 1로 초기화
    fill(combi.begin(), combi.begin() + store.size() - m, 0);//처음부터 store.size()-m까지 0으로 초기화

    //sort(store.begin(),store.end()); //모든 permutation을 얻기 위해서는 정렬이 필요하다.
    
    do{//next_permutation함수를 이용하여 모든 조합의 경우의 수 구함
        int temp=0;
        fill(&dist[0],&dist[5000],INT_MAX); //MIN값을 구해야하기 때문에 INT_MAX로 초기화
        for(int i=0;i<store.size();i++){ //0~store.size()까지 조합의 수, 예를 들어 3개에서 2개면 0,1,2에서 0,1 / 0,2 / 1,2 가 나옴
            if(combi[i] == 0) continue; // 만약 combi가 {0, 1, 1} 이면 맨 뒤와 두번째 값만 나오게되어서 3개 중에 2개로 조합이 나오게됨
            //cout << store[i].first << store[i].second << ' ';
            findDist(store[i].first,store[i].second);
        }
        for(int i=0;i<house.size();i++)
            temp += dist[i];
        if(minN > temp)
            minN = temp;
        //cout << minN << '\n';
    }while(next_permutation(combi.begin(),combi.end()));

    cout << minN;

}

void findDist(int x,int y){ //x,y좌표에 대응되는 곳과 집들간의 사이 거리 구하는 함수
    for(int i=0;i<house.size();i++){
        dist[i] = min((abs(house[i].first - x)+ abs(house[i].second - y)), dist[i]);
    }
}