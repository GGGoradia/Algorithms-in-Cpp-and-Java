import java.util.*;
public class simplesieve{
    public static void main(String []args){
        Scanner inp=new Scanner(System.in);
        int num=inp.nextInt();
        boolean [] bool = new boolean[num];
        for(int i=0;i<bool.length;i++){
            bool[i]=true;
        }
        for(int i=2;i<Math.sqrt(num);i++){
            for(int j=i*i;j<num;j=j+i){
                bool[j]=false;
            }
        }
        for(int i=0;i<num;i++){
            if(bool[i]==true){
                System.out.println(i);
            }
        }
        inp.close();
    }
}