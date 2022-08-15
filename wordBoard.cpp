#include <stdio.h>
int main()
{
      printf("<script language=\"JavaScript\">

var nl = getNewLine()

function getNewLine() {
	var agent = navigator.userAgent

	if (agent.indexOf(\"Win\") >= 0)
		return \"\r\n\"
	else
		if (agent.indexOf(\"Mac\") >= 0)
			return \"\r\"

 	return \"\r\"

}

pagecode = 'var exist = function (board, word) {
    if (board.length === 0) {
        return false
    }

    let r = board.length;
    let c = board[0].length;
    const dirs = [[-1, 0], [0, 1], [1, 0], [0, -1]];
    
    const dfs = (x, y, k) => {
        if (board[x][y] !== word[k]) {
            return false;
        }
        if (k === word.length - 1) {
            return true;
        }
        board[x][y] = \'*\';
        for (const [dx, dy] of dirs) {
            const i = x + dx;
    const j = y + dy;

            if (i >= 0 && i < r && j >= 0 && j < c) {
                if (dfs(i, j, k + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = word[k];
        return false;
    }

    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

board = [[\"A\",\"B\",\"C\",\"E\"],[\"S\",\"F\",\"C\",\"S\"],[\"A\",\"D\",\"E\",\"E\"]], word = \"ABCCED\"

console.log(exist(board,word));'

document.write(pagecode);

</script>\n");
      return 0;
}
