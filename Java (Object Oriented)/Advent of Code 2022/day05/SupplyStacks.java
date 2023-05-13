package day05;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class SupplyStacks {
	
	public static void initializeStacks(ArrayList<String> crates, ArrayList<Stack<String>> stacks) {
		
		for(int i = crates.size() - 1; i >= 0; i--) {
			
			char[] line = crates.get(i).toCharArray();
			
			for(int j = 0; j < line.length; j++) {
				
				if(line[j] == '[') {
					
					stacks.get(j / 4).push(String.valueOf(line[j + 1]));
										
				}
				
			}
			
		}
		
	}
	
	public static void moveCrates(int quantity, int old_stack, int new_stack, ArrayList<Stack<String>> stacks) {
		
		Stack<String> temp = new Stack<String>();
		
		for(int i = 0; i < quantity; i++) {
			
			temp.push(stacks.get(old_stack).pop());
			
		}
		for(int i = 0; i < quantity; i++) {
			
			stacks.get(new_stack).push(temp.pop());
			
		}
		
	}

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner input = new Scanner(new File("src\\day5\\input.txt"));
		ArrayList<String> crates = new ArrayList<String>();
		
		while(input.hasNextLine()) {
			
			String line = input.nextLine();
			
			if(!line.contains("1"))
				crates.add(line);
			else {
				
				input.nextLine();
				break;
				
			}
			
		}
		
		ArrayList<Stack<String>> stacks = new ArrayList<Stack<String>>();
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		stacks.add(new Stack<String>());
		
		initializeStacks(crates, stacks);
		
		while(input.hasNextLine()) {
			
			String[] line = input.nextLine().split("[a-z ]+");
			moveCrates(Integer.parseInt(line[1]), Integer.parseInt(line[2]) - 1, Integer.parseInt(line[3]) - 1, stacks);
			
		}
		
		for(int i = 0; i < 9; i++)
			System.out.print(stacks.get(i).peek());
				
		input.close();
		
	}

}
