package DP;

public class DynamicProg {
    static int NthTribonacci(int n,int[]memo){
        if(n==1 || n==0 ||n==2){
            return memo[n];
        }
        if(memo[n]>0){
            return memo[n];
        }

        memo[n]=NthTribonacci(n-1,memo)+NthTribonacci(n-2,memo)+NthTribonacci(n-3,memo);
        if(n==3){
            System.out.println(NthTribonacci(n-1,memo)+NthTribonacci(n-2,memo)+NthTribonacci(n-3,memo));

        }

        return memo[n];

    }

    public static int tribonacci(int n) {
        int[]memo=new int[n+1];
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }else if(n==2){
            return 1;
        }
        for(int i=0;i<=n;i++){
            memo[i]=0;
        }
        memo[1]=1;
        memo[2]=1;

        return NthTribonacci(n,memo);

    }

    public  static  void main(String[]args){
        System.out.println(tribonacci(4));
    }
}
