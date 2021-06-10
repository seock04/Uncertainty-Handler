typedef struct
{
	int v;
}Hash;
Hash tb2[MAX_TABLE];

unsigned long mhash(int arr)
{
	unsigned long hash = 5381;
	int c;
	while (c = arr % 10)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
		arr = arr / 10;
	}
	hash = hash % MAX_TABLE;

	while (tb2[hash].v != -1) // -1 is default value
	{
		if (tb2[hash].v == arr) return hash;
		hash = (hash + 1) % MAX_TABLE;
	}
	return hash;
}
