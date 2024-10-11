import java.util.*;
public class arrleaders {
    public static ArrayList<Integer> leaders(int []arr){
        ArrayList<Integer> result =new ArrayList<>();
        int n=arr.length;
        for(int i=0;i<n;i++){
            int j;
            for(j=i;j<n;j++){
                if(arr[i]<arr[j]){
                    break;
                }
            }
            if(j==n){
                result.add(arr[i]);
            }
        }
        return result;
    }
    public static void main(String [] args){
        int []arr={14,2,3,5,1,3};
        ArrayList<Integer> res=leaders(arr);
        for(int i:res){
            System.out.println(i+" ");
        }
    }
}
