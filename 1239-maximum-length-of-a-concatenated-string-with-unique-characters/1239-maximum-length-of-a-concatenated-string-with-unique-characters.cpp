class Solution {
public:
int n;
int solve(int idx,vector<bool>&letters,vector<string>&arr){
    // basecase
    if(idx==n){
        int cnt=0;
        for (int i = 0; i < 26; i++)cnt+=(letters[i]==1);
        return cnt;
    }
    // .i am at index idx , i have to check whether characters of arr[idx] has already visited 
    int ans=solve(idx+1,letters,arr);
    bool taken=false;
    vector<bool>seen(26,0);

    // first check within arr[idx]

    for (int i = 0; i < arr[idx].length(); i++)
    {
        if(seen[arr[idx][i]-'a']==1){
            taken=true;
            break;
        }
        seen[arr[idx][i]-'a']=1;
    }

    if(taken==false){
        // i can take string arr[idx] now check it with prev
        for (int i = 0; i < arr[idx].length(); i++){
            if(seen[arr[idx][i]-'a']==1 && letters[arr[idx][i]-'a']==1){
                taken=true;
                break;
            }
        }
        if(!taken){
            for (int i = 0; i < arr[idx].length(); i++){
                letters[arr[idx][i]-'a']=1;
            }           
            ans=max(ans,solve(idx+1,letters,arr));
            for (int i = 0; i < arr[idx].length(); i++){
            letters[arr[idx][i]-'a']=0;
        }
        }
    }
    return ans;
}
int maxLength(vector<string>& arr) {
     n=arr.size();
     
        // story = i have some string s till idx i-1,then at any index i , i can concatenate it with arr[i] or move further without joining . if i join , i have to check there must be unique character in resulting string (instead of string , i can take their index while joining)
    
    string prev="";
    vector<bool>letters(26,0);
    return solve(0,letters,arr);
    }
};