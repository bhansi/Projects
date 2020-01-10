public class Triangle extends Shape
{
    int num;
    int base;
    int height;
    double area;

    /**
     * Description: default constructor for Triangle class
     * Input: n/a
     * Output: increments id and gives default values to class and derived members
     */
    public Triangle()
    {
        num = ++id;
        label = "";
        base = 0;
        height = 0;
        area = 0;
    }

    /**
     * Description: overloaded constructor for Triangle class
     * @param l holds the user defined label
     * @param b holds the user defined base
     * @param h holds the user defined height
     * Output: increments id and gives values to label, base, and height
     */
    public Triangle(String l, int b, int h)
    {
        num = ++id;
        label = l;
        base = b;
        height = h;
        area = CalculateArea();
    }

    /**
     * Description: overridden method that calculates the area of a triangle
     * Input: n/a
     * @return the area of "this"
     */
    public double CalculateArea()
    {
        return ((double) (base * height)) / 2;
    }

    public String toString()
    {
        return String.format("%-2d", num) + " " + String.format("%-9s", label) + " = " + String.format("%.2f", area);
    }
}