
개요 
우연한 기회에, Coding Interview를 준비하는 기회를 갖게 되었고, 그 과정에서 알게 된 내용 중 회사에서 업무와 함께 중요하게 하고 있는 Code Review 관점에서 Software의 복잡도와 Performance와 연관된 내용을 잘 이해 하는 것은 중요하다고 생각 되어서 그냥 내 머리 속에만 가지고 있기 보다는 필요로 하는 사람들에게 조금 더 정리해서 공유 하고자 한다.

우리 회사 기코딩 기본 교육에는 asymptotic notation에 대한 설명이나 Time Complexity 혹은 Space Complexity에 대한 내용 설명이 상대적으로 부족하다.  (Mooc 의 APS Advanced level 교육 참고, 중간 중간 간략하게 소개 하고 중요해요 라곤 하지만 정작 상세한 내용은 본인이 많이 찾아봐야 함)
그 중에서도 average, worst time complexity 의 의미와 이것들이 왜 중요한지는 개인적으로 Code Review 관점이나 개발자 기본 상식으로도 알고 있는게 필요해 보여서 내용을 정리해 보기로 한다.
먼저 내용을 이해하기 위해서 Time Complexity 와 Space Complexity 를 표기하는 일반적인 방법 중 하나인 Asymptotic Notation 중 Big-O 기법을 알아보기로 한다.


Space Complexity(공간복잡도): by the amount of memory space used by the algorithm
Time Complexity(시간복잡도): by the amount of computer time used by the algorithm

일반적으로 공간복잡도와 시간복잡도는 상충관계(trade-off)에 있다.  그렇지만 알고리즘을 평가할 때에는 주로 시간복잡도에 초점을 맞춘다.

 Asymptotic Notation의 하나인 Big-O 기법을 사용하는 이유?
Software가 동작하는 IT Device의 성능을 좌우 하는 것은 여러가지 요소가 있다. 그 중에는 CPU 성능, RAM/Memory Memory 용량과 함께 Software Algorithm이 큰 요소 중 하나이다. Device에서 보통 1가지 동작을 하는데 걸리는 시간을 "1 unit time" 이라고 할때 CPU나 RAM/Memory의 hardware dependency가 같다고 가정할 경우 SW 알고리즘에 따른 그 성능을 표기 하는 방법 중 하나로 Big-O를 사용한다.

물론 Big-O 외에도 다른 기법들이 있지만, Big-O 기법 내용만으로도 돌아가는 SW가 어느정도의 성능을 가지는지 객관적인 지표를 만들어 내는데에 충분하다고 생각이 들어 여기서는 다른 것들은 다루지 않으며, 더 필요한 분은 찾아보길 바란다.
Big O Notation에 대한 이해
기본적인 알고리즘의 복잡도를 표시 할 수 있다. 하나의 함수에 대해서 복잡도를 수식으로 우선 나타내고 이를 Big O 형태로 표현 해 보면 아래와 같다.



좀 더 상세하게 이해하기 위해, 예를 들어 아래와 같은 복잡도를 가지는 함수가 있다고 하자 (실제 이런 복잡도를 가지는 코드가 어떤 모습일 지는 Time complexity 예시 참고)
3*n^2 + n*log(n) + n + n/2

이 경우 Big O notation은 어떻게 될까? 

우선 Big O notation의 가정은 위에 함수로 들어오는 input의 값을 n이라고 할 때 n이 무한대로 커짐을 가정하고, 그 때 실제로 의미 있는 내용만을 표기 한다.

위의 경우, n이 무한대가 되면 각 항목(+ 로 더하고 있는 것들) 중  3*n^2 의 값이 가장 커 질 것이며, 이 때 다른 값들의 영향은 미미 하다고 볼 수 있다. 그렇기 때문에 여기서 의미 있는 것은 3*n^2 뿐이라고 하고 또한 3*n^2 중에서도 n이 무한대가 되면 3* 은 크게 영향을 주지 못하기 때문에 이 역시도 지우게 되며 이렇게 되면 최종 Big O notation으로 들어갈 것은 O(n^2) 이다.



그래서 결론적으로는, 가장 큰 항의 계수 를 삭제 한 것이 Big-O notation으로 쓰인다. 이며, 이유는, 나머지는 n이 무한대로 커졌을 때 다른 값들은 상대적으로 무의미 해 지기 때문이다.

이 말인즉슨, 로직을 짤 때 
n^2 을 1000000n 으로 만들어 낼 수 알고리즘이 있는 경우, n이 무한대로 커지는게 실제 가능하다면 n^2 보다는 1000000n 정도의 time complexity를 가지는 알고리즘이 더 효울 적인 것일 수 있다는 것이다.

물론, 현실에서  n 이 무한대로 커지지 않고, 커질 수 있는 최대값이 정해져 있다면, 그 부분은 추가로 고려 되어야 한다.

또한 2n 이나 10n 이나 time complexity만 고려하면 크게 다르지 않르지 않은 성능이다. 

그렇기 때문에  n^2로 짜야하는 (nested for 문을 써야 하는) 로직을 2n 혹은 3n 정도로 (독립적인 for문 2~3개로) 바꿀 수 있다면 이는 훌륭한 대안이 된 다고 할 수 있다.

Time Complexity(시간복잡도)

입력 Size에 따른 연산 횟수의 변화를 따지는 것을 말하며, 대표적인 Time Complexity 형태는 아래와 같다.
여기서 가장 좋은 것은 입력의 size가 많아 지더라도, 실제 연산의 횟수는 변하지 않거나 그 정도가 최소한으로 늘어 나는 것이 좋다. 


또한, Time complexity를 계산할 때, 아래와 같이 3가지 Type을 구하는데, 이 중 우리가 반드시 이해해야 하는 것은 Worst time complexity 이다.

Best Time Complexity - 알고리즘의 best case 로, 입력 값에 따라 가장 적은 횟수의 연산만 하는 경우 이를 Big-O notation으로 나타낼 수 있으며 이 경우의 Time complexity가 Best Time Complexity 이다.
Average Time Complexity - 알고리즘의 평균적인 성능을 나타내는 것으로 입력의 size를 다양하게 했을 때 평균적으로 필요한 연산위 횟수를 Big-O notation으로 나타낸 것이 Average Time complexity 이다.
Worst Time Complexity - 최악의 상황에 맞는 input size가 들어왔을 때, 알고리즘의 성능을 나타내는 것으로 최악의 형태로 input size를 넣었을 때  필요한 연산위 횟수를 Big-O notation으로 나타낸 것이다.
왜? Worst Time Complexity 인가?

알고리즘을 잘 짜서 Average Time Complexity는 괜찮다고 할 수 있는 정도의 시간이 들더라도, 최악의 경우 실제 수행에 드는 시간이 서비스가 수용하는 기준을 넘어가 버린다면 서비스 장애가 발생할 수 있기 때문이다. input size 늘어나는 정도에 따라 알고리즘 내부의 연산 횟수가 늘어나더라도, 내가 제공하는 서비스에서 허용하는 범위 내에서 동작 해야 하기 때문이다
시험을 위한 이해
사실 시험 만을 위한 내용이라면, 실제 상황과는 약간 다를 수 있다. 실제로 우리 회사 시험 에서는, worst case 의 time complexity 뿐만 아니라 이를 실질적으로 실행할 때 걸리는 시간으로 상대평가를 하기 때문에, + 알파를 더 알아야 하는 상황이긴 하다. 그래서 이론적 속도와 실제 실행 속도 간의 차이도 이해는 필요하다.
Theoretical Speed(이론적 속도): the number of operations performed by the algorithm

Practical Speed(실제 실행속도): the execution time performed by the algorithm
Time Complexity 예시Loop를 활용한 logic의 Time Complexity






1) constant time (고정된 시간)
func_return_true(100)
{
    return true;
 
}
// T(n) = 1
// Big O(1)
 
 
2) Logarithmic time (1/2 혹은 1/n 씩 줄어드는 시간)
for(i=1;i<=n;i*=2) {
       //application code
}
//T(n) = log(n)
//Big O(logn)
 
for(i=n;i>=1;i/=2) {
      //application code
}
//T(n) = log(n) (밑이 2인 로그)
//Big O(logn)
 
 
 
3) Linear time (선형시간)
for(i=1;i<=n;i++) {
    //application code
}
//Time Complexity T(n) = n,
//Big O(n)
 
for(i=1;i<=n;i+=2) {
     //application code
}
//Time Complexity T(n) = n/2
//Big O(n)
 
4) 이건 머라고...ㅡ.ㅡ;; 하더라..(선행시간 보단 크지만 Quadratic time 보단 빠름)
for(i=1;i<=n;i++) { f
     for(j=1;j<=n;j*=2) {
        //application code
     }
}
T(n) = n*log(n)
//Big O(nlogn)
 
 
5) Quadratic time
for(i=1;i<=n;i++) {
    for(j=1;j<=n;j++) {
       //application code
    }
}
//T(n) = n*n = n^2
//Big O(n^2)
 
 
// 이거 이상의 알고리즘은... 쓰면 욕먹어영~

재귀함수의 Time Complexity
실제 로직상 순차적으로 모든 N의 값을 순서대로 보고 수행하는 동작이 있는지 따져봐야 한다.
모든 input에 size 만큼 수행해야 하는 동작이 있다면 Big O(n) 가 되지만  Dynamic programming 의 동적 Table 같은걸 쓰거나 가지치기 기법(Prunning) 등을 어떤 식으로 적용하느냐에 따라 달라질 수 있다.






1) Linear time (선형시간)
int recursiveFun1(int n)
{
    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun1(n-1);
}
//Big O(n)
2) Linear time (선형시간)
int recursiveFun2(int n)
{
    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun2(n-5);
}
// O(n/5) = O(n)
 
 
3) Logarithmic time (1/2 혹은 1/n 씩 줄어드는 시간)
int recursiveFun3(int n)
{
    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun3(n/5);
}
//O(log(n))
 
4) Quadratic time
void recursiveFun4(int n, int m, int o)
{
    if (n <= 0)
    {
        printf("%d, %d\n",m, o);
    }
    else
    {
        recursiveFun4(n-1, m+1, o);
        recursiveFun4(n-1, m, o+1);
    }
}
//O(2^n)
 
 
5) Quadratic time
int recursiveFun5(int n)
{
    for (i = 0; i < n; i += 2) {
        // do something
    }
 
    if (n <= 0)
        return 1;
    else
        return 1 + recursiveFun5(n-5);
}
//(n-5) *(n/2) = (2n-10) * n = 2n^2- 10n =>  O(n^2)

우리가 사용하는 라이브러리의 Time Complexity도 알아야 하는가? 
기본적으로, 우리가 사용하는 대부분의 코드는, 내가 직접 만드는 것 보다는 이미 만들어 져 있는 API를 가져와서 사용하는 경우가 많을 것이다. 그렇다면, 그들을 활용해서 Code를 만들 때, 해당 API 내부에서 constant 한 고정된 시간만이 소요 되는 경우는 상관이 없지만, Array, Vector, String 등과 같이 해당 라이브러리 내에서 검색, 정렬, 추가, 삭제 기능이 제공되는 경우 내부적으로 이미 Big O(n) 이상의 복잡도를 가질 수 있는 경우가 있기 때문에 이런 경우는 어느정도 파악을 해 놓는게 내 코드를 작성 할 때도 도움이 될 수 있다.

왜냐하면 나는 내가 가진 코드의 복잡도가 O(n)이라고 생각 했는데 실질적으로 loop 안 loop로 인식 되어 O(n^2) 이 되는 경우도 쉽게 볼 수 있기 때문이다.
Space complexity 는 왜 중요한가?
Time 과 Space는 상호 보완적이다.
Time complexity를 낮추고 성능을 높이기 위해서 Space Complexity를 희생하는것이 가능하다. 그러므로, 현재 당신의 알고리즘이 이미 재대로 동작하는 상태에서, 성능을 향상시킬 수 있는 방법을 찾는 거라면, Space Complexity를 희생 할 수 있는 범위가 얼마나 되는지 따져보고, 그 한도 내에서 이를 희생하면서 얻을 수 있는 Time complexity의 효율 성이 얼마나 되는지 계산 해 보면 내가 뭘 해야 하는지 알 수 있다.
Space complexity(공간복잡도)
input으로 들어오는 n의 사이즈 외에 부가적으로 사용해야만 하는 memory 사용량을 표시 하는 것으로 예를 들어 Merge sort는  Space complexity가 O(n) 인데 이유는 정렬해야하는 data의 사이즈 만큼 부가적인 메모리를 추가로 할당 해야 하기 때문이다.
Space Complexity를 이해해야 하는 이유는 부가적인 메모리 사용이 필요한 경우는 HW 적인 dependency를 가질 수도 있고, 결과적으로는 장치의 속도에 영향을 주거나 가용한 메모리 사용량을 초과 하면 해당 알고리즘을 쓸 수 없는 상태가 되어 버리기 때문이다.

그래서 Merge Sort 같은 것을 무한대로 커지는 N을 입력으로 받는 기능에서 사용시, N이 만약 4 byte만 사용해도 최악의 경우 메모리 over flow를 발생 시킬 수 있는 여지가 생기는 것이다.

또 한 가지 주의 할 점은 함수 콜과 메모리의 사용 영역인데, 예를 들어 recursion 알고리즘의 경우는 함수 내에서 동일 함수를 반복해서 부르게 되며 이 때 해당 함수의 현재 상태는 stack 영역에 계속해서 저장되게 된다. 그리고 이 영역은 해당 함수에서 호출한 recursion 함수가 종료되고 다시 돌아올 때까지 유지 되기 때문에 무한대의 recursion이 이루어 지게 되면 over flow가 발생할 수 밖에 없으니 이 역시 조심해야 한다.
Sorting 알고리즘을 배우는 우리가 왜 이걸 배우는지 알아야 하는 이유
우리는 지금까지 알고리즘을 구현 한 Code를 볼 때 Time & Space complexity를 고려해야 한다는 내용에 대해서 알아봤다. 실제로 이런 것들을 고려해서 사용하는 알고리즘의 대표적인 것이 Search & Sorting인데, 이번엔 존재하는 알고리즘들의 Time & Space complexity를 한번 확인 해 보고 왜 단순히 가장 좋은 search 혹은 sorting 알고리즘 하나만 이해하는게 아닌 여러 가지 알고리즘을 아는게 필요한지 이야기 해 보겠다.

우선, 알고리즘 별 Time & Space complexity 는 대체적으로 아래와 같다.


여기서 우리가 눈여겨 봐야 하는 것은, Time Complexity 중 Worst 와 Space Complexity 정보 이다. 

그렇다면, 여기서 가장 좋은 알고리즘은 무엇일까? Average 가 O(nlog(n)) 인 Quick Sort? 아니면 Worst Time complexity 까지 O(nlog(n)) 인 Mergesort? 정답은 주어진 data와 정렬 시 원하는 결과의 상태에 따라 다르다 이다.
이유는, Quick Sort는 Worst case 가 O(n^2) 이지만, Average는 O(nlog(n)) 이고 Worst를 회피할 수만 있다면, Space Complexity는 O(log(n)) 이기 때문에 memory를 많이 사용 할 수 없는 경우에는 Mergesort보다 나은 대안이 될 수 있기 때문이다.

그럼, Worst case가 이미  O(n^2) 다른 알고리즘은 도대체 왜? 알아야 하는 것일까? 거기에는 또 다른 이유가 있다.
Sorting 된 결과가 Stable 하냐 혹은 in place 하냐 하는 것도 중요 한 요소 중 하나다.Stable의 정의
Sorting에 사용되는 정렬 key 값이 original data 그룹 에서 동일한 것이 존재 할 때, original data 그룹에서의 이들 data의 순서가, sorting이 완료된 이후에 변하지 않은 것을 의미 한다.In place의 정의
Sorting을 하기 위해 전달 받은 original data 그룹 외에 부가적인 memory를 사용해야 하는 건지 그렇지 않은건지에 대한 내용으로 In place 한 경우는 부가적인 메모리 사용이 없는 경우이며, 그렇지 않으면 in place 하지 않다고 이야기 한다.

결론적으로 보면, 
	* 
merge sort는 stable 하나 in place 하지 않음, space complexity가 O(n) 이다.
	* 
quick sort는 stable 하지 않다 - worst time complexity가 O(n^2) 이나 randomized quick sort를 구현하면 O(nlongn)에 가깝게 구현 가능 하며, merge sort 와 다르게 extra space 가 필요치 않다.



마지막으로, 비교 형 Sorting 알고리즘의 time complexity 한계가  O(nlogn) 이지만,  non 비교형이 Sorting 알고리즘을 활용하면  (counting sorting 혹은 heap 을 사용한 sorting 알고리즘) 은  O(n) 까지 개선 시킬 수도 있다.

따라서, 결국은 내가 Sorting 하려는 data가 어떤 것인지, 그리고 이들을 sorting 할 때 필요한 제약사항이 무엇인지를 명확하게 이해하고 실제 적용 가능한 알고리즘 중에서 어떤 형태가 좋은지 파악 하는게 필요하다. Code Reviewer 관점에서 다시 보기
우리가 추구하는 코드리뷰는 CleanCode 관점에서 코드의 maintainability 와 readability 를 향상시키고 높은 상태로 유지하는 것이 목표 이다. 여기에, 추가로 코드의 성능을 체크하는 방법인 Time Complexity와 Space Complexity를 잘 활용한다면 순수하게 Software 적인 관점에서 성능에 영향을 주는 부분 까지 찾아내고 리뷰 할 수 있을 것 같다.

최종 적으로는 아래의 4가지 정도를 고려하면서 Code review를 할 수 있을 것으로 보인다.

1) 함수의 input의 size가 커짐에 따른 함수의 수행시간 증가 정도
2) 함수의 input의 size가 커짐에 따른 함수 수행을 위한 메모리 사용량(stack 과 heap size) 증가 정도
3) 함수내 코드 중 Time complexity(성능)에 가장 영향을 주는 부분이 어느 것인지 파악 하고, 그 부분을 개선 하는 방법 찾기
    (reviewee와 확인을 통한 가용 가능한 stack 과 heap size의 정도를 이해하고, 해당 범위 내에서 space complexity를 희생하여 time complexity(성능)을 높이도록)
4) 코드 상에 라이브러리를 활용하는 경우, time complexity 는 어떻게 활용 되는지 이해하기

참고문헌
한글
https://blog.naver.com/yhyang_hae/221259342434

점근적표기법: https://blog.naver.com/tpwls345/221377883969
시간복잡도 vs 공간복잡도: https://blog.naver.com/tpwls345/221377881710

영문
Algorithm and Data Structure
1) https://www.youtube.com/watch?v=aGjL7YXI31Q&list=PLEbnTDJUr_IeHYw_sfBOJ6gk5pie0yP-0

Big-O notation 소개: 
1) https://www.youtube.com/watch?v=D6xkbGLQesk
2) http://youtube.com/watch?v=aGjL7YXI31Q

Time & Space complexity of Algorithm
1) http://bigocheatsheet.com/
2) https://stackoverflow.com/questions/11032015/how-to-find-time-complexity-of-an-algorithm

Code example: https://stackoverflow.com/questions/13467674/determining-complexity-for-recursive-functions-big-o-notation

Stable vs Unstable Sorting Algorithm: https://www.youtube.com/watch?v=ClG4xjwQ0BM
In place Sorting Algorithm:  https://www.youtube.com/watch?v=SCUYnQxZsPE
