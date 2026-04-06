var count = 0;

function dfs(x, y) {
  for (let i = 0; i < 4; i++) {
    let xPos = x + dx[i];
    let yPos = y + dy[i];

    if (
      xPos >= 0 &&
      xPos < m &&
      yPos >= 0 &&
      yPos < m &&
      !visited[xPos][yPos] &&
      graph[xPos][yPos]
    ) {
      visited[xPos][yPos] = 1;
      count++;
      dfs(xPos, yPos);
    }
  }
}

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const m = Number(input[0]);
const graph = input
  .slice(1, 1 + Number(m))
  .map((line) => line.trim().split("").map(Number));

var visited = Array.from({ length: Number(m) }, () => Array(Number(m)).fill(0));
const dx = [0, 0, -1, 1];
const dy = [-1, 1, 0, 0];

var total = 0;
var answer = [];

for (let i = 0; i < m; i++) {
  for (let j = 0; j < m; j++) {
    if (!visited[i][j] && graph[i][j] == 1) {
      visited[i][j] = 1;
      count++;
      dfs(i, j);
    }
    if (count !== 0) {
      answer.push(count);
      total++;
    }
    count = 0;
  }
}

answer.sort((a, b) => a - b);
console.log(total);

answer.forEach((count) => {
  console.log(count);
});