package BitMasking;

import java.util.LinkedList;
import java.util.List;

public class bitMasking {
    static class Solution {
        public static List<List<Integer>> subsets(int[] nums) {
            List<List<Integer>> subsets = new LinkedList<>();
            int subsetsCount=(int)Math.pow(2,nums.length);
            System.out.println(subsetsCount);
            int index=-1;
            for(int i=0;i<subsetsCount;i++){
                List<Integer>subset=new LinkedList<>();
                index=-1;
                for(int j=0;j< nums.length;j++){
                    if((i&(1<<j))!=0){
                        subset.add(nums[j]);
                    }
                }
//                while (i > 0) {
//                    index++;
//                    if ((i & 1) != 0) {
//                        subset.add(nums[index]);
//                    }
//                    i = i >> 1;
//                }
                subsets.add(subset);
            }
            return subsets;

        }
    }



    public static void main(String []args) {
        int[]nums={1,2,3};
        List<List<Integer>>ans=Solution.subsets(nums);

        for(List<Integer>a:ans){
            for(Integer b:a){
                System.out.print(b);
            }
            System.out.println(" ");
        }

    }
}
