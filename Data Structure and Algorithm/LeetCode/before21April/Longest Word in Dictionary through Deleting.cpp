class Solution {
public:
    string findLongestWord(string sources, vector<string>& d) {

        sort(d.begin(), d.end());
        vector<int> len(d.size(), 0);

        for (int i = 0; i < d.size(); i++) {
            if (sources.length() < d[i].length()) continue;

            int is = 0;
            for (int j = 0; j < sources.length(); j++) {
                if (sources[j] == d[i][is]) {
                    is++;
                }
            }
            if (is == d[i].length()) {
                len[i] = is;
            }
        }

        int longest_idx = -1;
        int longest_val = 0;
        for (int i = 0; i < len.size(); i++) {
            if (len[i] > longest_val) {
                longest_val = len[i];
                longest_idx = i;
            }
        }

        if (longest_idx == -1) return "";
        return d[longest_idx];
    }
};
