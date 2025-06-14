function hanoi(n, start, last, mid, arr) {
  if (n == 1) {
    arr.push([Number(start), Number(last)]);
    return;
  } else {
    hanoi(n - 1, start, mid, last, arr);
    arr.push([Number(start), Number(last)]);
    hanoi(n - 1, mid, last, start, arr);
  }
}

function solution(n) {
  const arr = [];
  hanoi(n, "1", "3", "2", arr);
  return arr;
}