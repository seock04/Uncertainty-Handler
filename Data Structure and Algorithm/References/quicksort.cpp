/*
1 // number of Test cases
5 // Data size
1 4 5 2 3
*/

#include <stdio.h>

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;
	
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (input[i] <= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] > input[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;

    int l = left;
    int r = right;
    int pivot = left;
    while (l < r) {
        while (nums[l] <= nums[pivot] and l < right) l++;
        while (nums[r] > nums[pivot]) r--;
        if (l < r) {
            swap(nums[l], nums[r]);
        }
    }
    swap(nums[pivot], nums[r]);

    quickSort(nums, left, r - 1);
    quickSort(nums, r + 1, right);
}
    
void printResult(void)
{
	int i;

	for (i = 0; i < num; ++i)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
}

int main(void)
{
	int T;
	int test_case;
	int i;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &num);
		for (i = 0; i < num; i++)
		{
			scanf("%d", &input[i]);
		}
		quickSort(0, num - 1);
		printf("#%d ", test_case);
		printResult();
	}

	return 0;
}
