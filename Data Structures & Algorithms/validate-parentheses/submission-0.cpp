class Solution {
public:
    bool isValid(string s) {
       stack<char> stack;
       unordered_map<char,char> closetoOpen={
        {')','('},
        {']','['},
        {'}','{'}
       };
       for(char c:s){
        if(closetoOpen.count(c)){
            if(!stack.empty()&&stack.top()==closetoOpen[c]){
                stack.pop();
            }
            else{
                return false;
            }
        }
        else stack.push(c);
       }
       return stack.empty();
    }
};
