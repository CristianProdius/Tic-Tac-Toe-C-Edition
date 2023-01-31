#include <iostream>
#include <iomanip>

/*This function checks the entire
gameboard to see if there are any
winning rows/columns/diagonals.
It returns true if there is a winning
configuration. Otherwise it returns
false.
*/
bool checkBoard(char board[][3]){
    bool row_check = true;
    bool col_check = true;
    char temp;

    //Check X's on diagonals
    if((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')){
        return true;
    }
    //Check O's on diagonals
    else if((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')){
        return true;
    }


    //Check rows
    for(int r = 0; r < 3; r++){
        temp = board[r][0];
        row_check = true;
        for(int c = 0; c < 3; c++){
            if((board[r][c] != temp) || (board[r][c] == '-')){
                row_check = false;
            }
        }
        if(row_check){
            return true;
        }
    }

    //Check columns
    for(int c = 0; c < 3; c++){
        temp = board[0][c];
        col_check = true;
        for(int r = 0; r < 3; r++){
            if((board[r][c] != temp) || (board[r][c] == '-')){
                col_check = false;
            }
        }
        if(col_check){
            return true;
        }
    }
    return false;
}

/*This function prints the
gameboard
*/
void printBoard(char board[][3]){
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            std::cout << std::setw(2) << board[r][c];
        }
        std::cout << std::endl;
    }
}

int main(){
    bool gameOver = false;
    int row = 1;
    int col = 1;
    char players[2] = {'X', 'O'};
    int numTurns = 0;

    //Initialize gameboard with emtpy '-'
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    std::cout << "Welcome to the game of tic-tac-toe\nEnter '0' for row if you want to quit" << std::endl;
    do{
        //Using modulus to cycle between players
        std::cout << players[numTurns%2] << "'s turn" << std::endl;
        std::cout << "Current Game Board:" << std::endl;
        printBoard(board);
        std::cout << "Enter Row: ";
        std::cin >> row;
        
        //Exit if the player entered '0' for row
        if(row == 0){
            exit(0);
        }
        std::cout << "Enter Col: ";
        std::cin >> col;

        //Check to see if the player chose a valid position
        while((board[row-1][col-1] != '-') || (row > 3) || (col > 3)){
            std::cout << "Invalid choice, please choose again" << std::endl;
            std::cout << "Enter Row: ";
            std::cin >> row;
            
            //Once again exit the player entered '0' for row
            if(row == 0){
                exit(0);
            }
            std::cout << "Enter Col: ";
            std::cin >> col;
        }
        //Assign X or O to the correct spot on the board
        board[row-1][col-1] = players[numTurns%2];
        
        //Check if game was won and increment the number of turns
        gameOver = checkBoard(board);
        numTurns++;
    }
    while(!gameOver && row != 0 && col != 0 && numTurns < 9);
    

    //Print the final board and check one last time to see if
    //somebody won or whether it was a draw
    printBoard(board);
    gameOver = checkBoard(board);
    if(gameOver){
        std::cout << players[(numTurns+1)%2] << "'s win!" << std::endl;
        std::cout << "Game won after " << numTurns << " Turns" << std::endl;
    }
    else{
        std::cout << "Game ended in Draw" << std::endl;
    }
    
    return 0;

}