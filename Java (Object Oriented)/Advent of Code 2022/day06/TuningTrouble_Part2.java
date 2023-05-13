package day06;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TuningTrouble_Part2 {
	
	public static boolean isMessage(char[] buffer, int start, int end) {
		
		for(int i = start; i < end; i++) {
			
			for(int j = i + 1; j <= end; j++) {
			
				if(buffer[i] == buffer[j])
					return false;
					
			}
			
		}
		
		return true;
		
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = new Scanner(new File("src\\day6\\input.txt"));
		
		char[] buffer = input.nextLine().toCharArray();
		int i = 0, j = 13;
		
		for(; j < buffer.length; i++, j++) {
			
			if(isMessage(buffer, i, j))
				break;
			
		}
			
		input.close();
		
		System.out.println(j+1);
		
	}
}
