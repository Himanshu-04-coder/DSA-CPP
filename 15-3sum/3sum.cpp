class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            if(i>0 && a[i]==a[i-1]){
                // i++;
                continue;
            }
            int j=i+1, k=n-1;
            while(j<k){
                int s= a[j]+a[k];
                int sum = -1*a[i];
                if(s==sum){
                    res.push_back({a[i], a[j], a[k]});
                    j++;
                    k--;
                    while(j<n && a[j]==a[j-1]){
                        j++;
                    }
                    while(k>=0 && a[k]==a[k+1]){
                        k--;
                    }
                }
                else if(s<sum){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return res;
    }
};