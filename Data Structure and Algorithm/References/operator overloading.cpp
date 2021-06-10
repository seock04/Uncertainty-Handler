struct item {
    int v;
    int vv;
};
 
void SWAP(item a, item b)
{
    item t = a;
    a = b;
    b = t;
}
 
bool operator<=(item a, item b)
{
    return a.v <= b.v;
}
 
bool operator>(item a, item b)
{
    return a.v > b.v;
}
 
void quickSort(item input[], int first, int last)
{
    int pivot;
    int i;
    int j;
    item temp;
 
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
 
        quickSort(input, first, j - 1);
        quickSort(input, j + 1, last);
    }
}
 
 
int main()
{
    item it[5] = { {1,2}, {2,4}, {5,1}, {3,3}, {5,5 } };
    quickSort(it, 0, 4);
    for (item itr : it) {
        cout << itr.v;
    }
    return 0;
}
