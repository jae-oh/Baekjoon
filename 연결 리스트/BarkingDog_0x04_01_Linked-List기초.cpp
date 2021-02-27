#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  list<int> L = {1, 2};                // 1 2
  list<int>::iterator t = L.begin();   // t는 1을 가리키는 중
  list<int>::iterator end_t = L.end(); //리스트의 끝을 리턴하는데, 여기서 주의할 점은 마지막 값보다 한 칸 뒤에 위치해있기에 값은 없다.
  L.push_front(10);                    // 10 1 2
  cout << *t << '\n';                  // t가 가리키는 값 = 1을 출력
  L.push_back(5);                      // 10 1 2 5
  L.insert(t, 6);                      // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
  t++;                                 // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
  t = L.erase(t);                      // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
                                       // 10 6 1 5, t가 가리키는 값은 5
  cout << *t << '\n';                  // 5
  for (auto i : L)
    cout << i << ' ';
  cout << '\n';
  for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << ' ';

  /*
  반복자

  begin(): beginning iterator 반환
  end(): end iterator 반환

  삽입
  push_front(element): 리스트 맨 앞에 원소 추가
  push_back(element): 리스트 맨 뒤에 원소 추가
  insert(iterator, element): iterator가 가리키는 부분의 앞에 원소 추가

  삭제
  pop_front(): 리스트 맨 앞의 원소 삭제
  pop_back(): 리스트 맨 뒤의 원소 삭제
  erase(iterator): iterator가 가리키는 부분의 원소 삭제

  조회
  *iterator: iterator가 가리키는 원소에 접근
  front(): 첫번째 원소 반환
  back(): 마지막 원소 반환

  기타
  empty(): 리스트가 비어있는지 여부
  size(): 리스트 사이즈 반환
  */
}