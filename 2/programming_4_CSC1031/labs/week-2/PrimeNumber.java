import java.util.Scanner;

public class PrimeNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the upper limit
        long limit = scanner.nextInt();

        // Counter of prime number
        long cnt = 0;

        // Write your code
        for (int i =1; i <= limit; i++){
          if (isPrime(i)){
            cnt++;
          }
        }

        // Print the results
        System.out.println(cnt);
    }

    // Function to check if it is prime
    private static boolean isPrime(long num) {
        if (num <= 1){
            return false;
        }
        if (num == 2 || num == 3){
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0){
            return false;
        }
        for (int i = 5; i <= Math.sqrt(num); i = i + 6){
            if (num % i == 0 || num % (i + 2) == 0){
                return false;
            }
        }

        return true;
    }
}
