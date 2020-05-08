#include <iostream>

using namespace std;

int H, W;
int ans = 0;
void solve(int h, int w)
{
	if (h > H || w > W) return;
	if (h == H && w == W) {
		++ans;
		return;
	}

	solve(h + 1, w);
	if ((double)H / W <= (double)h / (w + 1)) {
		solve(h, w + 1);
	}
}
int DT[110][110];

int IsAvailable(int h, int w)
{
	if (0 == w) return 1;
	int ans = (double)H / W <= (double)h / w;
	return ans;
}

int solve2(int h, int w)
{
	if (h > H || w > W || IsAvailable(h,w)<1) 
 		return 0;
	if (h == H && w == W) {
 		return 1;
	}	
	return solve2(h + 1, w) + solve2(h, w + 1);
}

int betterSolution_DT(int h, int w)
{
	if (DT[h][w] == 0) {
		if (h > H || w > W || !IsAvailable(h, w)) DT[h][w] = 0;
		else if (h == H && w == W) {
			DT[h][w] = 1;
		}
		else DT[h][w] = betterSolution_DT(h + 1, w) + betterSolution_DT(h, w + 1);
	}
	return DT[h][w];
}

int main()
{
	cin >> H >> W;
	//exhaustive way
	//solve(0,0);
	//cout << ans;

	//cout << solve2(0, 0);
	cout << betterSolution_DT(0, 0) << endl;
	return 0;
}