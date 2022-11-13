class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double Kelvin = celsius + 273.15 ;
        double Fahrenheit = celsius * 1.80 + 32.00;
        vector<double> ans;
        ans.push_back(Kelvin);
        ans.push_back(Fahrenheit);
        return ans;
    }
};