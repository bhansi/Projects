public abstract class player implements global
{
    public int symbol;
    public String name;
    public board gameBoard;

    public abstract void play(board gameBoard);

    /**
     * Description: overloaded constructor for the player class
     * @param symbol holds the symbol of the player (X or O)
     * @param name holds the name of the player
     * @param gameBoard holds the gameboard for the player
     * Output: sets symbol, name, and gameBoard to the respective parameters
     */
    public player(int symbol, String name, board gameBoard)
    {
        this.symbol = symbol;
        this.name = name;
        this.gameBoard = gameBoard;
    }

    /**
     * Description: toString method for the player class
     * Input: n/a
     * Output: returns the name of the player
     */
    public String toString()
    {
        return name;
    }
}