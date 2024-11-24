public class karatsuba {
    public static long kara(long x, long y) {
        if (x < 10 || y < 10) {
            return x * y;
        }

        int n = Math.max(Long.toString(x).length(), Long.toString(y).length());
        int m = n / 2;  
        long high1 = x / (long) Math.pow(10, m);
        long low1 = x % (long) Math.pow(10, m);
        long high2 = y / (long) Math.pow(10, m);
        long low2 = y % (long) Math.pow(10, m);
        long z0 = kara(low1, low2);                    
        long z1 = kara(low1 + high1, low2 + high2);    
        long z2 = kara(high1, high2);                  
        return (z2 * (long) Math.pow(10, 2 * m)) + ((z1 - z2 - z0) * (long) Math.pow(10, m)) + z0;
    }

    public static void main(String[] args) {
        long x = 123456789;  // Example number 1
        long y = 987654321;  // Example number 2

        long result = kara(x, y);
        System.out.println("Karatsuba multiplication result: " + result);
    }
}
