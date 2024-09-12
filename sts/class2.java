
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int unit  = input.nextInt();
        int price = unit * 100;
        if (price > 1000) {
            System.out.println(price - price*0.1);
        } else {
            System.out.println(price);
        }
        input.close();
    }

}