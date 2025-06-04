class Solution {
public:
int brokenCalc(int startValue, int target) {
     int operations=0;
     if(target<=startValue)return startValue-target;
     if(target&1){
        target++;
        operations++;
     }
     while (target>startValue)
     {
        target/=2;
        operations++;
        if(target&1 && target>startValue){
            target++;
            operations++;
        }
     }
     return operations+startValue-target; 
    }
};