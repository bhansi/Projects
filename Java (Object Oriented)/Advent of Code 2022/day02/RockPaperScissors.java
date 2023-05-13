package day02;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class RockPaperScissors {

	public static void main(String args[]) throws FileNotFoundException  {
		
		Scanner input = new Scanner(new File("src\\day2\\input.txt"));
		
		int score = 0;
		
		while(input.hasNextLine()) {
			
			String[] line = input.nextLine().split(" ");
			
			if(line[0].equals(line[1]))
				score += 3;
			else {
				
				switch(line[1]) {
				
				case "X":
					switch(line[0]) {
					
					case "A":
						score += 3;
						break;
					case "B":
						score += 1;
						break;
					case "C":
						score += 2;
						break;
					
					}
					break;
				case "Y":
					switch(line[0]) {
					
					case "A":
						score += 1 + 3;
						break;
					case "B":
						score += 2 + 3;
						break;
					case "C":
						score += 3 + 3;
						break;
						
					}
					break;
				case "Z":
					switch(line[0]) {
					
					case "A":
						score += 2 + 6;
						break;
					case "B":
						score += 3 + 6;
						break;
					case "C":
						score += 1 + 6;
						break;
						
					}
					break;
				
				}
				
			}
		}
		
		input.close();
		System.out.println(score);
	}
	
}
