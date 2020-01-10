public class Circle extends Shape
{
    int num;
    int radius;
    double area;

    /**
     * Description: default constructor for Circle class
     * Input: n/a
     * Output: increments id and gives default values to class and derived members
     */
    public Circle()
    {
        num = ++id;
        label = "";
        radius = 0;
        area = 0;
    }

    /**
     * Description: overloaded constructor for Cirlce class
     * @param l holds the user defined label
     * @param r holds the user defined radius
     * Output: increments id and gives values to label and radius
     */
    public Circle(String l, int r)
    {
        num = ++id;
        label = l;
        radius = r;
        area = CalculateArea();
    }

    /**
     * Description: overridden method that calculates the area of a circle
     * Input: n/a
     * @return the area of "this"
     */
    public double CalculateArea()
    {
        return Math.PI * radius * radius;
    }

    public String toString()
    {
        return String.format("%-2d", num) + " " + String.format("%-9s", label) + " = " + String.format("%.2f", area);
    }
}