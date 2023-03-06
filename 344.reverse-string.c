/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start
void swap(char* s, int p1, int p2)
{
    char temp;
    temp = s[p1];
    s[p1] = s[p2];
    s[p2] = temp;
}
void reverseString(char* s, int sSize){
    int p1 = 0;
    int p2 = sSize - 1;
    while (p1 < p2)
    {
        swap(s, p1, p2);
        p1++;
        p2--;
    }
}
// @lc code=end

