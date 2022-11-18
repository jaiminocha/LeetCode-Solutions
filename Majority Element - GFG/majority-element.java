//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Geeks
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
             arr[i] = sc.nextInt();
             
           System.out.println(new Solution().majorityElement(arr, n)); 
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    static int majorityElement(int arr[], int n)
    {
        
        int ans = -1, counter = 0;

        for (int i = 0; i < n; i++){
            if (counter == 0 && ans != arr[i]){
                ans = arr[i];
                counter++;
            }
            else if(ans == arr[i]) {
                counter++;
            }
            else {
                counter--;
            }
        }
        counter = 0;
        for (int i = 0; i < n; i++){
            if (ans == arr[i]){
                counter++;
            }
        }
        if (counter <= n / 2) return -1;
        return ans;
    }
}