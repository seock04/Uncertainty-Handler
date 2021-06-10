#include<iostream>
 
using namespace std;
 
#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096
 
typedef struct
{
    char key[MAX_KEY + 1];
}Hash;
Hash tb[MAX_TABLE];
 
int mstrcmp(const char* a, const char* b)
{
    int index = 0;
    while (b[index] != '\0') {
        if (a[index] != b[index]) return -1;
        ++index;
    }
    if (a[index] != '\0') return -1;
    return 0;
}
 
void mstrcpy(char* dst, const char* src)
{
    int index = 0;
    while (src[index] != '\0') {
        dst[index] = src[index];
        ++index;
    }
    dst[index] = '\0';
}
 
 
unsigned long mhash(const char *str)
{
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
    {
        hash = (((hash << 5) + hash) + c) % MAX_TABLE;
    }
    hash = hash % MAX_TABLE;
 
    while (tb[hash].key[0] != 0)
    {
        if (mstrcmp(tb[hash].key, str)) return hash;
        hash = (hash + 1) % MAX_TABLE;
    }
    return hash;
}
 
int main()
{
    unsigned long h = mhash("abc");
    mstrcpy(tb[h].key, "abc");
    h = mhash("abc");
 
    return 0;
}
