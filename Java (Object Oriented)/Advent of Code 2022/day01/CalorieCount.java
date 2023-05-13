package day01;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CalorieCount {

	public static void main(String args[]) throws FileNotFoundException  {
		
		Scanner input = new Scanner(new File("src\\day1\\input.txt"));
		
		int top_1 = 0, top_2 = 0, top_3 = 0, new_calories = 0;
		while(input.hasNextLine()) {
			
			String line = input.nextLine();
			
			if(!line.equals("")) {
				
				new_calories += Integer.parseInt(line);
				
			}
			else {
				
				if(new_calories > top_1) {
					
					top_3 = top_2;
					top_2 = top_1;
					top_1 = new_calories;
					
				}
				else if(new_calories > top_2) {
					
					top_3 = top_2;
					top_2 = new_calories;
					
				}
				else if(new_calories > top_3)
					top_3 = new_calories;
				new_calories = 0;
			}
		}
		
		input.close();
				
		System.out.println(top_1 + top_2 + top_3);
	}
	
}
