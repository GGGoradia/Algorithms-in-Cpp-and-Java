import java.util.*;
public class hourglass {
    public static int hover(int r,int c, List<List<Integer>>Mat){
        int sum=Mat.get(r+1).get(c+1);
        for(int i=0;i<3;i++){
            sum+=Mat.get(r).get(c+i);
            sum+=Mat.get(r+2).get(c+i);
        }
        return sum;
    }
    public static int findmaxsum(int n,int m,List<List<Integer>>Mat){
        int maxsum=-1;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                maxsum=Math.max(maxsum, hover(i, j, Mat));
            }
        }
        return maxsum;
    }
    public static void main(String[]args){
        List<List<Integer>> mat=new ArrayList<>();
        mat.add(List.of(1, 1, 1, 0, 0, 0));
        mat.add(List.of(0, 1, 0, 0, 0, 0));
        mat.add(List.of(1, 1, 1, 0, 0, 0));
        int n=mat.size();
        int m=mat.get(0).size();
        System.out.println(findmaxsum(n, m, mat));
    }
}