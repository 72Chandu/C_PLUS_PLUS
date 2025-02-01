class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size(), i = 0;
        while (i < n) {
            int j = i, lineLength = 0;
            // Determine how many words fit in this line
            while (j < n && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            int spaces = maxWidth - lineLength;
            int numWords = j - i;
            string line;
            // If last line or only one word in the line
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k] + " ";
                }
                line.pop_back(); // Remove the last extra space
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                int evenSpaces = spaces / (numWords - 1);
                int extraSpaces = spaces % (numWords - 1);
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) { // Not adding space after the last word
                        int spaceCount =evenSpaces + (extraSpaces-- > 0 ? 1 : 0);
                        line.append(spaceCount, ' ');
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
/*
{"This", "is", "an", "example", "of", "text", "justification."}
maxWidth = 16
["This", "is", "an"] -> 4 (This) + 2 (is) + 2 (an) = 8
Required spaces: 16 - 8 = 8
Since we have 2 gaps between words, distribute spaces evenly
Each gap gets at least 8/2 = 4 spaces
*/
