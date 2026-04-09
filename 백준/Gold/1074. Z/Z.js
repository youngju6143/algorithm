const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [n, r, c] = input[0].trim().split(" ").map(Number);

function z(level, row, col) {
  if (level === 0) return 0;
  let half = 2 ** (level - 1);
  let area = half * half;

  if (row < half && col < half) return z(level - 1, row, col);
  else if (row < half && col >= half)
    return area + z(level - 1, row, col - half);
  else if (row >= half && col < half)
    return 2 * area + z(level - 1, row - half, col);
  else return 3 * area + z(level - 1, row - half, col - half);
}

console.log(z(n, r, c));