/*
Question - https://www.geeksforgeeks.org/problems/implement-atoi/1

Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and rest are numeric.

Example 1:

Input:
s = "-123"
Output:
-123
Explanation:
It is possible to convert -123 into an integer
and is so returned in the form of an integer
Example 2:

Input:
s = "21a"
Output:
-1
Explanation:
The output is -1 as, due to the inclusion of 'a',
the given string cannot be converted to an integer.
Your Task:
You do not have to take any input or print anything. Complete the function atoi() which takes a string s as an input parameter and returns an integer value representing the given string. If the conversion is not feasible, the function should return -1.

|s| = length of string str.
Expected Time Complexity: O( |s| ),
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |s| ≤ 10

*/

/*Approach -
1.) Take an ans integer initialized to zero and a boolean variable initialized to false to check if the number is negative or not.
2.) Iterate each character, if the first character is '-', mark the boolean variable as true
                           if(current character >= 0 and <= 9) ans*10 + current character;
                           if(current character is other than 0-9 (means it is a symbol of a string character)) it is not convertible return -1
3.) If the boolean is marked as true multiply answer with -1.
4.) Return the answer.
*/

int atoi(string s)
{
    int num = 0;
    bool negative = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 && s[i] == '-')
        {
            negative = true;
        }
        else if (s[i] == '1')
        {
            num = num * 10 + 1;
        }
        else if (s[i] == '2')
        {
            num = num * 10 + 2;
        }
        else if (s[i] == '3')
        {
            num = num * 10 + 3;
        }
        else if (s[i] == '4')
        {
            num = num * 10 + 4;
        }
        else if (s[i] == '5')
        {
            num = num * 10 + 5;
        }
        else if (s[i] == '6')
        {
            num = num * 10 + 6;
        }
        else if (s[i] == '7')
        {
            num = num * 10 + 7;
        }
        else if (s[i] == '8')
        {
            num = num * 10 + 8;
        }
        else if (s[i] == '9')
        {
            num = num * 10 + 9;
        }
        else if (s[i] == '0')
        {
            num = num * 10;
        }
        else
        {
            return -1;
        }
    }

    if (negative)
    {
        num = num * (-1);
    }
    return num;
}