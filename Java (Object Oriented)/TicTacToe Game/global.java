import java.util.Scanner;
import java.util.Random;

public interface global
{
    int EMPTY = 0;
    int X = 1;
    int O = 2;
    int DRAW = 3;
    Scanner scan = new Scanner(System.in); // Scanner object for any classes that need it
    Random rand = new Random(); // Random object for any classes that need it
}