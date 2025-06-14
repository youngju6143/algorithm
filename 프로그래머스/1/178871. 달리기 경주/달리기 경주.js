function solution(players, callings) {
  const playerIndex = {};
  players.forEach((player, idx) => {
    playerIndex[player] = idx;
  });

  callings.forEach((player) => {
    const index = playerIndex[player];
    if (index > 0) {
      [players[index - 1], players[index]] = [
        players[index],
        players[index - 1],
      ];
      playerIndex[players[index]] = index;
      playerIndex[players[index - 1]] = index - 1;
    }
  });
  return players;
}