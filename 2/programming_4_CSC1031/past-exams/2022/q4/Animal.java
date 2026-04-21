import java.util.Scanner;

public class Animal {
    String name;

    public Animal(String name) {
        this.name = name;
    }

    public String greeting() {
        return "Hello, my name is " + this.name;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String name = in.nextLine();
        Animal ani = new Animal(name);
        System.out.println(ani.greeting());
    }
}
