class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg;
        vector<int> pos;
        
        for(int i=0; i<n;i++){ // separating negative and positive array
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }

        int a = neg.size();
        int b = pos.size();

        // if(a==0){                   // when there is no negative value
        //    for(int i=0; i<b;i++){
        //         pos[i]=pos[i]*pos[i];
        //     } 
        //     return pos;
        // }

        // if(b==0){                   // when there is no positive value
        //     for(int i=0; i<a; i++){
        //         neg[i]=neg[i]*neg[i];
        //         reverse(neg.begin(),neg.end());
        //         }
        //     return neg;
        // }

        for(int i=0; i<a; i++){    // both negative and positive values
            neg[i]=neg[i]*neg[i];}
        reverse(neg.begin(),neg.end()); //reverse

        for(int i=0; i<b;i++){
            pos[i]=pos[i]*pos[i];
        }

        // Merge Sorted arrays

        int i=0;
        int j=0;
        int id=0;
        vector<int> res(a+b);

        while(i<a and j<b){     
            if(neg[i]<=pos[j]){
                res[id] = neg[i];
                i++;
                id++;
            }
            else{
                res[id]= pos[j];
                j++;
                id++;
            }
        }
        while(i<a){              // if positive array fully traversed and negative left
            res[id] = neg[i];
                i++;
                id++;
        }
        while(j<b){              // if negative array fully traversed and positive left
            res[id] = pos[j];
                j++;
                id++;
        }
        return res;
    }
};