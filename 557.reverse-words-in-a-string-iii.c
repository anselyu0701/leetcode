/*
 * @lc app=leetcode id=557 lang=c
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
void swap(char *s, int p1, int p2)
{
    char temp;
    temp = s[p1];
    s[p1] = s[p2];
    s[p2] = temp;
    p1++;
    p2--;
    if (p1 <= p2)
    {        
        swap(s, p1, p2);
    }
}
char * reverseWords(char * s){
    int p1 = 0;
    int p2 = 1;

    while (1)
    {
        if (s[p2] == ' ')
        {
            swap(s, p1, p2-1);
            p1 = p2 + 1;
            p2 = p2 + 2;
        }
        else if (s[p2] == '\0')
        {
            swap(s, p1, p2-1);
            break;
        }
        else
        {
            p2++;
        }
    }
    return s;
}
// @lc code=end

