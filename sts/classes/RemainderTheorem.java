public class RemainderTheorem {

    // Method to evaluate the polynomial using the Remainder Theorem
    public static int evaluatePolynomial(int[] coefficients, int c) {
        int result = 0;
        int n = coefficients.length;

        // Evaluate f(c) = a0 * c^n-1 + a1 * c^n-2 + ... + an
        for (int i = 0; i < n; i++) {
            result += coefficients[i] * Math.pow(c, n - i - 1);
        }

        return result;
    }

    public static void main(String[] args) {
        // Hardcoded polynomial coefficients and value of c
        // Example: f(x) = 2x^3 + 3x^2 + 4x + 5
        int[] coefficients = {2, 3, 4, 5};
        int c = 2;

        // Calculate the remainder using the Remainder Theorem
        int remainder = evaluatePolynomial(coefficients, c);

        // Output the result
        System.out.println("The remainder when the polynomial is divided by (x - " + c + ") is: " + remainder);
    }
}
