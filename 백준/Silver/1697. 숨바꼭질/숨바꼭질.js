const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

const [m, n] = input[0].split(" ").map(Number);

var visited = Array.from({ length: 100001 }).fill(0);

var queue = [];
queue.push([m, 0]);
visited[m] = 1;

while (queue.length !== 0) {
  let [x, time] = queue.shift();
  if (x == n) {
    console.log(0);
    break;
  }
  let a = x + 1;
  let b = x - 1;
  let c = 2 * x;

  if (a === n || b === n || c == n) {
    time++;
    console.log(time);
    break;
  }

  if (!visited[a] && a >= 0 && a <= 100000) {
    queue.push([a, time + 1]);
    visited[a] = 1;
  }
  if (!visited[b] && b >= 0 && b <= 100000) {
    queue.push([b, time + 1]);
    visited[b] = 1;
  }
  if (!visited[c] && c >= 0 && c <= 100000) {
    queue.push([c, time + 1]);
    visited[c] = 1;
  }
}