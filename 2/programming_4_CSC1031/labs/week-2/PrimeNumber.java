import java.util.Scanner;

public class PrimeNumber {
    private static boolean[] prime;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the upper limit
        long limit = scanner.nextInt();

        // Counter of prime number
        long cnt = 0;

        // Write your code
        prime = new boolean[(int)limit+1];
        for (int i =0; i <= limit; i++){
        prime[i] = true;
        }

        for (int i = 2; i*i <= limit;i++){
            if (prime[i]){
                for (int j = i*i; j <= limit; j += i){
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= limit; i++){
            if (isPrime(i)){
                cnt++;
            }
        }

        // Print the results
        System.out.println(cnt);
    }

    // Function to check if it is prime
    private static boolean isPrime(long num) {
        return prime[(int)num];
    }
}
