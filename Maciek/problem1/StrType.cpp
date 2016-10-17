#include "StrType.h"
#include <cctype>
#include <cstring>



void StrType::MakeEmpty()
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


void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{
		inFile.get(letter);
		while (!isalnum(letter) && inFile)//isalnum zwraca wartosc rozna od zera gdy argument jest znakiem alfanumerycznym
		inFile.get(letter);
	}
	else
		inFile.get(letter);

	if (!inFile || !isalnum(letter))
		letters[0] = '\0';

	else
	{
		do
		{
		letters[count] = letter;
		count++;
		inFile.get(letter);
		}
		while (isalnum(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		if (count == MAX_CHARS && isalnum(letter))
			do
			{
				inFile.get(letter);
			}
			while (isalnum(letter) && inFile);
	}
}


void GetAlpha(bool skip, char letters[], std::ifstream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{
		inFile.get(letter);
		while (!isalpha(letter) && inFile)//isalpha zwraca wartosc rozna od zera gdy argument jest znakiem alfabetycznym
		inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || !isalpha(letter))
		letters[0] = '\0';
	else
	{
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
			}
			while (isalpha(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		if (count == MAX_CHARS && isalpha(letter))
			do
			{
				inFile.get(letter);
			}
			while (isalpha(letter) && inFile);
	}
}




void GetNonWhite(bool skip, char letters[], std::ifstream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{
		inFile.get(letter);
		while (!isspace(letter) && inFile)//isspace zwraca wartosc rozna od zera gdy argument jest zankiem bialym
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || !isspace(letter))
		letters[0] = '\0';
	else
	{
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		}
while (isspace(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		if (count == MAX_CHARS && isspace(letter))
		do
		{
			inFile.get(letter);
		}
		while (isspace(letter) && inFile);
	}
}








void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{
		inFile.get(letter);
		while ((letter == '\n') &&inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || letter == '\n')
		letters[0] = '\0';
	else
	{
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		}
		while ((letter != '\n') && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		if (count == MAX_CHARS && letter != '\n')
		do
		{
			inFile.get(letter);
		}
		while ((letter != '\n') && inFile);
	}
}






void StrType::PrintToFile(bool newLine,std::ofstream& outFile)
{
	using namespace std;
	if (newLine)
		outFile << endl;
	outFile << letters;
}









void StrType::PrintToScreen(bool newLine)
{
	using namespace std;
	if (newLine)
		cout << endl;
	cout << letters;
}
 








void StrType::CopyString(StrType& newString)
{
	std::strcpy(newString.letters, letters);
}






int StrType::LengthIs()
{
	return std::strlen(letters);
}

