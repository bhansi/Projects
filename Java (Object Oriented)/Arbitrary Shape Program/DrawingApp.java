import java.util.*;

public class DrawingApp
{
    public static void main(String args[])
    {
        ArrayList<Shape> shapes = new ArrayList<Shape>();
        double total = 0;
        Random r = new Random();

        for(int i = 0; i < 10; i++)
        {
            switch(r.nextInt(3))
            {
                case 0:
                    shapes.add(new Circle("Circle", r.nextInt(20) + 1));
                    total += shapes.get(i).CalculateArea();
                    System.out.println(shapes.get(i));
                    break;

                case 1:
                    shapes.add(new Rectangle("Rectangle", r.nextInt(20) + 1, r.nextInt(20) + 1));
                    total += shapes.get(i).CalculateArea();
                    System.out.println(shapes.get(i));
                    break;

                case 2:
                    shapes.add(new Triangle("Triangle", r.nextInt(20) + 1, r.nextInt(20) + 1));
                    total += shapes.get(i).CalculateArea();
                    System.out.println(shapes.get(i));
            }
        }

        System.out.println(String.format("\nThe total area of the generated shapes is %.2f\n", total));

        Collections.sort(shapes);

        System.out.println("The shapes sorted in decending order according to area is:\n");
        for(int i = 0; i < 10; i++)
        {
            System.out.println(shapes.get(i));
        }
    }
}