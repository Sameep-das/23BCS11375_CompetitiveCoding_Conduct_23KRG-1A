function travellingSalesmanProb(cities, costs) {
  const n = cities.length;

  let dp = new Array(1 << n)
    .fill()
    .map(() => new Array(n).fill(Number.MAX_VALUE));

  dp[1][0] = 0;

  for (let mask = 0; mask < 1 << n; mask++) {
    for (let i = 0; i < n; i++) {
      if (dp[mask][i] === Number.MAX_VALUE) continue;

      for (let j = 0; j < n; j++) {
        if ((mask & (1 << j)) !== 0) continue;

        const newMask = mask | (1 << j);
        dp[newMask][j] = Math.min(dp[newMask][j], dp[mask][i] + costs[i][j]);
      }
    }
  }
  let ans = Number.MAX_VALUE;
  for (let i = 0; i < n; i++) {
    ans = Math.min(ans, dp[(1 << n) - 1][i] + costs[i][0]);
  }

  return ans;
}

let cities = ["A", "B", "C", "D"];
let costs = [
  [0, 10, 15, 20],
  [5, 0, 9, 10],
  [6, 13, 0, 12],
  [8, 8, 9, 0],
];
console.log(travellingSalesmanProb(cities, costs));
