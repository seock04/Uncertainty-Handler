class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		set<pair<int, int>> ss;

		int N = mat.size();
		for (int i = 0; i < mat.size(); i++) {
			int strength = 0;
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 1) strength += 1;
			}
			ss.insert(make_pair(strength, i));
		}

		vector<int> res;

		for (int i = 0; i < k; i++) {
			res.push_back(ss.begin()->second);
			ss.erase(ss.begin());
		}

		return res;
	}
};
