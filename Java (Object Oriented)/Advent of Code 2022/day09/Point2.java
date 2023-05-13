package day09;

public class Point2 {

	private int x;
	private int y;
	
	public Point2(int x, int y) {
		
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
	
	public boolean isSamePoint(Point2 point) {
		
		return this.x == point.getX() && this.y == point.getY();
		
	}
	
	public boolean isTouching(Point2 point) {
		
		return Math.abs(this.x - point.getX()) < 2 && Math.abs(this.y - point.getY()) < 2;
		
	}
	
	public void move(Point2 point) {
		
		int x_difference = this.getX() - point.getX();
		int y_difference = this.getY() - point.getY();
		
		if(x_difference == 0) {
			
			if(y_difference > 0)
				point.moveUp();
			else
				point.moveDown();
			
		}
		else if (y_difference == 0) {
			
			if(x_difference > 0)
				point.moveRight();
			else
				point.moveLeft();
			
		}
		else {
			
			if(x_difference > 0) {
				
				if(y_difference > 0) {
					
					point.moveUp();
					point.moveRight();
					
				}
				else {
					
					point.moveDown();
					point.moveRight();
					
				}
				
			}
			else {
				
				if(y_difference > 0) {
					
					point.moveUp();
					point.moveLeft();
					
				}
				else {
					
					point.moveDown();
					point.moveLeft();
					
				}
				
			}
			
		}
		
	}
	
	public String toString() {
		
		return String.format("(%3d, %3d)", this.x, this.y);
		
	}
	
}
