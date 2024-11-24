import java.util.*;

import static java.lang.Math.sqrt;
import static java.lang.Math.floor;
public class segsieve {
        public static void main(String[]args){
            Scanner input=new Scanner(System.in);
            int n= input.nextInt();
            int limit=(int) (floor(sqrt(n))+1);
            Vector<Integer> prime = new Vector<>();  
            boolean mark[] = new boolean[limit+1];
        
            for (int i = 0; i < mark.length; i++)
                mark[i] = true;
        
            for (int p=2; p*p<limit; p++)
            {
                if (mark[p] == true)
                {
                    for (int i=p*p; i<limit; i+=p)
                        mark[i] = false;
                }
            }
        
            for (int p=2; p<limit; p++)
            {
                if (mark[p] == true)
                {
                    prime.add(p);
                    System.out.print(p + "  ");
                }
            }

            int low=limit;
            int hi=limit*2;
            while(low<n){
                if(hi>=n){
                    hi=n;
                }
                boolean [] mark2=new boolean[limit+1];

                for(int i=0;i<n;i++){
                    mark2[i]=true;
                }
                for(int i=0;i<prime.size();i++){
                    int lolim=(int) floor(low/prime.get(i)*prime.get(i));
                    if(lolim<low){
                        lolim+=prime.get(i);
                    }
                    for (int j=lolim;j<hi;j+=prime.get(i)){
                        mark[j-low]=false;
                    }
                    
                }
                for(int i=low;i<hi;i++){
                    if(mark[i-low]==true){
                        System.out.println(i+" ");
                    }       
                }
                low=low+limit;
                hi=hi+limit;
            }

            input.close();

        
        }
    }
