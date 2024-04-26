/* From LeetCode, Palindrome */

bool isPalindrome(int x) {
    int placeholder;

    if(x < 0){
        return false;
    }

    int rev=0;
    int orig=x;
    while(x!=0){
        placeholder = x%10;
        rev = rev * 10LL + placeholder;
        x/=10;
    }

    if(orig==rev){
        return true;
    }
    return false;
}
