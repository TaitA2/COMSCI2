import java.util.Scanner;

public class NoMinusOne {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter numbers: ");
        int prev = -1;
        int num = scanner.nextInt();
        while (num != -1) {
            prev = num;
            num = scanner.nextInt();
        }
        System.out.println("The penultimate number was: " + prev);
    }
}
