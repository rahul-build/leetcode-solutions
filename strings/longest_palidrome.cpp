class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count occurrences of each character
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                lower[s[i] - 'a']++;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                upper[s[i] - 'A']++;
            }
        }

        int count = 0;
        bool odd = false;

        // Count even parts and at most one odd character
        for (int i = 0; i < 26; i++)
        {
            if (lower[i] % 2 == 0)
            {
                count += lower[i];
            }
            else
            {
                count += lower[i] - 1;
                odd = true;
            }

            if (upper[i] % 2 == 0)
            {
                count += upper[i];
            }
            else
            {
                count += upper[i] - 1;
                odd = true;
            }
        }

        // Add 1 if there was any odd count (to place a central character)
        return count + (odd ? 1 : 0);
    }
};
Time and Space Complexity : Time Complexity : O(n) where n is the length of the string(we loop once through it and once through 26 letters).

                                              Space Complexity : O(1) because lower and upper vectors are of fixed size 26.