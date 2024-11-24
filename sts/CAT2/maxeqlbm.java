import java.util.*;
public class maxeqlbm {
    public static int findmax(int [] arr,int n){
        int res=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            int pre=arr[i];
            for(int j=0;j<i;j++){
                pre+=arr[j];
            }
            int suf=arr[i];
            for(int j=n-1;j>i;j--){
                suf+=arr[j];
            }
            if(pre==suf){
                res=Math.max(res,pre);
            }
        }
        return res;
    }
    public static void main(String args[]){
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int [] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=input.nextInt();
        }
        System.out.println(findmax(arr,n));
        input.close();
    }
}
