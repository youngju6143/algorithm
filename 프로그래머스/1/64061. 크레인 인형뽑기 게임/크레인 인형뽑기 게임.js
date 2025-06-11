function solution(board, moves) {
  const stack = [0];
  let answer = 0;
  for (let i = 0; i < moves.length; i++) {
    const idx = moves[i] - 1;
    for (let j = 0; j < board.length; j++) {
      if (board[j][idx] === 0) {
        continue;
      } else {
        const top = stack[stack.length - 1];
        if (top == board[j][idx]) {
          stack.pop();
          answer += 2;
        } else {
          stack.push(board[j][idx]);
        }
        board[j][idx] = 0;

        break;
      }
    }
  }
  return answer;
}