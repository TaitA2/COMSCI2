import java.util.Scanner;

public class Absolute {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = scanner.nextInt();
        if (num < 0) {
            num = (num - (2 * num));
        }
        System.out.println("The absolute value is " + num + ".");
    }
}
