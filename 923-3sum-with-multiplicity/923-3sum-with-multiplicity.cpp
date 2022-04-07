class Solution {
public:   
    int threeSumMulti(vector<int>& arr, int target) {
        
        sort( arr.begin(), arr.end() ); 
        vector<int> freq(101, 0) ;
        for(auto i : arr){
            freq[i]++;
        }
        int prev = -1; vector<int> vec;
        for(int i = 0; i < arr.size(); i++){
            if(prev != arr[i]){
                vec.push_back(arr[i]);
                prev = arr[i];
            }
        }
        int mod = 1e9 + 7;
        long long int count = 0;
        for(int i = 0; i < vec.size(); i++){
            int key = target - vec[i];
            for(int j = i, k = vec.size()-1; j <= k; ){
                int sum = vec[j] + vec[k];
                if( sum == key )
                {
                    if(i == j and j == k){
                        if( freq[ vec[i] ] == 3 )
                            count++;
                        else if( freq[ vec[i] ] > 3 )
                            count += NcR(freq[ vec[i] ], 3);
                    }
                    else if(i == j and j != k){
                        if( freq[ vec[i] ] == 2 )
                            count += freq[ vec[k] ];
                        else if( freq[ vec[i] ] > 2 )
                            count += NcR(freq[ vec[i] ], 2) * freq[ vec[k] ];
                    }
                    else if(i != j and j == k){
                        if( freq[ vec[j] ] == 2 )
                            count += freq[ vec[i] ];
                        else if( freq[ vec[j] ] > 2 )
                            count += NcR(freq[ vec[j] ], 2) * freq[ vec[i] ];
                    }
                    else if(i != j and j != k and i != k){
                            count += freq[ vec[i] ] * freq[ vec[j] ] * freq[ vec[k] ];
                    }
                    // cout<<vec[i]<<" "<<vec[j]<<" "<<vec[k]<<" count = "<<count<<endl;
                    j++;
                }
                else if( sum < key )
                    j++;
                else if( sum > key )
                    k--;
            }
        }
        return count % mod;
    }

//Initialise array elements with zero
// long long int NcR(int n, int r)
// {
//        if(n==r) return dp[n][r] = 1; //Base Case
//        if(r==0) return dp[n][r] = 1; //Base Case
//        if(r==1) return dp[n][r] = n;
//        if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
//        long long int a = NcR(n-1,r) ;
//        long long int b = NcR(n-1,r-1);
//        return dp[n][r] = a + b;
// }
    // Function to find the nCr
    long long NcR(int n, int r)
    {   
    
        // p holds the value of n*(n-1)*(n-2)...,
        // k holds the value of r*(r-1)...
        long long p = 1, k = 1;           
        
        // C(n, r) == C(n, n-r),
        // choosing the smaller value
        if (n - r < r)
            r = n - r;

        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;

                // gcd of p, k
                long long m = __gcd(p, k);

                // dividing by gcd, to simplify
                // product division by their gcd
                // saves from the overflow
                p /= m;
                k /= m;

                n--;
                r--;
            }

            // k should be simplified to 1
            // as C(n, r) is a natural number
            // (denominator should be 1 ) .
        }

        else
            p = 1;

        // if our approach is correct p = ans and k =1
        //cout << p << endl;
        return p;
    } 
};