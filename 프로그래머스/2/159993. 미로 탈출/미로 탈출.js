function bfs(maps, start, target) {
  const dx = [0, 0, -1, 1];
  const dy = [-1, 1, 0, 0];

  const col = maps.length;
  const row = maps[0].length;

  var queue = [];
  var visited = Array.from({ length: col }, () => Array(row).fill(false));

  queue.push([start[0], start[1], 0]);
  visited[start[0]][start[1]] = true;

  while (queue.length) {
    const [x, y, dist] = queue.shift();

    if (x === target[0] && y === target[1]) return dist;

    for (let i = 0; i < 4; i++) {
      const xpos = x + dx[i];
      const ypos = y + dy[i];

      if (
        xpos >= 0 &&
        xpos < col &&
        ypos >= 0 &&
        ypos < row &&
        !visited[xpos][ypos] &&
        maps[xpos][ypos] !== "X"
      ) {
        visited[xpos][ypos] = true;
        queue.push([xpos, ypos, dist + 1]);
      }
    }
  }
  return -1;
}

function solution(maps) {
  var start = [0, 0];
  var lever = [0, 0];
  var exit = [0, 0];

  for (let i = 0; i < maps.length; i++) {
    for (let j = 0; j < maps[i].length; j++) {
      let pos = maps[i][j];
      if (pos == "S") start = [i, j];
      if (pos == "L") lever = [i, j];
      if (pos == "E") exit = [i, j];
    }
  }

  const toLever = bfs(maps, start, lever);
  if (toLever === -1) return -1;

  const toExit = bfs(maps, lever, exit);
  if (toExit === -1) return -1;

  return toLever + toExit;
}