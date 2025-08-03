class Solution {
public:
    char kthCharacter(int k) {
        if(k==1){
            return 'a';
        }
        long long length=1;
        while(length<k){
            length*=2;
        }
        long long midpoint=length/2;
        if(k<=midpoint){
return kthCharacter(k);
        }
        else{
            char previous_char=kthCharacter(k-midpoint);
            if (previous_char == 'z') {
            return 'a';
        } else {
            return previous_char + 1;
        }
        }
    }
};