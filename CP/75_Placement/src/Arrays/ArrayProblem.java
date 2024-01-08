package Arrays;

import Graph.Graph;

import java.util.ArrayList;
import java.util.Arrays;

public class ArrayProblem {

    //gcd of string
    public static String gcdOfStrings(String str1, String str2) {
        // Check if concatenated strings are equal or not, if not return ""
        if (!(str1 + str2).equals(str2 + str1))
            return "";
        // If strings are equal than return the substring from 0 to gcd of size(str1), size(str2)
        int gcd = gcd(str1.length(), str2.length());
        return str1.substring(0, gcd);
    }

    //gcd function
    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    //merge two string
    public static String mergeAlternately(String word1, String word2) {
        //string builder to append easily
        StringBuilder str = new StringBuilder();
        int index=0;

        //string length
        while(index<word1.length() || index<word2.length()){
            if(index<word1.length()){
                str.append(word1.charAt(index));
            }
            if(index<word2.length()){
                str.append(word2.charAt(index));
            }
            index++;
        }
        return str.toString();
    }


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



