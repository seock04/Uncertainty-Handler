# Reference Code review

## Data Structure Review
* [Stack]()
  * structure 의 stack 추가 삭제 등이 자유로운게 좋음 사이즈가 고정됨
* [Queue](./queue.cpp)
  * buffer 사이즈가 고정이라 오류 생길수 있음 
  * 그래서 circular queue로 만들수 있음 좋을 것 같음
* [LinkedList](./LinkedList.cpp)
  * 써티에서는 malloc을 활용하는건 비추천( buffer array를 미리 만들어 놓고 &기호를 통한 주소만 가져와서 new 한 것 같은 효과를 활용하는게 더 효율적)
  * double linked list 보다 single linked list가 나은 경우도 있음 
  * erase가 포함된 코드가 있으니 일부 보완 하더라도 손쉽게 활용할 수 있게 연습을 해 둔다면 좋을 것 같음
* [Hash](./hash.cpp)
  * 삭제가 없음
  * hash 함수는 자주 씀
  * hash buffer 사이즈 잡기가 애매함, 어떤 기준이 좋을까요?

## Algorithm Review
* [Quick Sort](./quicksort.cpp)
  * compare() 함수의 custom이 좀 더 자유로운 형태로 되어 있으면 좋을 것 같다. (예: 구조체의 sorting이 가능한 형태)
* [Binary Search](./binarysearch.cpp)
  * 정렬되어 있는 data에서 빠르게 검색하는 방법
  * 여기도 compare 함수의 custom이 좀 더 쉬우면 좋을 것 같다.
* [DFS](./dfs.cpp)
  * 재귀 함수 사용, memoization 및 가지치기 등으로 최적화 추가 가능  
* [BFS](./bfs.cpp)
  * queue 활용, 반복문 사용하기 때문에 재귀보다 빠름
  * queue의 buffer 사이즈를 잘 정의 하지 않으면 오류발생 가능
  * tree 에서 level 별로 구분해서 처리해야 하는 경우 현재 ref 코드 만으로는 부족 함
  * 최단거리 찾기에는 dfs보다 bfs가 더 좋음
