class Solution {
    public int majorityElement(int[] arr) {
        int ans = -1, counter = 0;
        int n = arr.length;
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
        return ans;
    }
}