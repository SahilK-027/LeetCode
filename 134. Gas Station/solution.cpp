/*
83 ms
69.5 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief :  Linear traversal
*/

class Solution {
private:
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start_sation = 0;
        int net_gas_balance = 0;
        int gas_deficit = 0;
        for(int i = 0 ; i < n ; i++){
            net_gas_balance += gas[i] - cost[i];
            if(net_gas_balance < 0){
                // Negactive balanace
                // Step 1: Calculate how much deficiency of gas is there
                gas_deficit += net_gas_balance;
                // Step 2: Start from next station
                int next_station = i + 1;
                start_sation = next_station;
                // Step 3: Make initial balanace again 0 as we starting tour from next station
                net_gas_balance = 0;
            }
        }
        // Step 4: Find remaining gas after visiting last station
        int remaining_gas = gas_deficit + net_gas_balance;
        if(remaining_gas >= 0){
            // Travel is possible from where ever we started
            return start_sation;
        }
        else
        {
            // Travel is not possible
            return -1;
        }
    }
};