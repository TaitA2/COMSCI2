import java.util.Scanner;

public class Reverse {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("How many numbers: ");
        int count = scanner.nextInt();

        int[] nums = new int[count];

        System.out.print("Enter " + count + " numbers: ");

        for (int i = 0; i < count; i++) {
            nums[count - i - 1] = scanner.nextInt();
        }

        System.out.print("The numbers reversed are: ");
        for (int i : nums) {
            System.out.print(i + " ");
        }
        System.out.println();

    }
}
