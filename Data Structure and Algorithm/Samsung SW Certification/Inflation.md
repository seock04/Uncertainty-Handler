inflation

Condition
* 50 - * * items
* 3000 * max duration for each item
* 1000 api max call
* price length - 99

Functions
* init(int N, char name[][], char prices[][], int duration[])
* changePrices(char name[], char prices[])
* int getDurations(char price[])

Examples)
1) Init()
* A 1000 5
* B 5000 10
* C 3000 3

2) getDurations(10000)
* A + B + C = 9000
* = return minDuration(5, 10, 3) = 3 

3) getDurations(12000)
* A + B + 2C = 12000
* = return minDuration(5, 10, 6) =  5
