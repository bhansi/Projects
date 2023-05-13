package day03;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class RucksackReorganization {
	
	public static boolean isUpper(char c) {
		
		return c >= 65 && c <= 90;
		
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = new Scanner(new File("src\\day3\\input.txt"));
		
		int sum_of_priorities = 0;
		boolean item_found = false;

		while(input.hasNextLine()) {
			
			char[] rucksack1 = input.nextLine().toCharArray();
			char[] rucksack2 = input.nextLine().toCharArray();
			char[] rucksack3 = input.nextLine().toCharArray();
			
			for(int r1 = 0; r1 < rucksack1.length; r1++) {
				
				for(int r2 = 0; r2 < rucksack2.length; r2++) {
					
					if(rucksack1[r1] != rucksack2[r2])
						continue;
					
					for(int r3 = 0; r3 < rucksack3.length; r3++) {
						
						if(rucksack1[r1] != rucksack3[r3])
							continue;
						else {
							
							if(isUpper(rucksack1[r1]))
								sum_of_priorities += rucksack1[r1] - 38;
							else
								sum_of_priorities += rucksack1[r1] - 96;
							
							item_found = true;
							break;
							
						}
						
					}
					
					if(item_found)
						break;
					
				}
				
				if(item_found) {
					
					item_found = false;
					break;
					
				}
				
			}
			
		}
		
		input.close();
		
		System.out.println(sum_of_priorities);
		
	}

}
