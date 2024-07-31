import java.util.*;

class class1{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int seat = input.nextInt();
        int r = seat % 8;
        if (r == 1 || r == 4) {
            System.out.println("Lower Berth");
        } else if (r == 2 || r == 5) {
            System.out.println("Middle Berth");
        } else if (r == 3 || r == 6) {
            System.out.println("Upper Berth");
        } else if (r == 7) {
            System.out.println("Side Lower Berth");
        } else if (r == 0) {
            System.out.println("Side Upper Berth");
        }
        input.close();
    }
}