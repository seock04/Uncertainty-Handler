#define MAX_SIZE 100001
struct Item {
	int num;
	int count;
};
 Item heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(Item value)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap[heapSize] = value;

	int current = heapSize;
	while (current > 0 && heap[current].count > heap[(current - 1) / 2].count)
	{
		Item temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop(Item* value)
{
	if (heapSize <= 0)
	{
		return -1;
	}

	*value = heap[0];
	heapSize = heapSize - 1;

	heap[0] = heap[heapSize];

	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = heap[current * 2 + 1].count > heap[current * 2 + 2].count ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current].count > heap[child].count)
		{
			break;
		}

		Item temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
	}
	return 1;
}

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k == nums.size()) return nums;
        heapInit();
        ///*using map
		unordered_map<int, int> mp;        
        for(int n : nums) mp[n]++;
		for (auto p : mp) {
			heapPush({ p.first, p.second });
		}
		//using map end */
        /*
        sort(nums.begin(), nums.end
        int x = nums[0], n = nums.size(), pos = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] != x){
                heapPush({x, i-pos});
                x = nums[i];
                pos = i;
            }
        }
        heapPush({ nums[n-1], n - pos });
        */
		vector<int> res;
		Item item;
		for (int i = 0; i < k; ++i) {
			res.push_back(heap[0].num);
			heapPop(&item);
		}

		return res;
	}
};
