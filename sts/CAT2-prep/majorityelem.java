public class majorityelem {
    //elements that appear more than n/2 times
    public static int major(int [] arr){
        int n=arr.length;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
            if(count>n/2){
                return arr[i];
            }
        }
        return -1;
        
    }
    public static void main(String []args){
        int [] arr={1,1,1,1,2,2};
        System.out.println(major(arr));
    }
}
