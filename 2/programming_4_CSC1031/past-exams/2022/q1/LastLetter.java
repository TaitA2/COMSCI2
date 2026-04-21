import java.util.Scanner;

public class LastLetter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("What is your name: ");
        String name = scanner.nextLine();
        System.out.println("The last letter in your name is " + name.substring(name.length() - 1) + ".");
        scanner.close();
    }
}
