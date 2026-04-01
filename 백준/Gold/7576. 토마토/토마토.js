const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [m, n] = input[0].split(" ").map(Number);

var tomatoes = input.slice(1).map((line) => line.split(" ").map(Number));
var count = tomatoes.flat().filter((v) => v === 0).length;

const dx = [0, 0, -1, 1];
const dy = [-1, 1, 0, 0];

function solution() {
  let answer = 0;
  let index = 0;
  const queue = [];

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (tomatoes[i][j] === 1) {
        queue.push([i, j, 0]);
      }
    }
  }

  while (index < queue.length) {
    let [x, y, day] = queue[index];
    answer = day;
    for (let i = 0; i < 4; i++) {
      let xPos = x + dx[i];
      let yPos = y + dy[i];
      if (
        xPos < n &&
        xPos >= 0 &&
        yPos < m &&
        yPos >= 0 &&
        tomatoes[xPos][yPos] === 0
      ) {
        tomatoes[xPos][yPos] = 1;
        queue.push([xPos, yPos, day + 1]);
        count--;
      }
    }
    index++;
  }
  if (count !== 0) return -1;
  return answer;
}

console.log(solution());