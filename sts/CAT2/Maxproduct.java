public class Maxproduct
{public static int max(int [] a){
    int mx=a[0];
    int min=a[0];
    int m=a[0];
    int temp=0;
    for(int i=1;i<a.length;i++){
        if(a[i]>0){
            mx=Math.max(a[i],mx*a[i]);
            min=Math.max(a[i],min*a[i]);
        }
        else if(a[i]==0){
            mx=min=0;
        }
        else{
            temp=mx;
            mx=Math.max(a[i],a[i]*min);
            min=Math.max(a[i],a[i]*temp);
        }
        m=Math.max(m,mx);
    }
    return m;
}
public static void main (String[] args)
{   int a[]={-5,-4,-1,-2};
    int max=a[0],m=a[0],min=a[0],temp=0;
    for(int i=1;i<a.length;i++)
    {  
        if(a[i]>0)
        {
             max=Math.max(a[i],max*a[i]);
             min=Math.min(a[i],min*a[i]);
         }
        else if(a[i]==0)
             max=min=0;
        else
         {
             temp=max;
             max=Math.max(a[i],min*a[i]);
             min=Math.min(a[i],temp*a[i]);
         }
         m=Math.max(m,max);
    }
     System.out.println(m);
    }
}
