import java.util.Scanner;

public class booths {
    @SuppressWarnings("unused")
    public int multiply(int multiplicand, int multiplier) {
        int positiveMultiplicand = multiplicand;
        int negativeMultiplicand = -multiplicand;
        int product = 0;
        int bitsCount = Integer.SIZE;

        System.out.print(bitsCount);

        while (bitsCount > 0) {
            if ((multiplier & 1) == 1) {
                product += positiveMultiplicand;
            }
            positiveMultiplicand <<= 1;
            negativeMultiplicand <<= 1;
            bitsCount--;
            multiplier >>= 1;
        }
        return product;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        booths boothsMultiplier = new booths();
        System.out.println("Enter two integer numbers -");
        int firstNumber = scanner.nextInt();
        int secondNumber = scanner.nextInt();
        int result = boothsMultiplier.multiply(firstNumber, secondNumber);
        System.out.println("\n\nResult : " + firstNumber + " * " + secondNumber + " = " + result);
        scanner.close();
    }
}