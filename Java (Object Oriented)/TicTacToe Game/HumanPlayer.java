public class HumanPlayer extends player
{
    /**
     * Description: overloaded constructor for the HumanPlayer class
     * @param symbol holds the symbol for the human player (X or O)
     * @param name holds the name of the human player
     * @param gameBoard holds the game board
     * Output: calls the overloaded constructor of the player class
     */
    public HumanPlayer(int symbol, String name, board gameBoard)
    {
        super(symbol, name, gameBoard);
    }

    /**
     * Description: has the human player make a move in an available spot
     * @param gameBoard holds the gameBoard
     * Output: updates the gameBoard once a valid move is played
     */
    public void play(board gameBoard)
    {
        boolean valid = false;
        int location;

        super.gameBoard = gameBoard;

        while(!valid)
        {
            try{Thread.sleep(1000);}
            catch(InterruptedException e){}
            System.out.println("Cortana: Please make your move at one of the available slots:");
            gameBoard.displayBoard();
            location = scan.nextInt();

            if(!(valid = gameBoard.makeMove(location, symbol)))
                System.out.println("Cortana: Invalid move, please try again.");
        }
    }
}