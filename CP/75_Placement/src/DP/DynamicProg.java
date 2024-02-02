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

    public static int findProfit2(int[]prices,int index,int buy, int[][]profitIndex){

        if(index>=prices.length){
            return 0;
        }
        if(profitIndex[index][buy]!=-1){
            return profitIndex[index][buy];
        }

        int profit=0;
        if(buy==1){
            profit=Math.max(-prices[index]+findProfit2(prices,index+1,0,profitIndex),findProfit2(prices,index+1,1,profitIndex));


        }else{
            profit=Math.max(prices[index]+findProfit2(prices,index+1,1,profitIndex),findProfit2(prices,index+1,0,profitIndex));
        }

        return profitIndex[index][buy]=profit;
    }

    public static int maxProfit2(int[] prices) {
        int n = prices.length;
        int[][]profitIndex=new int[n][2];
        for (int i = 0; i <n; i++) {
            profitIndex[i][0]=-1;
            profitIndex[i][1]=-1;
        }
        if(prices.length==1){
            return 0;
        }
        return findProfit2(prices,0,1,profitIndex);
    }



    static int findMaxCooldown(int[]prices,int index,int buy,int[][]profitArr){
        if(index==prices.length){
            return 0;
        }
        if(profitArr[index][buy]!=-100){
            return profitArr[index][buy];
        }

        int profit=0;
        if(buy==2){
            findMaxCooldown(prices,index+1,1,profitArr);
            profit=0;

        }else if(buy==1){
            profit=Math.max((-prices[index]+findMaxCooldown(prices,index+1,0,profitArr)),(0+findMaxCooldown(prices,index+1,1,profitArr)));
        }else if(buy==0){
            profit=Math.max((prices[index]+findMaxCooldown(prices,index+1,2,profitArr)),(0+findMaxCooldown(prices,index+1,0,profitArr)));
        }
        profitArr[index][buy]=profit;
        return profit;

    }
    public static int maxProfitCooldown(int[] prices) {

        int n=prices.length;
        int[][]profitArr=new int[prices.length][3];

        if(n==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                profitArr[i][j]=-100;
            }
        }
        return findMaxCooldown(prices,0,1,profitArr);

    }




    public static void main(String[]args){


    /////

    }




}





