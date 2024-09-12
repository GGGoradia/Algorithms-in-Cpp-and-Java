import java.util.*;
class SegmentedSieve{
    static int N=10000;
    static boolean [] arr=new boolean[N];
    static void simplesieve(){
        for(int i=2;i<N;i++){
            arr[i]=true;
        }
        for(int i=2;i<Math.sqrt(N);i++){
            if(arr[i]==true){
                for(int j=i*i;j<N;j=j+i){
                    arr[j]=false;
                }
            }
        }

    }
    static ArrayList<Integer> generateprimes(int n){
        ArrayList<Integer>al=new ArrayList();
        for(int i=2;i<Math.sqrt(n);i++){
            if(arr[i]==true){
                al.add(i);
            }
        }
        return al;
    }
    public static void main(String [] args){
        int low=80;
        int high=90;
        simplesieve();
        ArrayList <Integer> al=generateprimes(high);
        boolean [] dum=new boolean[high-low+1];
        for(int i=0;i<high-low+1;i++){
            dum[i]=true;
        }
        for(int prime:al){
            int st=(low/prime)*prime;
            if(st<low){
                st+=prime;
            }
            int start=Math.max(st,prime*prime);
            for(int j=start;j<=high;j=j+prime){
                dum[j-low]=false;
            }
        }
        for(int i=low;i<high;i++){
            if(dum[i-low]==true){
                System.out.println(i);
            }
        }
    }
}