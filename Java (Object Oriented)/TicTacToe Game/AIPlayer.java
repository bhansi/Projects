import java.util.Random;

public class AIPlayer extends player
{
    /**
     * Description: overloaded constructor for the AIPlayer class
     * @param symbol holds the symbol (X or O) of the AI player
     * @param name holds the name of the AI player
     * @param gameBoard holds the game board
     * Output: calls the overloaded constructor of the player class to give values to the respective instance members
     */
    public AIPlayer(int symbol, String name, board gameBoard)
    {
        super(symbol, name, gameBoard);
    }

    /**
     * Description: has the AI player make a move in an available spot
     * @param gameBoard holds the gameBoard
     * Output: updates the gameBoard once a valid move is played
     */
    public void play(board gameBoard)
    {
        boolean valid = false;
        int location = 0;

        while(!valid)
        {
            location = rand.nextInt(9) + 1;
            valid = gameBoard.makeMove(location, symbol);
        }

        try{Thread.sleep(2000);}
        catch(InterruptedException e){}
        System.out.println(name + ": I made a move at " + location);
        gameBoard.displayFinalBoard();
    }
}