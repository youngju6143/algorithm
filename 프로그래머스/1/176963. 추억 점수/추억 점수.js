function solution(name, yearning, photo) {
  const object = {};

  name.forEach((element, index) => {
    object[element] = yearning[index];
  });

  var answer = new Array(photo.length).fill(0);

  for (let i = 0; i < photo.length; i++) {
    for (let j = 0; j < photo[i].length; j++) {
      if (object[photo[i][j]]) answer[i] += object[photo[i][j]];
    }
  }

  return answer;
}