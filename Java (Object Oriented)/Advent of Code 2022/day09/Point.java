package day09;

public class Point {

	private int x;
	private int y;
	
	public Point(int x, int y) {
		
		this.x = x;
		this.y = y;
		
	}
	
	public int getX() {
		
		return this.x;
		
	}
	
	public int getY() {
		
		return this.y;
		
	}

	public void moveUp() {
		
		this.y++;
		
	}
	
	public void moveDown() {
		
		this.y--;
		
	}
	
	public void moveLeft() {
		
		this.x--;
		
	}

	public void moveRight() {
		
		this.x++;
		
	}
	
	public boolean isSamePoint(Point point) {
		
		return this.x == point.getX() && this.y == point.getY();
		
	}
	
	public boolean isTouching(Point point) {
		
		return Math.abs(this.x - point.getX()) < 2 && Math.abs(this.y - point.getY()) < 2;
		
	}
	
	public boolean inSameRowOrColumn(String direction, Point point) {
		
		switch(direction) {
		
		case "U":
		case "D":
			return this.x == point.getX();
		case "L":
		case "R":
		default:
			return this.y == point.getY();
		
		}
		
	}
	
	public String toString() {
		
		return String.format("(%3d, %3d)", this.x, this.y);
		
	}
	
}
