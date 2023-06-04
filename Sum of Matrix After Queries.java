class Solution {
    public long matrixSumQueries(int n, int[][] queries) {
        long sum = 0;
        int row = 0, col = 0;
        HashSet<Integer> setRow = new HashSet<>();
        HashSet<Integer> setCol = new HashSet<>();

        for (int i = queries.length - 1; i >= 0; i--) {
            if (queries[i][0] == 0) {
                if (setRow.contains(queries[i][1])) {
                    continue;
                } else {
                    sum += (n - col) * queries[i][2];
                    row += 1;
                    setRow.add(queries[i][1]);
                }
            } else {
                if (setCol.contains(queries[i][1])) {
                    continue;
                } else {
                    sum += (n - row) * queries[i][2];
                    col += 1;
                    setCol.add(queries[i][1]);
                }
            }
        }

        return sum;
    }
}
