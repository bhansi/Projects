package day10;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CathodeRayTube_Part2 {
	
	static int cycle = 0, x = 1;
	
	public static void noop() {
		
		printPixel();
		cycle++;
		
	}
	
	public static void addx(int v) {
		
		printPixel();
		cycle++;
		printPixel();
		cycle++;
		x += v;
		
	}
	
	public static void printPixel() {
		
		if(cycle == 40) {
			
			cycle = 0;
			System.out.println();
			
		}
		
		if(isOverlapped())
			System.out.print("#");
		else
			System.out.print(".");
		
	}
	
	public static boolean isOverlapped() {
		
		return (x - 1) <= cycle && cycle <= (x + 1);
		
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = new Scanner(new File("src/day10/input.txt"));
		
		while(input.hasNextLine() && cycle <= 240) {
			
			String[] line = input.nextLine().split(" ");
			
			switch(line[0]) {
			
			case "noop":
				noop();
				break;
			case "addx":
				addx(Integer.parseInt(line[1]));
				break;
			
			}
			
		}
		
		input.close();
		
	}

}
