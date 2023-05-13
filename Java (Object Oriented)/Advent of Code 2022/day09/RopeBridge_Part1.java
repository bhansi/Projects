package day09;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class RopeBridge_Part1 {
	
	static ArrayList<Point> points_visited = new ArrayList<>();
	static Point head = new Point(0, 0);
	static Point tail = new Point(0, 0);
	
	public static void move(String direction, int steps) {
		
		for(int i = 0; i < steps; i++) {
			
			switch(direction) {
			
			case "U":
				head.moveUp();
				if(!head.isTouching(tail)) {
					
					tail.moveUp();
					if(!head.inSameRowOrColumn(direction, tail)) {
						
						if(head.getX() - tail.getX() > 0)
							tail.moveRight();
						else
							tail.moveLeft();
						
					}
					
				}
				break;
				
			case "D":
				head.moveDown();
				if(!head.isTouching(tail)) {
					
					tail.moveDown();
					if(!head.inSameRowOrColumn(direction, tail)) {
						
						if(head.getX() - tail.getX() > 0)
							tail.moveRight();
						else
							tail.moveLeft();
						
					}
					
				}
				break;
				
			case "L":
				head.moveLeft();
				if(!head.isTouching(tail)) {
					
					tail.moveLeft();
					if(!head.inSameRowOrColumn(direction, tail)) {
						
						if(head.getY() - tail.getY() > 0)
							tail.moveUp();
						else
							tail.moveDown();
						
					}
					
				}
				break;
				
			case "R":
				head.moveRight();
				if(!head.isTouching(tail))	{
					
					tail.moveRight();
					if(!head.inSameRowOrColumn(direction, tail)) {
						
						if(head.getY() - tail.getY() > 0)
							tail.moveUp();
						else
							tail.moveDown();
						
					}
					
				}
				break;
			
			}
			
			if(isNewPosition(tail)) {
				
				points_visited.add(new Point(tail.getX(), tail.getY()));
				
			}
			
		}
		
	}
	
	public static boolean isNewPosition(Point point) {
		
		for(int i = 0; i < points_visited.size(); i++) {
			
			if(point.isSamePoint(points_visited.get(i)))
				return false;
			
		}
		
		return true;
		
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = new Scanner(new File("src/day9/input.txt"));
		
		points_visited.add(new Point(0, 0));
		String[] line = null;
		
		while(input.hasNextLine()) {
			
			line = input.nextLine().split(" ");
			move(line[0], Integer.parseInt(line[1]));
			
		}
		
		input.close();
		System.out.println(points_visited.size());
		
	}

}
