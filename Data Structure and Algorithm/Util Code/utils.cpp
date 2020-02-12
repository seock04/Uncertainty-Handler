
// this file contain a few util code that is good to remember for the algorithm exam or coding interview

void IntToArray(int n, int numbers[], int &len)
{
	if (n == 0) return;
	int i = 0;
	while (n) {
		i = n % 10;
		numbers[len++] = i;
		n /= 10;
	}
}

bool IsPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}


int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a < b ? b : a; }

void SWAP(int& a, int& b) { int t = a; a = b; b = t; }

int mABS(int v) { return v < 0 ? -v : v; }

int mStrlen(char str[])
{
	int idx = 0;
	while (str[idx] != '\0') idx++;
	return idx;
}


void quicksort(int arr[], int left, int right)
{
	int pivot;
	int i, j;

	if (left < right) {
		pivot = left;
		i = left;
		j = right;

		while (i < j) {
			while (arr[i] <= arr[pivot] && i < right) i++;
			while (arr[j] > arr[pivot]) j--;

			if (i < j) {
				SWAP(arr[i], arr[j]);
			}
		}
		SWAP(arr[pivot], arr[j]);

		quicksort(arr, left, j - 1);
		quicksort(arr, j + 1, right);
	}

}


//int Ceiling(float v)
//{
//	int a = v;
//	if ((float)a != v)
//		return v + 1;
//	return a;
//}
