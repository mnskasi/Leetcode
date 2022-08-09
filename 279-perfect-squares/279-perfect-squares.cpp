class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n+1,0);
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2;i<= n;i++) {
            int temp = sqrt(i);

            int mn = INT_MAX;
            for (int j = temp;j>0;j--) {
                if (mn > arr[i - j*j]) {
                    mn = arr[i - j*j];
                }
            }
            arr[i] = mn + 1;
        }

        return arr[n];
    }
};