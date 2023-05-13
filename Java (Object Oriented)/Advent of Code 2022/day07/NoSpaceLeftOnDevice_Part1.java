package day07;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class NoSpaceLeftOnDevice_Part1 {
	
	public static ArrayList<DirectorySize> directorySizes = new ArrayList<>();

	public static long countDirectorySizes(Scanner input, String currentDirectoryName, long currentDirectorySize) {
		
		while(input.hasNextLine()) {
			
			String[] line = input.nextLine().split(" ");
			
			if(line[0].equals("$") && line[1].equals("cd")) {
				
				if(line[2].equals("..")) {
					
					directorySizes.add(new DirectorySize(currentDirectoryName, currentDirectorySize));
					return currentDirectorySize;
						
				}
				else {
					
					currentDirectorySize += countDirectorySizes(input, line[2], 0);
					
				}
				
			}
			else if(line[0].matches("[0-9]+"))
				currentDirectorySize += Long.parseLong(line[0]);
			
		}
		
		directorySizes.add(new DirectorySize(currentDirectoryName, currentDirectorySize));
		return currentDirectorySize;
		
	}

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner input = new Scanner(new File("src/day7/input.txt"));
		
		input.nextLine();
		
		countDirectorySizes(input, "/", 0);
		
		input.close();
		
		System.out.println(directorySizes);
		
		long total = 0;
		
		for(int i = 0; i < directorySizes.size(); i++) {
			
			if(directorySizes.get(i).getDirectorySize() <= 100000)
				total += directorySizes.get(i).getDirectorySize();
			
		}
		
		System.out.println(total);
		
	}

}
