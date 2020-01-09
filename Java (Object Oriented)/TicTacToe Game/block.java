public class block implements global
{
    private int state;

    /**
     * Description: default constructor for the block class
     * Input: n/a
     * Output: sets the state of an instance block to EMPTY (0)
     */
    public block()
    {
        state = EMPTY;
    }

    /**
     * Description: mutator method for the 'state' instance member
     * @param state holds the state the player wishes to change 'this' block to
     * Output: returns true if the state was successfully changed, false otherwise
     */
    public boolean setState(int state)
    {
        if(isValidState(state))
        {
            this.state = state;
            return true;
        }

        else
            return false;
    }

    /**
     * Description: accessor method for the 'state' instance member
     * Input: n/a
     * Output: returns the state of 'this' block
     */
    public int getState()
    {
        return state;
    }

    /**
     * Description: helper method to determine whether a change in state is valid or not
     * @param state holds the change in state
     * Output: returns true if the change in state is valid (X or O), false otherwise
     */
    private boolean isValidState(int state)
    {
        if(state == X || state == O)
            return true;
        
        else
            return false;
    }

    /**
     * Description: toString method for the block class
     * Intput: n/a
     * Output: returns a string to represent the state of 'this' block
     */
    public String toString()
    {
        if(state == EMPTY)
            return " ";

        else if(state == X)
            return "X";

        else
            return "O";
    }
}