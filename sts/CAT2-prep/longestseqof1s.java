import java.util.*;
public class longestseqof1s {
    public static int longseq(int x){
        int prev=0;
        int cur=0;
        int max=0;
        while(x>0){
            if((x&1)==1){
                cur++;
            }
            else{
                max=Math.max(prev+cur+1,max);
                prev=cur;
                cur=0;
            }
            x>>=1;
            
        }
        max=Math.max(max,prev+cur+1);
        return max;
    }
    public static void main(String []args){
        System.out.println(longseq(1775));
    }
}
