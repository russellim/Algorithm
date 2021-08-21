// table에서 도형들 분리한 뒤, 배열에 넣어줌. (좌표), 블록 갯수도 저장.
// game_board 탐색하면서 빈칸 만나면 그 빈칸 갯수만큼의 도형을 대조함.
// 맞는 도형이 있으면 도형의 블록 갯수만큼 반환하고 해당 도형 삭제.
//figure is [x,y]

function compareFigure(fig1, fig2, blockCount){
    for(let i=0; i<blockCount; ++i){
        if(fig1[i] != fig2[i])
            return false;
    }
    return true;
}

// 블록 회전하기.
function turnFigure(fugure){
    
}

// BFS 이용해서 [블록 갯수, ...도형 분리] 저장.
function makeFigure(board, startRow, startCol, findNumber){
    var res = [];
    var count = 0;
    
    figure.push(figure);
    figure.push(count);
}

function solution(game_board, table) {
    var answer = -1;
    var boardSize = game_board.length;
    var gameFigures = [];
    var tableFigures = [];
    
    for(let row = 0; row < boardSize; ++row){
        for(let col = 0; col < boardSize; ++col){
            if(game_board[row][col] === 0)
                gameFigures.push(makeFigure(game_board, row, col, 0));
            if(table[row][col] === 1)
                tableFigures.push(makeFigure(table, row, col, 1));
        }
    }
    
    // sort block size asc
    
    // 블록 개수 같은 것 끼리 비교해보기.
    
    return answer;
}
