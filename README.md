## Operating Systems Pre-Requisite Assignment: Dictionary Trie

---

#### Summary:

The dictionary tree is a tree storing a set of words (or strings), with each word stored along a
tree path. Starting from the child nodes of the root node, each tree node represents a single
character or letter of the word. Each node contains a collection of child nodes representing the
next set of possible characters to continue the word from the current node. A dictionary tree
constructed this way supports very efficient search and insert operations, in O(K) time with K
being the length of the word searched or inserted.
For this implementation, valid word characters are:

- alphabet characters from a to z (note: big case letters A to Z would be equivalent to
  a to z, all operations should be case-insensitive, as well as the autograding part)
- the apostrophe ' character.

## Table of Contents

1. [General Info](#general-info)
2. [Technologies](#technologies)
3. [Preparation](#preparation)
4. [Collaboration](#collaboration)

### General Info

---

Main program
With the dictionary tree implementation, the main program will:

- Read words from a dictionary text file and insert them to a dictionary tree.
- Read words from test text file, and for each word read in: search, count, and print the number of words in the dictionary tree that start with it.

Main(int argc, char \*\*argv) function should expect two arguments. The first argument is
the file path to the dictionary source text file, the second is for the file path to the test text file. Minimal error checking is required, fail gracefully when there are the wrong number of
arguments, or a file does not exist.

## Technologies

To extract all words from each line read in, strtok() function from <string.h> was used to
parse each line buffer read from the file. The strtok function iterates across a buffer, pulling out
groups of characters separated by a list of characters called delimiters (see snippet below for an
example).

The following delimiter string used to separate words:
const char _delimiters = "\n\r !\"#$%&()_+,-./0123456789:;<=>?@[\\]^\_`{|}~";

## Preparation

---

- Effectively open files passed through command line to be used for building the dictionary trie and search the trie as well.

- Ensure proper tokenization of each line read from files.

- Ensure characters from each tokenized words are properly inserted into the dictionary trie.

- Characters [a-z and '] are stored in indexes [0-26] of node arrays in the dictinary trie.

- After storing all words from dictionary source file, open test file to read and tokenize lines.

- Search the tokenzied words from test files in the dictionary trie and return the node corresponding to the last character of the word, if word is in the trie.

- Nodes in dictionary trie use flag isWord to determine if path from root node to each node is a word from the dictionary trie.

- Apply depth first search on returned node to count the number of words that begin with the tokenized word as a prefix.

- Stdout the word and the number of words in the tree that start with that word as prefix.

- Run tests using provided files as well as testing through gradescope to ensure all test cases have been met and passed.

- Account for hidden test features not provided in testing files.

## Collaboration

---

Solo collaboration to properly develop a dictionary trie that passes
all test cases when reading records.

Omar Martinez (REDID:818749029) - Contribution:
