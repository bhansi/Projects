public abstract class Shape implements Comparable<Shape>
{
    protected static int id = 0; // Holds the ID number of the generated shape
    protected String label; // Holds the name of the generated shape (Circle, Rectangle, or Triangle)

    public abstract double CalculateArea(); // Abstract method to calculate the area of a shape
    public abstract String toString();

    /**
     * Description: overried compareTo() method to sort the object list in decending order according to shape area
     * @param o the object being compared with this
     * Output: returns 0, 1, or -1 based to the comparason between area1 and area2
     */
    public int compareTo(Shape o)
    {
        double area1 = this.CalculateArea();
        double area2 = o.CalculateArea();

        if(area1 == area2)
            return 0;

        else if(area1 > area2)
            return 1;

        else
            return -1;
    }
}