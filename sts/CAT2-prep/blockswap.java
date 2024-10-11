public class blockswap {
    static void swapBlocks(int[] arr, int start1, int start2, int size) {
        for (int i = 0; i < size; i++) {
            int temp = arr[start1 + i];
            arr[start1 + i] = arr[start2 + i];
            arr[start2 + i] = temp;
        }
    }
    static void blockSwap(int[] arr, int k) {
        int n = arr.length;
        k = k % n;
        if (k == 0 || k == n) return; 

        int i = k;
        int j = n - k;

        while (i != j) {
            if (i < j) {
                swapBlocks(arr, k - i, k + j - i, i);
                j -= i;
            } else {
                swapBlocks(arr, k - i, k, j);
                i -= j;
            }
        }
        swapBlocks(arr, k - i, k, i);
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int k = 3;
        System.out.println("Original array: ");
        printArray(arr);
        blockSwap(arr, k);
        System.out.println("Array after rotation: ");
        printArray(arr);
    }
    static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}