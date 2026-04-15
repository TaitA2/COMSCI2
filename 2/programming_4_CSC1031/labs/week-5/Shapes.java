// Abstract class Shape
abstract class Shape {
    // Protected color field
    protected String color;

    // Constructor
    public Shape(String color) {
        this.color = color;
    }

    // Abstract method to get this shape's area
    abstract double getArea();

    // Concrete method to print this shape's color
    void displayColor() {
        System.out.println("Shape color: " + this.color);
    }
}

// Subclass Circle
class Circle extends Shape {
    // Radius field
    private double radius;

    // Constructor
    public Circle(String color, double radius) {
        super(color);
        this.radius = radius;
    }

    // Implementation of getArea
    double getArea() {
        if (this.radius <= 0) {
            return 0;
        }
        return Math.PI * this.radius * this.radius;
    }
}

// Subclass Rectangle
class Rectangle extends Shape {
    // Width and height fields
    private double width, height;

    // Constructor
    public Rectangle(String color, double width, double height) {
        super(color);
        this.width = width;
        this.height = height;
    }

    // Implementation of getArea
    double getArea() {
        if (this.width <= 0 || this.height <= 0) {
            return 0;
        }
        return this.width * this.height;
    }
}
