function solution(genres, plays) {
  var songTable = [];
  var sumTable = [];

  genres.map((genre) => {
    if (sumTable.find((element) => element.genre == genre) === undefined)
      sumTable.push({ genre: genre, play: 0 });
  });

  for (let i = 0; i < plays.length; i++) {
    songTable.push({
      id: i,
      genre: genres[i],
      play: plays[i],
    });

    sumTable.forEach((a) => {
      if (a.genre == genres[i]) a.play += plays[i];
    });
  }

  sumTable.sort((a, b) => b.play - a.play);
  songTable.sort((a, b) => b.play - a.play);

  console.log(sumTable);
  console.log(songTable);
  var answer = [];

  sumTable.forEach((element) => {
    let cnt = 0;
    songTable.forEach((song) => {
      if (cnt < 2 && song.genre == element.genre) {
        answer.push(song.id);
        console.log(cnt);
        cnt += 1;
      }
    });
  });
  return answer;
}