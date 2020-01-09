public class board implements global
{
    public block[][] grid = new block[3][3];
    private int state = EMPTY;

    /**
     * Description: default constructor for the board class
     * Input: n/a
     * Output: instantiates a 3x3 grid of block objects
     */
    public board()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                grid[i][j] = new block();
            }
        }
    }

    /**
     * Description: handles the move made by the player
     * @param location holds the location of the move
     * @param move holds the value of the move (X or O)
     * Output: returns true if the move was successfully made, returns false otherwise
     */
    public boolean makeMove(int location, int move)
    {
        int row, column;

        // Set the row and column values according to the location where the player wishes to make their move
        switch(location)
        {
            case 1:
                row = 0;
                column = 0;
                break;

            case 2:
                row = 0;
                column = 1;
                break;

            case 3:
                row = 0;
                column = 2;
                break;

            case 4:
                row = 1;
                column = 0;
                break;

            case 5:
                row = 1;
                column = 1;
                break;

            case 6:
                row = 1;
                column = 2;
                break;

            case 7:
                row = 2;
                column = 0;
                break;

            case 8:
                row = 2;
                column = 1;
                break;

            case 9:
                row = 2;
                column = 2;
                break;

            // The case where the player does not enter a correct move
            default:
                return false;
        }

        // Only accept the move if the block is empty
        if(grid[row][column].getState() == EMPTY)
        {
            grid[row][column].setState(move);
            return true;
        }

        // Invalid move since the block is not empty
        else
            return false;
    }

    /**
     * Description: accessor/mutator method for the state instance variable
     * Input: n/a
     * Output: returns the state of the board (game is incomplete, playerX wins, playerO wins, or draw)
     */
    public int getState()
    {
        return updateState();
    }

    /**
     * Description: updates the state instance variable according to the state of the board
     * Input: n/a
     * Output: returns the updated state of the board
     */
    public int updateState()
    {
        // Check all rows, columns, and diagonals
        int winCheck = checkRow(0) + checkRow(1) + checkRow(2) + checkColumn(0) + checkColumn(1) + checkColumn(2) + checkDiagonals();

        // If a player (X or O) wins, set the state of the board to X or O respectively 
        if(winCheck != 0)
            state = winCheck;
        
        // Otherwise, check for a draw
        else
            state = checkDraw();

        return state;
    }

    /**
     * Description: checks if 'row' in the grid is in a winning state
     * @param row holds the value of the row which is being checked
     * Output: returns the state of the row (0 [when the row is not in a winning state], X, or O)
     */
    private int checkRow(int row)
    {
        if(grid[row][0].getState() != EMPTY && grid[row][0].getState() == grid[row][1].getState() && grid[row][1].getState() == grid[row][2].getState())
            return grid[row][0].getState();

        else
            return 0;
    }

    /**
     * Description: checks if 'column' in the grid is in a winning state
     * @param column holds the value of the column which is being checked
     * Output: returns the state of the column (0 [when the column is not in a winning state], X, or O)
     */
    private int checkColumn(int column)
    {
        if(grid[0][column].getState() != EMPTY && grid[0][column].getState() == grid[1][column].getState() && grid[1][column].getState() == grid[2][column].getState())
            return grid[0][column].getState();

        else
            return 0;
    }

    /**
     * Description: checks if either of the diagonals are in a winning state
     * Input: n/a
     * Output: returns the state of the diagonals (0 [when neither diagonal is in a winning state], X, or O)
     */
    private int checkDiagonals()
    {
        if(grid[0][0].getState() != EMPTY && grid[0][0].getState() == grid[1][1].getState() && grid[1][1].getState() == grid[2][2].getState())
            return grid[0][0].getState();

        else if(grid[2][0].getState() != EMPTY && grid[2][0].getState() == grid[1][1].getState() && grid[1][1].getState() == grid[0][2].getState())
            return grid[2][0].getState();
        
        else
            return 0;
    }

    /**
     * Description: check whether the grid is in a state of draw
     * Input: n/a
     * Output: returns 0 (the game is incomplete) or DRAW (the game is a draw)
     */
    private int checkDraw()
    {
        // If an empty block is found, the game is incomplete
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(grid[i][j].getState() == EMPTY)
                    return 0;
            }
        }

        // If not, the game is a draw
        return DRAW;
    }

    /**
     * Description: display method for the grid
     * Input: n/a
     * Output: prints the contents of the grid (with numbers) to the screen
     */
    public void displayBoard()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(j < 2)
                {
                    if(grid[i][j].getState() != EMPTY)
                        System.out.print(grid[i][j] + "|");

                    else
                        System.out.printf("%d|", i * 3 + j + 1); // Print out the location of the available space
                }

                else
                {
                    if(grid[i][j].getState() != EMPTY)
                        System.out.println(grid[i][j]);

                    else
                        System.out.printf("%d\n", i * 3 + j + 1);
                }
            }
        }
    }

    /**
     * Description: alternate display method for the grid
     * Input: n/a
     * Ouptut: prints the contents of the grid (without numbers) to the screen
     */
    public void displayFinalBoard()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(j < 2)
                    System.out.print(grid[i][j] + "|");

                else
                    System.out.println(grid[i][j]);
            }
        }
    }
}