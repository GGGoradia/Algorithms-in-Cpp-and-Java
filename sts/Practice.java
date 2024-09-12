import java.util.*;
public class Practice {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x;
        String y;
        
        x = input.nextInt();
        input.nextLine();  // Consume the leftover newline character
        y = input.nextLine();
        
        System.out.println(x);
        System.out.println(y);
        input.close();
    }
}

