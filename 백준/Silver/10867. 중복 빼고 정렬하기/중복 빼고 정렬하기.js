const readline = require('readline')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

let n;
let input = [];
let count = 0;
rl.on("line", function(line) {
    if (count == 0)
        n = Number(line.trim()); // 첫 줄 : 정수 하나만 입력 받음 (N)
    else if (count == 1) {
        input.push(...line.split(' ').map(Number));
        if (input.length >= n)
            rl.close();
    }
    count++;
})

rl.on("close", function() {
    const sortedArr = [...new Set(input)].sort((a, b) => a - b);
    // [...new Set(input)] : Set은 sort, map 등의 배열 메서드 사용 X -> 다시 배열로 변경해줌
    // (a, b) => a - b : 숫자 정렬을 위한 비교 함수
        // a - b > 0 => a > b => a가 뒤로 감
        // a - b < 0 => a < b => b가 뒤로 감
        // a - b = 0 => a = b => 순서 변경 X
    console.log(sortedArr.join(' '));  // 배열의 요소들을 공백으로 구분하여 출력
})
