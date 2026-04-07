"use strict";
function uniquePaths(rows, cols) {
  let dp = new Array(rows);
  for (let i = 0; i < rows; ++i) {
    dp[i] = new Array(cols).fill().map(() => 0);
  }

  for (let i = 1; i < rows; ++i) {
    if (obstacles.some(([x, y]) => x === i && y === 0)) {
      dp[i][0] = 0;
      continue;
    }
    dp[i][0] = 1;
  }
  for (let i = 1; i < cols; ++i) {
    if (obstacles.some(([x, y]) => x === 0 && y === i)) {
      dp[0][i] = 0;
      continue;
    }
    dp[0][i] = 1;
  }
  for (let i = 1; i < rows; ++i) {
    for (let j = 1; j < cols; ++j) {
      if (obstacles.some(([x, y]) => x === i && y === j)) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[rows - 1][cols - 1];
}
const obstacles = [
  [1, 1],
  [2, 0],
];
console.log(uniquePaths(3, 3));
