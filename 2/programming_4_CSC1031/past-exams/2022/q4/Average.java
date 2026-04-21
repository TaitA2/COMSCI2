public abstract class Shape {
    private String name;

    public Shape(String name) {
        this.name = name;
    }

    abstract double area();

    public String toString() {
        return name + " with area " + area();
    }
}

public class Average {
    public double averageArea(Shape[] shapes) {
        double total = 0;

        for (Shape s : shapes) {
            total += s.area();
        }
        return total / shapes.length;
    }
}
