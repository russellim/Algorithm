// table에서 도형들 분리한 뒤, 배열에 넣어줌. (좌표), 블록 갯수도 저장.
// game_board 탐색하면서 빈칸 만나면 그 빈칸 갯수만큼의 도형을 대조함.
// 맞는 도형이 있으면 도형의 블록 갯수만큼 반환하고 해당 도형 삭제.
//figure is [x,y]

class Queue{
    constructor() { this._arr = []; }
    push(item) { this._arr.push(item); }
    pop() { return this._arr.shift(); }
}

function compareFigure(fig1, fig2, blockCount){
    for(let i=0; i<blockCount; ++i){
        if(fig1[i] != fig2[i])
            return false;
    }
    return true;
}

// 블록 회전하기. (왼쪽으로 90도)
function turnFigure(figure = []){
    let maxCol = 0;
    figure.forEach(coord => {
        if(maxCol < coord[1])
            maxCol = coord[1];
    });
    return figure.map(coord => [maxCol - coord[1], coord[0]]);
}

function isRange(size, row, col){
    return (row >= 0 && col >= 0 && row < size && col < size);
}

var direction = [[1, 0], [0, 1], [-1, 0], [0, -1]];
// BFS 이용해서 [블록 갯수, ...도형 분리] 저장.
function makeFigure(board, startRow, startCol, findNumber){
    let res = [];
    let figure = [];
    let count = 0;
    
    let q = new Queue();
    q.push([startRow, startCol]);
    figure.push([0, 0]);
    board[startRow][startCol] = 1 - findNumber;
    ++count;

    while(q.length != 0){
        let nowPos = q.pop();

        for(let d=0; d<4; ++d){
            let nextPos = [newPos[0] + direction[d][0], newPos[1] + direction[d][1]];
            if(!isRange(board.length, nextPos[0], nextPos[1])) continue;
            if(board[nextPos[0]][nextPos[1]] != findNumber) continue;
            q.push(nextPos);
            figure.push([nextPos[0] - startRow, nextPos[1] - startCol]);
            board[nextPos[0]][nextPos[1]] = 1 - findNumber;
            ++count;
        }
    }

    res.push(count);
    res.push(figure);
}

function solution(game_board, table) {
    var answer = -1;
    var boardSize = game_board.length;
    var tableFigures = [];
    
    for(let row = 0; row < boardSize; ++row){
        for(let col = 0; col < boardSize; ++col){
            if(table[row][col] === 1)
                tableFigures.push(makeFigure(table, row, col, 1));
        }
    }
    
    // sort block size asc
    
    // 블록 개수 같은 것 끼리 비교해보기.
    
    return answer;
}
