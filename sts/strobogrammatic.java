import java.util.*;

class strobogrammatic {

  static ArrayList<String> numdef(int n, int length) {
    ArrayList<String> result = new ArrayList<String>();
    if (n == 0) {
      result.add("");
      return result;
    }
    if (n == 1) {
      result.add("1");
      result.add("0");
      result.add("8");
      return result;
    }

    ArrayList<String> middles = numdef(n - 2, length);

    for (String middle : middles) {
      if (n != length)
        result.add("0" + middle + "0");

      result.add("8" + middle + "8");
      result.add("1" + middle + "1");
      result.add("9" + middle + "6");
      result.add("6" + middle + "9");
    }

    return result;
  }

  static ArrayList<String> strobogrammatic_num(int n) {
    ArrayList<String> result = numdef(n, n);
    return result;
  }
  // Driver Code
  public static void main(String[] args) {
    // Print all Strobogrammatic numbers for n = 2
    for (String num : strobogrammatic_num(4))
      System.out.print(num + " ");
  }
}
