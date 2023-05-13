package day08;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class TreetopTreeHouse_Part1 {
	
	static ArrayList<ArrayList<Integer>> grid = new ArrayList<>();
	
	public static boolean isVisible(int tree_row, int tree_column) {
		
		int tree_size = grid.get(tree_row).get(tree_column);
		
		if(tree_size == 0)
			return false;
		
		int up = tree_row - 1,
			down = tree_row + 1,
			left = tree_column - 1,
			right = tree_column + 1;
		boolean up_visible = true,
				down_visible = true,
				left_visible = true,
				right_visible = true;
		
		while(true) {
			
			if(up >= 0) {
				
				if(up_visible)
					up_visible = !(tree_size <= grid.get(up).get(tree_column));
				up--;
				
			}
			
			if(down < grid.size()) {
				
				if(down_visible)
					down_visible = !(tree_size <= grid.get(down).get(tree_column));
				down++;
				
			}
			
			if(left >= 0) {
				
				if(left_visible)
					left_visible = !(tree_size <= grid.get(tree_row).get(left));
				left--;
				
			}
			
			if(right < grid.get(0).size()) {
				
				if(right_visible)
					right_visible = !(tree_size <= grid.get(tree_row).get(right));
				right++;
				
			}
			
			if(up < 0 && down >= grid.size() && left < 0 && right >= grid.get(0).size())
				break;
						
		}
		
		return up_visible || down_visible || left_visible || right_visible;
		
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
		
		int number_of_visible_trees = 0;
		number_of_visible_trees += grid.get(0).size() * 2 + grid.size() * 2 - 4;
		
		for(int row = 1; row < grid.size() - 1; row++) {
			
			for(int column = 1; column < grid.get(0).size() - 1; column++) {
				
				if(isVisible(row, column))
					number_of_visible_trees++;
				
			}
			
		}
		
		System.out.println(number_of_visible_trees);
		
	}

}
