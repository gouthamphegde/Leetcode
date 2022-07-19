class Solution {
public:
    
    int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
 
// Function to find gcd of array of
// numbers
int findGCD(vector<int> &arr)
{
  int result = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    result = gcd(arr[i], result);
 
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int gc = findGCD(numsDivide);
        
        sort(nums.begin(),nums.end());
        int counter = 0;

        
        for(int i = 0 ; i < nums.size() && nums[i] <= gc ;i++){
            if(gc%nums[i] == 0){
                return i;
            }

        }
        
        return -1;
        
    }
};