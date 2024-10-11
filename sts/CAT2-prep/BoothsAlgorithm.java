public class BoothsAlgorithm {
    public static int multiply(int multiplicand, int multiplier) {
        int product = 0;
        int negativeMultiplicand = -multiplicand;
        
        // We'll use the 32-bit two's complement representation
        for (int i = 0; i < 32; i++) {
            // Check the least significant bit of multiplier and the bit to its right
            int lsb = multiplier & 1;
            int lsbMinus1 = (multiplier & 2) >> 1;
            
            if (lsb == 1 && lsbMinus1 == 0) {
                // If '10', subtract multiplicand
                product -= (multiplicand << i);
            } else if (lsb == 0 && lsbMinus1 == 1) {
                // If '01', add multiplicand
                product += (multiplicand << i);
            }
            
            // Arithmetic right shift the multiplier
            multiplier = multiplier >> 1;
        }
        
        return product;
    }

    public static void main(String[] args) {
        int a = 5;
        int b = -3;
        System.out.println(a + " * " + b + " = " + multiply(a, b));
        
        a = -7;
        b = 6;
        System.out.println(a + " * " + b + " = " + multiply(a, b));
    }
}