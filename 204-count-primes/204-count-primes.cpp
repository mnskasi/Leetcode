class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n+1,0);
        int cnt = 1;
        if (n < 2) {
            return 0;
        }
        for (int i =2;i<=n;i+=2) {
            arr[i] = 1;
        }
        arr[2] = 0;
        for (int i =3;i<=n;i+=2) {
            if (arr[i] == 0) {
                cnt++;
                for (int j = i + i;j<=n;j+=i) {
                    arr[j] = 1;
                }
            }
        }
        if (arr[n] == 0) {
            return cnt - 1;
        }
        return cnt;
    }
};