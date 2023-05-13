package day09;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class RopeBridge_Part2 {
	
	static ArrayList<Point2> points_visited = new ArrayList<>();
	static ArrayList<Point2> rope = new ArrayList<>();
	static final int head = 0, tail = 9;
	
	public static void initiateRope() {
		
		for(int i = 0; i < 10; i++)
			rope.add(new Point2(0, 0));
		
	}
	
	public static void move(String direction, int steps) {
		
		for(int i = 0; i < steps; i++) {
			
			switch(direction) {
			
			case "U":
				rope.get(head).moveUp();
				break;
			case "D":
				rope.get(head).moveDown();
				break;
			case "L":
				rope.get(head).moveLeft();
				break;
			case "R":
				rope.get(head).moveRight();
				break;
			
			}
			for(int knot = head; knot < tail; knot++) {
				
				if(!rope.get(knot).isTouching(rope.get(knot + 1)))
					rope.get(knot).move(rope.get(knot + 1));
				
			}
			
			if(isNewPosition(rope.get(tail))) {
				
				points_visited.add(new Point2(rope.get(tail).getX(), rope.get(tail).getY()));
				
			}
			
		}
		
	}
	
	public static boolean isNewPosition(Point2 point) {
		
		for(int i = 0; i < points_visited.size(); i++) {
			
			if(point.isSamePoint(points_visited.get(i)))
				return false;
			
		}
		
		return true;
		
	}

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = new Scanner(new File("src/day9/input.txt"));
		
		initiateRope();
		points_visited.add(new Point2(0, 0));
		
		while(input.hasNextLine()) {
			
			String[] line = input.nextLine().split(" ");
			move(line[0], Integer.parseInt(line[1]));
			
		}
		
		input.close();
		System.out.println(points_visited.size());
		
	}

}
