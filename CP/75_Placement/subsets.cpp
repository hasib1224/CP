#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> subsetas(vector<int>& nums) {
        vector<vector<int>> subsets;
        int subsetsCount=1<<nums.size();
        for(int i=0;i<subsetsCount;i++){
            vector<int>subset;
            int index=-1;
            while (i > 0) {
                index++;
                if ((i & 1) != 0) {
                    subset.push_back(nums[index]);
                }
                i = i >> 1;
            }            
            subsets.push_back(subset);
        }
        return subsets;

    }


int main(){
    cout<<"cbscb";
    // vector<int> nums={1,2,3};
    // cout<<"jdcbdjb";
    // vector<vector<int>>res=subsets(nums);

    // for(vector<int>a:res){
    //     for(int b:a){
    //         cout<<b<<" ";
    //     }
    // }
    
}