# Reference Code review

## Data Structure Review
* [Stack]()
 * 
* [Queue](./queue.cpp)
* [LinkedList](./LinkedList.cpp)
* [Hash](./hash.cpp)

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
