 /**
 *  main.cpp
 *  - Implements dictionary Class and functions create dictionary trie.
 *  - Reads files provided as command line arguments.
 *  - Dictionary file creates the dictionary trie.
 *  - Test files are used for searching words inside dictionary trie.
 *  - Outputs the # of words that begin with string we are searching.
 *  @course: [CS480-01 : (Professor: B. Shen)]
 *  @authors:
 *      - [Omar Martinez(REDID:818749029)]
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "dictionary.h"

using namespace std;

// macro defining # of acceptable characters to be used.
#define NUMOfCHARS 27 /* a-z plus ' */ 
int main(int argc, char** argv){
    // create new DictNode pointer 
    DictNode* dictObj = new DictNode();
    // create ifstream object and open dictionary file
    ifstream dictStream(argv[1]);
    int count = 0;
    // delimiter string to separate words
    const char *delimiters = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
    // holds string read from each line of file
    string line_c;
    // read dictionary file line by line
    if(dictStream.is_open()){
        // loop through file
        while(getline(dictStream,line_c)){
            // create array of char
            char str[line_c.length()+1];
            // copy string to char array initialized with length of string
            strcpy(str,line_c.c_str());
            char* word = strtok(str,delimiters);
            // loop through each word of the line
            while(word != nullptr){
                // terminate program if word count not be added to tree.
                if(!dictObj->add(word)){
                    cout << "Word could not be inserted. Terminating program.\n";
                    return 1;
                }
                // read next token
                word = strtok(NULL,delimiters);
            }
        }
    }
    // end program if file not found/cannot be opened
    else{
        cout << "***ERROR OPENING FILE***"<<"\n";
        return 1;
    }
    //close dictionary file
    dictStream.close();
    //open test file
    dictStream.open(argv[2]);
    // read test file line by line
    if(dictStream.is_open()){
        // loop through file
        while(getline(dictStream,line_c)){
            // create array of char intialized with length of string
            char str[line_c.length()+1];
            // copy string to char array
            strcpy(str,line_c.c_str());
            char* word = strtok(str,delimiters);
            // loop through each word of the line
            while(word != nullptr){
                DictNode* nodeFound = dictObj->findEndingNodeOfAStr(word);
                if(nodeFound != NULL){
                    nodeFound->countWordsStartingFromANode(count);
                }
                // print word searched along with count
                cout << word << " " << count<<"\n";
                // reset count to 0;
                count = 0;
                // read next token
                word = strtok(NULL,delimiters);
            }
        }
    }
    // end program if file not found/cannot be opened
    else{
        cout << "***ERROR OPENING FILE***"<<"\n";
        return 1;
    }
    return 0;
}