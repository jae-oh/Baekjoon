#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    list<char> eList; // editor Linked List
    string input; // 초기에 입력될 문자열
    int n; // 입력할 명령어 개수
    char c; // 명령어 문자

    cin >> input >> n;
    
    //eList에 문자열을 다 넣어준 뒤 iterator를 만들어줘야함
    for(int i : input)
        eList.push_back(i);
    
    list<char>::iterator begin_eList = eList.begin(); // eList 처음을 가리킴 (auto begin_eList = eList.begin(); 도 가능)
    list<char>::iterator end_eList = eList.end(); // eList 마지막을 가리킴 (auto end_eList = eList.end(); 도 가능)
    auto t = eList.end(); // 처음 커서는 문자열 마지막에 있으므로 eList.end()로 iterator 지정 (주의할 점은 마지막 값보다 한 칸 뒤에 위치해있기에 end iterator는 값이 존재하지 않는다.)

    for(int i=0 ; i<n ; i++){
        cin >> c;
        if(c == 'L'){
            if(t == begin_eList)
                continue;
            t--; //iterator 앞으로(왼쪽)
        }
        if(c == 'D'){
            if(t == end_eList)
                continue;
            t++; //iterator 뒤로(오른쪽)
        }
        if(c == 'B'){
            if(t == begin_eList)
                continue;
            if(--t == begin_eList) // 삭제할 노드가 begin_eList이면 begin_eList++ 해준 뒤 삭제
                begin_eList++;
            t = eList.erase(t); // iterator가 가리키는 값을 제거 후 그 다음 원소의 위치를 다시 t로 지정
        }
        if(c == 'P'){
            cin >> c;
            eList.insert(t,c); // iterator가 가리키는 곳 앞에 c 삽입
            if(t == begin_eList)
                begin_eList--;
        }
    }

    for(auto i : eList)
        cout << i;

    return 0;
}

/*
바킹독 풀이 : 나처럼 처음에 List.begin()/List.end()을 변수로 정해두고 할 필요가 없이 필요할 때마다 List.begin()/List.end()을 쓰면 된다; 난 넘 멍청한듯 ;

#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string init;
  cin >> init;
  list<char> L;
  for (auto c : init) L.push_back(c);
  auto cursor = L.end();
  int q;
  cin >> q;
  while (q--) {
    char op;
    cin >> op;
    if (op == 'P') {
      char add;
      cin >> add;
      L.insert(cursor, add);
    }
    else if (op == 'L') {
      if (cursor != L.begin()) cursor--;
    }
    else if (op == 'D') {
      if (cursor != L.end()) cursor++;
    }
    else { // 'B'
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L) cout << c;
}
*/