/*Store the characters count of a string in an unordered map which allows operations in constant time.
Then, print the characters which have a frequency greater than 1.*/
void printDups(string str){
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;// increase the count of character str[i] by 1
    }
    for (auto it : count) {// iterating through the unordered map
        if (it.second > 1) cout << it.first << ", count = " << it.second<< "\n";// if the count of characters is greater than 1 then duplicate found
    }
}
/*Time Complexity: O(N), where N = length of the string passed and it takes O(1) time to insert and access any element in an unordered map
Auxiliary Space: O(K), where K = size of the map*/

/*If we sort the string then all duplicates will come together in the string. Then, traverse the string from starting index to the ending index and 
check if the neighbor character is same then increment the count by 1.*/

void printDuplicates(string str){
    int len = str.length();
    sort(str.begin(), str.end());
    for (int i = 0; i < len; i++) {
        int count = 1;
        while (i < len - 1 && str[i] == str[i + 1]) {// Counting the occurrences of each character
            count++;
            i++;
        }
        if (count > 1) {// Printing the duplicate character and its count
            cout << str[i] << ", count = " << count << endl;
        }
    }
}
/*Time Complexity: O(N*logN), where n is the length of the string 
Auxiliary Space: O(1), if you observe we did not use any extra space.*/