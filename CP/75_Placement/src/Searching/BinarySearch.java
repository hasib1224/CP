package Searching;

import java.lang.reflect.Array;
import java.util.Arrays;

public class BinarySearch {

    //This will find exactly the first index of any value
    public static int search(int[]num, int value){
        int result = 0;
        int low=0; int high =num.length-1;
        int tempAns =-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(num[mid]>value){
                high = mid-1;
            } else if (num[mid]<value) {
                low=mid+1;
            } else if (num[mid]==value) {
                high =mid-1;
                tempAns=mid;
            }
        }

        if(tempAns!=-1){
            return tempAns;
        }else if(high>=0 && num[high]>value){
            return high;
        } else if (num.length>low && num[low]>value) {
            return low;
        }

        return -1;
    }


    public static void main(String[] args) {
        int[]num={25,19,30,37,14,30,38,22,38,38,26,33,34,23,40,28,15,29,36,39,39,37,32,38,8,17,39,20,4,39,39,7,30,35,29,23};
        Arrays.sort(num);
        int index = search(num,23);

//        for(int x: num){
//            System.out.println(x);
//        }

        System.out.println(index+","+num.length);




    }
}
