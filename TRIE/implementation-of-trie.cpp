/*
We’ll insert the word: "cat"
We assume:
Each node has 26 children (for letters 'a' to 'z'). 'a' is at index 0, 'b' at 1, ..., 'z' at 25. Root node is empty ("").

Step 1: Start at root
root
  |
  ∅
  
Step 2: Insert 'c' (index 2)
'c' - 'a' = 2 → child[2] is null, so create a new node.
root
  |
 [2] → 'c'
 
Step 3: Insert 'a' (index 0)
Move to 'c' node.
'a' - 'a' = 0 → child[0] is null, so create node for 'a'.
root
  |
 [2] → 'c'
         |
       [0] → 'a'

Step 4: Insert 't' (index 19)
Move to 'a' node.
't' - 'a' = 19 → child[19] is null, so create node for 't'.
root
  |
 [2] → 'c'
         |
       [0] → 'a'
                 |
               [19] → 't' (isEndOfWord = true ✅)

Now let's insert: "apple"

🔡 Character 1: 'a'
'a' - 'a' = 0
root.children[0] is nullptr → create new node for 'a'
(root)
  |
 [0] -- 'a'       [2] -- 'c'
 
🔡 Character 2: 'p'
Go to 'a' node
'p' - 'a' = 15  children[15] is nullptr → create node for 'p'
(root)
  |
 [0] -- 'a' -- [15] -- 'p'
          |
        ...
 [2] -- 'c'
         |
       [0] -- 'a'
                 |
               [19] -- 't' (✔️)
🔡 Character 3: 'p'
Move to the 'p' node
'p' - 'a' = 15 again → children[15] is nullptr, create new 'p' node
(root)
  |
 [0] -- 'a' -- [15] -- 'p' -- [15] -- 'p'

🔡 Character 4: 'l'
'l' - 'a' = 11   children[11] = nullptr → create new node for 'l'
(root)
  |
 [0] -- 'a' -- [15] -- 'p' -- [15] -- 'p' -- [11] -- 'l'

🔡 Character 5: 'e'
'e' - 'a' = 4
children[4] = nullptr → create node for 'e'
mark isEndOfWord = true ✅ at 'e' node

🔚 Final Trie Structure (after inserting "cat" and "apple"):
(root)
  |
 [0] -- 'a'
          |
        [15] -- 'p'
                 |
               [15] -- 'p'
                        |
                      [11] -- 'l'
                               |
                             [4] -- 'e' (✔️ "apple")
  |
 [2] -- 'c'
         |
       [0] -- 'a'
                 |
               [19] -- 't' (✔️ "cat")

*/
