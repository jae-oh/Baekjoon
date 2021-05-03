#include <bits/stdc++.h>
using namespace std;

int n,c;
pair<int,int> arr[1005]; //입력받을 때, 값과 언제나왔는지 표시하는 값을 저장한다.
vector<tuple<int,int,int>> vec;

bool cmp(tuple<int,int,int>& a, tuple<int,int,int>& b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second = i; //언제 나왔는지 표시
    }
    sort(arr,arr+n); //값들로 정렬해줘서 같은 값끼리 모아준다.

    for(int i=0;i<n;i++){
        int cnt=0,minN = arr[i].second; //cnt는 어떤 값에 대해서 같은 수가 몇번 나왔는지 센다 , 그리고 minN은 같은 수 빈도가 같을 때 비교하기 위해서 입력받을 때, 그 수가 언제 처음 나왔는지 저장한다.
        for(int j=i;j<n;j++){
            if(arr[j].first ==  arr[j+1].first){//같은 수가 나오면 cnt++
                cnt++;
                if(minN > arr[j].second)//만약 같은 수 중에서 빨리 나왔다면 언제 나왔는지 저장
                    minN = arr[j].second;
                i++; //i++을 해주어서 반복적으로 검사하지 않도록 해준다.
            }else{
                cnt++; //다음 값이 다른 값이라면 지금값도 cnt에 넣어줘야기 때문에 ++해준뒤 break로 끝낸다.
                break;
            }
        }
        vec.push_back(make_tuple(cnt,minN,arr[i].first)); //vec에는 빈도, 언제나왔는지, 값을 넣어준다.
    }

    /*for(auto i : vec){
        cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';
    }*/

    sort(vec.begin(),vec.end(),cmp); //vector를 빈도, 언제 처음나왔는지에 대해서 내림차순으로 정렬해준다.

    for(auto i : vec){
        for(int j=0;j<get<0>(i);j++){
            cout << get<2>(i) << ' ';
        }
    }
    
}

bool cmp(tuple<int,int,int>& a, tuple<int,int,int>& b){
    if(get<0>(a) > get<0>(b)) return true;
    else if(get<0>(a) == get<0>(b)){
        if(get<1>(a) < get<1>(b)) return true;
        else return false;
    }
    else return false;
}