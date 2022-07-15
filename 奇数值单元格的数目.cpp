class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> rows(m, 0);

        vector<int> cols(n, 0);

        for(int i = 0; i < indices.size(); i++) {
            rows[indices[i][0]]++;
            cols[indices[i][1]]++;
        }

        int evenRows = 0;
        int evenCols = 0;
        for(int i = 0; i < m; i++) {
            if(rows[i] % 2 == 0)
                evenRows++;

        }

        for(int i = 0; i < n; i++) {
            if(cols[i] % 2 == 0)
                evenCols++;
        }

        return evenRows * (n - evenCols) + (m - evenRows) * evenCols;
    }
};