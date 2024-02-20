class Solution {
public:
    bool isPowerOfTwo(int n) {
        double result = 0;
        int i = 0;
        while(result<n){
            if(pow(2,i)==n){
                
                return true;
                i++;
            }
            else{
                result = pow(2,i);
                i++;
            }
           
        }
        
        return false;
        
    }
};