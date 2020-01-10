public class Rectangle extends Shape
{
    int num;
    int height;
    int width;
    double area;

    /**
     * Description: default constructor for Rectangle class
     * Input: n/a
     * Output: increments id and gives default values to class and derived members
     */
    public Rectangle()
    {
        num = ++id;
        label = "";
        height = 0;
        width = 0;
        area = 0;
    }

    /**
     * Description: overloaded constructor for Rectangle class
     * @param l holds the user defined label
     * @param h holds the user defined height
     * @param w holds the user defined width
     * Output: increments id and gives values to label, height, and width
     */
    public Rectangle(String l, int h, int w)
    {
        num = ++id;
        label = l;
        height = h;
        width = w;
        area = CalculateArea();
    }

    /**
     * Description: overridden method that calculates the area of a rectangle
     * Input: n/a
     * @return the area of "this"
     */
    public double CalculateArea()
    {
        return height * width;
    }

    public String toString()
    {
        return String.format("%-2d", num) + " " + String.format("%-9s", label) + " = " + String.format("%.2f", area);
    }
}