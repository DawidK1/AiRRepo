#include "strtype.c"

using namespace std;


void StrType::MakeEmpty()

// Post: letters is empty string.

{

letters[0] = '\0';

}

void StrType::GetStringFile(bool skip, InType charsAllowed,std::ifstream& inFile)

{

 switch (charsAllowed)

 {

case ALPHA_NUM : GetAlphaNum(skip, letters, inFile);

       break;

case ALPHA : GetAlpha(skip, letters, inFile);

          break;

case NON_WHITE : GetNonWhite(skip, letters, inFile);

     break;

case NOT_NEW : GetTilNew(skip, letters, inFile);

  break;

 }
}
 
 void StrType::GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)

// Post: If skip is true, non-alphanumeric letters are skipped.

// Alphanumeric characters are read and stored until a

// non-alphanumeric character is read or MAX_CHARS characters

// have been stored. If the stream is not in the fail state,

// the last character read was a non-alphanumeric character.

{



  char letter;

  int count = 0;

  if (skip)

  {// Skip non-alphanumeric characters.

    inFile.get(letter);

    while (!isalnum(letter) && inFile)

    inFile.get(letter);

  }

 else

   inFile.get(letter);

 if (!inFile || !isalnum(letter))

 // No legal character found; empty string returned.

    letters[0] = '\0';

 else

 {// Read and collect characters.

   do

    {

      letters[count] = letter;

      count++;

      inFile.get(letter);

    } while (isalnum(letter) && inFile && (count < MAX_CHARS));

   letters[count] = '\0';

  // Skip extra characters if necessary.

  if (count == MAX_CHARS && isalnum(letter))

  do

   {

     inFile.get(letter);

    } while (isalnum(letter) && inFile);

  }

}

 

 

void StrType::GetTilNew(bool skip, char letters[], std::ifstream& inFile)

// Post: If skip is true, newline characters are skipped.

// All characters are read and stored until a newline

// character is read or MAX_CHARS characters have been

// stored. If the stream is not in the fail state, the

// last character read was a newline character.

{



char letter;

int count = 0;

if (skip)

 {// Skip newlines.

  inFile.get(letter);

  while ((letter == '\n') &&inFile)

  inFile.get(letter);

}

 else

   inFile.get(letter);

if (!inFile || letter == '\n')

  letters[0] = '\0';

else

 {// Read and collect characters.

 do

  {

    letters[count] = letter;

    count++;

    inFile.get(letter);

  } while ((letter != '\n') && inFile && (count < MAX_CHARS));

 letters[count] = '\0';

// Skip extra characters if necessary.

 if (count == MAX_CHARS && letter != '\n')

  do

    {

      inFile.get(letter);

    } while ((letter != '\n') && inFile);

  }

}

void StrType::PrintToScreen(bool newLine)

// Post: letters has been sent to the output stream.

{

using namespace std;

if (newLine)

  cout << endl;

 cout << letters;

}
 
 
 void StrType::CopyString(StrType& newString)

// Post: letters has been copied into newString.letters.

{

std::strcpy(newString.letters, letters);

}

 

int StrType::LengthIs()

// Post: Function value = length of letters string

{

return std::strlen(letters);

}