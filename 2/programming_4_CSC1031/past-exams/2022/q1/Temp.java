import java.util.Scanner;
import java.util.Convert;

public class Temp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Give me a Fahrenheit temperature: ");
        double ftemp = scanner.nextFloat();
        double temp = Convert.fahr2cels(ftemp);
    }
}
