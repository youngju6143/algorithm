function solution(n, w, num) {
  var answer = 0;
  var startRow = 0;
  var col = 0;
  var boxes = [];
  var current = 1;
  var row = [];
  for (let i = 0; i < n / w; i++) {
    for (let j = current; j < current + w; j++) {
      if (j > n) row.push(0);
      else row.push(j);
    }
    if (i % 2 != 0) row.reverse();
    boxes.push(row);
    row = [];
    current += w;
  }
  for (let i = 0; i < boxes.length; i++) {
    if (boxes[i].includes(num)) {
      col = boxes[i].indexOf(num);
      startRow = i;
      break;
    }
  }

  for (let i = startRow; i < boxes.length; i++) {
    if (boxes[i][col] != 0) answer++;
  }

  return answer;
}