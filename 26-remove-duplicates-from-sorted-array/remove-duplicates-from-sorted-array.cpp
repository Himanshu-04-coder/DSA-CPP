class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n= arr.size();
        int l=0;
        int h=1;
        int res = 1;
        while(h<n){
            if(arr[h]==arr[h-1]){
                h++;
                continue;  // agar condition match hui to iss loop ke next codes implement nhi 
                           // honge balki agle iteration pr badh jayega
            }
            arr[l+1]= arr[h]; //
            l++;              //
            res++;            //
            h++;              //
        }
        return res;
    }
};