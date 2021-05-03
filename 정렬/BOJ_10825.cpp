#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<string,int,int,int>> vec;

bool cmp(tuple<string,int,int,int>& a,tuple<string,int,int,int>& b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--){
        string name;
        int a, b, c;

        cin >> name >> a >> b >> c;
        vec.push_back(make_tuple(name,a,b,c));
    }
    sort(vec.begin(),vec.end(),cmp);

    for(auto i : vec)
        cout << get<0>(i) << '\n';
}

bool cmp(tuple<string,int,int,int>& a,tuple<string,int,int,int>& b){
    if(get<1>(a) > get<1>(b)) return true;
    else if(get<1>(a) < get<1>(b)) return false;
    else{
        if(get<2>(a) < get<2>(b)) return true;
        else if(get<2>(a) > get<2>(b)) return false;
        else{
            if(get<3>(a) > get<3>(b)) return true;
            else if(get<3>(a) < get<3>(b)) return false;
            else{
                if(get<0>(a) < get<0>(b)) return true;
                else return false;
            }
        }
    }
}