 

#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <cstring>

const int MAX_CHARS = 100;

enum InType {ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW};

class StrType

{

  public:

// Assumptions:

// InType is a data type consisting of the following constants:

// ALPHA: only alphabetic characters are stored;

// ALPHA_NUM: only alphanumeric characters are stored;

// NON_WHITE: all nonwhitespace characters are stored;

// NOT_NEW: all characters excluding the newline character

// are stored.

// If skip is true, characters not allowed are skipped until the

// first allowed character is found. Reading and storing

// begins with this character and continues until a character

// not allowed is encountered. This character is read but not

// stored. If skip is false, reading and storing begins with

// the current character in the stream.

  void MakeEmpty();

  void GetString(bool skip, InType charsAllowed);

// Post: If the number of allowable characters exceeds

// MAX_CHARS, the remaining allowable characters have

// been read and discarded.

  void GetStringFile(bool skip, InType charsAllowed,std::ifstream& inFile);

// Post: If the number of allowable characters exceeds

// MAX_CHARS, the remaining allowable characters have been

// read and discarded.

  void PrintToScreen(bool newLine);

  void PrintToFile(bool newLine, std::ofstream& outFile);

  int LengthIs();

  void CopyString(StrType& newString);
  
  // Prototypes of auxiliary functions.

// Note: If skip is true, nonallowable leading characters are

// skipped. If end-of-file is encountered while skipping

// characters, the empty string is returned. If the number

// of allowable characters exceeds MAX_CHARS, the rest are

// read and discarded.

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);

// Post: letters array contains only alphanumeric characters.

void GetAlpha(bool skip, char letters[], std::ifstream& inFile);

// Post: letters array contains only alphabetic characters.

void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);

// Post: letters array contains only nonwhitespace characters.

void GetTilNew(bool skip, char letters[], std::ifstream& inFile);

// Post: letters array contains everything up to newline character.

 

  private:

    char letters[MAX_CHARS + 1];

};
