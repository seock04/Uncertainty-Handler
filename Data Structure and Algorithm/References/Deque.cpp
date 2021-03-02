/* Deque 는 Queue 의 일반화 된 버전으로 Queue 의 양 끝에서 데이터의 삽입 /삭제가 가능하게끔 만든 자료구조이다. 크기가 N 인 Queue 에서 주어진 M 개의 Command 를 수행하는 프로그램을 작성하라. 각각의 Command는 1~6 사이의 정수값을 가지며, 다음과 같은 동작을 수행한다. 1 : front 에 element 삽입 2 : rear 에 element 삽입 3 : front 에 있는 element 출력 4 : rear 에 있는 element 출력 5 : front 에 있는 element 삭제 6 : rear 에 있는 element 삭제 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 100

int arr[MAX];
int front;
int rear;
int size;

void dequeInit(int n) {
	front = -1;
	rear = 0;
	size = n;
}

bool isFull() {
	return ((front == 0 && rear == size - 1) || front == rear + 1);
}

bool isEmpty() {
	return (front == -1);
}

void insertFront(int value) {
	if (isFull()) {
		printf("Overflow\n");
	}

	if (front == -1) {
		front = rear = 0;
	}
	else if (front == 0) {
		front = size - 1;
	}
	else {
		front = front - 1;
	}

	arr[front] = value;
}

void insertRear(int value) {
	if (isFull()) {
		printf("Overflow\n");
	}

	if (front == -1) {
		front = rear = 0;
	}
	else if (rear == size - 1) {
		rear = 0;
	}
	else {
		rear = rear + 1;
	}

	arr[rear] = value;
}

int getFront() {
	if (isEmpty()) {
		printf("Underflow\n");
		return -1;
	}
	return arr[front];
}

int getRear() {
	if (isEmpty() || rear < 0) {
		printf("Underflow\n");
		return -1;
	}
	return arr[rear];
}

void deleteFront() {
	if (isEmpty()) {
		printf("Underflow\n");
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == size - 1) {
		front = 0;
	}
	else {
		front = front + 1;
	}
}

void deleteRear() {
	if (isEmpty()) {
		printf("Underflow\n");
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (rear == 0) {
		rear = size - 1;
	}
	else {
		rear = rear - 1;
	}
}

int main(void) {

	int T, N, M;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {

		scanf("%d%d", &N, &M);

		dequeInit(N);

		printf("#%d ", test_case);

		for (int i = 0; i < M; ++i) {
			
			int cmd, elem;

			scanf("%d", &cmd);

			switch (cmd) {
			case 1:
				scanf("%d", &elem);
				insertFront(elem);
				break;
			case 2:
				scanf("%d", &elem);
				insertRear(elem);
				break;
			case 3:
				printf("%d ", getFront());
				break;
			case 4:
				printf("%d ", getRear());
				break;
			case 5:
				deleteFront();
				break;
			case 6:
				deleteRear();
				break;
			}
		}

		printf("\n");
	}

	return 0;
}
