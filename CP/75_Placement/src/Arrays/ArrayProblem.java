package Arrays;

import Graph.Graph;

import java.util.ArrayList;
import java.util.Arrays;

public class ArrayProblem {
    public static int compress(char[] chars) {
        char[]temp=new char[chars.length];
        temp[0]=chars[0];
        int tem=1;
//        char charValue = (char)tem;
//        System.out.println(charValue);
        for(int i=1,j=1;i<chars.length;i++){
            if(chars[i]==temp[i-1]){
                tem++;
                if(i==chars.length-1){
                    temp[j++]=(char)(tem+'0');
                    break;
                }
            }else if(tem!=1){
                temp[j++]=(char)(tem+'0');
                if(i!=chars.length-1){
                    System.out.println();
                    temp[j++]=chars[i];
                }
                tem=1;
            }else if(tem==1){
                temp[j++]=chars[i];
            }
        }
        chars= Arrays.copyOf(temp,temp.length);
        System.out.println(chars);
        return chars.length;
    }


    public static void main(String []args){

        char[]  ar ={'t','t','r','r',};

        System.out.println(compress(ar));
    }
}



