package day08;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class TreetopTreeHouse_Part2 {
	
	static ArrayList<ArrayList<Integer>> grid = new ArrayList<>();
	
	public static int calculateScenicScore(int tree_row, int tree_column) {
		
		int tree_size = grid.get(tree_row).get(tree_column);
		
		if(tree_size == 0)
			return 1;
		
		int up_distance = 1,
			down_distance = 1,
			left_distance = 1,
			right_distance = 1;
		
		for(; tree_row - up_distance > 0 && tree_size > grid.get(tree_row - up_distance).get(tree_column); up_distance++);
		for(; tree_row + down_distance < 98 && tree_size > grid.get(tree_row + down_distance).get(tree_column); down_distance++);
		for(; tree_column - left_distance > 0 && tree_size > grid.get(tree_row).get(tree_column - left_distance); left_distance++);
		for(; tree_column + right_distance < 98 && tree_size > grid.get(tree_row).get(tree_column + right_distance); right_distance++);
		
		return up_distance * down_distance * left_distance * right_distance;
		
	}

	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner input = new Scanner(new File("src/day8/input.txt"));
		
		
		for(int row = 0; input.hasNextLine(); row++) {
			
			grid.add(new ArrayList<Integer>());
			
			char[] line = input.nextLine().toCharArray();
			for(int column = 0; column < line.length; column++)
				grid.get(row).add(line[column] - 48);
			
		}
		
		input.close();
		
		int highest_scenic_score = 0, current_scenic_score = 0;
		
		for(int row = 1; row < grid.size() - 1; row++) {
			
			for(int column = 1; column < grid.get(0).size() - 1; column++) {
				
				current_scenic_score = calculateScenicScore(row, column);
				if(current_scenic_score > highest_scenic_score)
					highest_scenic_score = current_scenic_score;
				
			}
			
		}
		
		System.out.println(highest_scenic_score);
		
	}

}
