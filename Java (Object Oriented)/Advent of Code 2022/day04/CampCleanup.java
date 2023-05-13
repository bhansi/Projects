package day04;

import java.lang.System;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CampCleanup {
	
	public static boolean isSubset(String[] line) {
		
		int range1_lower = Integer.parseInt(line[0]);
		int range1_upper = Integer.parseInt(line[1]);
		int range2_lower = Integer.parseInt(line[2]);
		int range2_upper = Integer.parseInt(line[3]);
		
		return range1_lower <= range2_lower && range1_upper >= range2_upper ||
			   range1_lower >= range2_lower && range1_upper <= range2_upper;
		
	}
	
	public static boolean isOverlapped(String[] line) {
		
		int range1_lower = Integer.parseInt(line[0]);
		int range1_upper = Integer.parseInt(line[1]);
		int range2_lower = Integer.parseInt(line[2]);
		int range2_upper = Integer.parseInt(line[3]);
		
		return range1_upper >= range2_lower && range1_lower <= range2_upper ||
			   range2_upper >= range1_lower && range2_lower <= range1_upper;
		
	}

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner input = new Scanner(new File("src\\day4\\input.txt"));
		
		int count = 0;
		
		while(input.hasNextLine()) {
			
			String[] line = input.nextLine().split("[-,]");
			
			if(isOverlapped(line))
				count++;
		}
		
		input.close();
		System.out.println(count);
		
	}
	
}
