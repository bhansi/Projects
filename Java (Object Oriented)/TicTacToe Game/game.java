import java.util.Random;
import java.util.Scanner;

public class game implements global
{
    board gameBoard;
    player playerX;
    player playerO;

    /**
     * Description: method to create and setup a game of tic-tac-toe
     * Input: n/a
     * Output: has the player choose the gamemode and player names (if any)
     */
    public game()
    {
        gameBoard = new board();
        String name1 = "", name2 = "";
        int mode;
        boolean valid = false;

        while(!valid)
        {
            System.out.println("-----------------------------------------------------------------------------------------");
            System.out.println("-------------------------------- Welcome to Tic-Tac-Toe! --------------------------------");
            System.out.println("------------------------ I am your humble game referee, Cortana. ------------------------");
            System.out.println("-----------------------------------------------------------------------------------------");
            System.out.print("Cortana: Please select a game mode:\n[1] Human vs. Human\n[2] Human vs. AI\n[3] AI vs. AI\nEnter your selection: ");
            mode = scan.nextInt();
            
            switch(mode)
            {
                case 1:
                    System.out.print("Cortana: Please enter human playerX's name: ");
                    name1 = scan.next();

                    System.out.print("Cortana: Please enter human playerO's name: ");
                    name2 = scan.next();
                    
                    valid = true;

                    playerX = new HumanPlayer(X, name1, gameBoard);
                    playerO = new HumanPlayer(O, name2, gameBoard);

                    break;

                case 2:
                    System.out.print("Cortana: Please enter human playerX's name: ");
                    name1 = scan.next();

                    try{Thread.sleep(1000);}
                    catch(InterruptedException e){}
                    System.out.println("Cortana: PlayerO AI will be Siri.");
                    name2 = "Siri";

                    valid = true;

                    playerX = new HumanPlayer(X, name1, gameBoard);
                    playerO = new AIPlayer(O, name2, gameBoard);

                    break;

                case 3:
                    try{Thread.sleep(1000);}
                    catch(InterruptedException e){}
                    System.out.println("Cortana: PlayerX AI will be Alexa");
                    name1 = "Alexa";

                    try{Thread.sleep(1000);}
                    catch(InterruptedException e){}
                    System.out.println("Cortana: PlayerO AI will be Siri");
                    name2 = "Siri";

                    valid = true;

                    playerX = new AIPlayer(X, name1, gameBoard);
                    playerO = new AIPlayer(O, name2, gameBoard);

                    break;
            }
        }

        System.out.print("Cortana: ");
        for(int i = 0; i < 3; i++)
        {
            try{Thread.sleep(1000);}
            catch(InterruptedException e){}
            System.out.print(".");
        }

        try{Thread.sleep(1000);}
        catch(InterruptedException e){}
        System.out.println("\nCortana: Game has been successfully started!");
        try{Thread.sleep(1000);}
        catch(InterruptedException e){}
        System.out.println("Cortana: Lets get ready to TIC-TAC-TOE!");
        try{Thread.sleep(1000);}
        catch(InterruptedException e){}
        System.out.printf("Cortana: %s vs. %s!\n", name1, name2);
    }

    /**
     * Description: method to start playing the game
     * Input: n/a
     * Output: calls various methods to control the game as it progesses and exits
     *         once a player has won or there is a draw 
     */
    public void start()
    {
        boolean finished = false;
        int gameResult = 0;

        int turn = rand.nextInt(2) + 1;

        try{Thread.sleep(1000);}
        catch(InterruptedException e){}
        if(turn == 1)
            System.out.printf("Cortana: %s wins the coin toss! X goes first.\n", playerX.name);

        else
            System.out.printf("Cortana: %s wins the coin toss! O goes first.\n", playerO.name);

        while(!finished)
        {
            if(turn == 1)
            {
                try{Thread.sleep(1000);}
        catch(InterruptedException e){}
                System.out.printf("\nCortana: PlayerX's turn, make your move, %s!\n", playerX.name);
                playerX.play(gameBoard);
            }

            else
            {
                try{Thread.sleep(1000);}
        catch(InterruptedException e){}
                System.out.printf("\nCortana: PlayerO's turn, make your move, %s!\n", playerO.name);
                playerO.play(gameBoard);
            }

            gameResult = gameBoard.getState();

            if(gameResult != 0)
                finished = true;

            else
            {
                if(turn == 1)
                    turn = 2;

                else
                    turn = 1;
            }
        }

        try{Thread.sleep(1000);}
        catch(InterruptedException e){}
        System.out.println("\nCortana: Heres the final board!");
        gameBoard.displayFinalBoard();

        switch(gameResult)
        {
            case X:
                System.out.println("\nCortana: PlayerX wins the game! Congratulations, " + playerX.name + ".");
                break;

            case O:
                System.out.println("\nCortana: PlayerO wins the game! Congratulations, " + playerO.name + ".");
                break;

            case DRAW:
                System.out.println("\nCortana: It's a draw!");
        }

        scan.close(); // Closes the scanner object at the end of the game
    }
}