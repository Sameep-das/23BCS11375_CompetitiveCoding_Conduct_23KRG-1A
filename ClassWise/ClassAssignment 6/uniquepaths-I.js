"use strict";
function uniquePaths(rows, cols) {
  let dp = new Array(rows);
  for (let i = 0; i < rows; ++i) {
    dp[i] = new Array(cols).fill().map(() => 0);
  }

  for (let i = 1; i < rows; ++i) {
    dp[i][0] = 1;
  }
  for (let i = 1; i < cols; ++i) {
    dp[0][i] = 1;
  }
  for (let i = 1; i < rows; ++i) {
    for (let j = 1; j < cols; ++j) {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]) + 1;
    }
  }
  return dp[rows - 1][cols - 1];
}
console.log(uniquePaths(8, 8));
