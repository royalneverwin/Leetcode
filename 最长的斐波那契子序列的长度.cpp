class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int l = arr.size();
        int bp[l][l]; // bp[i][j]表示第i个和第j个数形成F的子序列长度 i < j
        unordered_map<int, int> umap;
        for(int i = 0; i < l; i++) {
            for(int j = i+1; j < l; j++) {
                bp[i][j] = 2;
            }
            umap[arr[i]] = i;
        }
        int ans = 2;
        for(int j = l-2; j >= 1; j--) {
            for(int i = j-1; i >= 0; i--) {
                if(umap.count(arr[i]+arr[j])) {
                    int k = umap[arr[i]+arr[j]];
                    bp[i][j] = max(bp[i][j], bp[j][k]+1);
                    ans = max(ans, bp[i][j]);
                }
            }
        }
        return ans==2?0:ans;
    }
};