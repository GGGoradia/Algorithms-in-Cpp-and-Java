//last two digits 01 then add the multiplicand to the accumulator
//last two digits 10 then subtract the multiplicand from the accumulator
public class booths {
    static int boothMulti(int multiplicand,int multiplier){
        int A=multiplicand;
        int Q=multiplier;
        int M=multiplicand;
        int count=Integer.toBinaryString(multiplier).length();
        int qmin=0;
        int acc=0;
        while(count>0){
            int lastbit=Q&1;//gives least signi digit
            if(lastbit==1 && qmin==0){
                acc-=M;
            }
            else if(lastbit==0 && qmin==1){
                acc+=M;
            }
        }
        return 0;
    }
    public static void main(String[] args){

    }    
}