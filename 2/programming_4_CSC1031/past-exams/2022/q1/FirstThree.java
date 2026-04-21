import java.util.Scanner;

public class FirstThree {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Tell me your name: ");
        System.out.println("Your nickname is " + scanner.nextLine().substring(0, 3) + ".");
        scanner.close();
    }
}
