package day10;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CathodeRayTube_Part1 {
	
	static int cycle = 0, x = 1, signal_strength = 0;
	
	public static void noop() {
		
		cycle++;
		checkCycle();
		
	}
	
	public static void addx(int v) {
		
		cycle++;
		checkCycle();
		cycle++;
		checkCycle();
		x += v;
		
	}
	
	public static void checkCycle() {
		
		switch(cycle) {
		
		case 20:
		case 60:
		case 100:
		case 140:
		case 180:
		case 220:
			signal_strength += cycle * x;
			break;
		
		}
		
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = new Scanner(new File("src/day10/input.txt"));
		
		while(input.hasNextLine() && cycle <= 220) {
			
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
		
		System.out.println(signal_strength);
		
	}

}
