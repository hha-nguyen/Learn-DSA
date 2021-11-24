 #include <bits/stdc++.h>
    using namespace std;
    long int UnboundedKnapsack(long int W,long int n, long int weight[],long int val[]){
        long int dp[W+1];
        for(int i=0;i < W+1;i++){
            dp[i]=0;                            
        }
        for(int i=0;i < W+1;i++){
            for(int j=0;j < n;j++){
                if(weight[j] < i){
                    dp[i] = max(dp[i], dp[i-weight[j]] + val[j]);   
                }
            }
        }
        return dp[W];
    }
    int main(){
        //  The no. of items : 
        long int n, Capacity;
        //  Weights of all the items : 
        cin >> n >> Capacity;
        long int weight[n];
        //  Enter values of all the items : 
        long int val[n];
        // Enter the knapsack capacity : 
        for (int i = 0; i < n; ++i) {
            cin >> weight[i] >> val[i];
        }
        cout << "The maximum value you can achieve in Unbounded Knapsack is: " << UnboundedKnapsack(Capacity,n,weight,val);
        return 0;
    }