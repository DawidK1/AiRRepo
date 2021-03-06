#include "strtype.h"

void StrType :: MakeEmpty()
{
	letters[0]='\0';
}

void StrType :: GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
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

void StrType :: PrintToScreen(bool newLine)
{
	using namespace std;
	if(newLine)
		cout << endl;
	cout << letters;
}

void StrType :: PrintToFile(bool newLine, std::ofstream& outFile)
{
	using namespace std;
	if(newLine)
		outFile << endl;
	outFile << letters;
}

int StrType:: LengthIs()
{//zwraca dlugosc stringa
	return std::strlen(letters);
}

void StrType :: CopyString(StrType& newString)
{
	std::strcpy(newString.letters, letters);
}

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	if(skip)
	{
		inFile.get(letter);
		while(!isalnum(letter) && inFile) //isalnum zwraca !=0 gdy argument jest znakiem alfanum w innym przypadku zwraca 0
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if(!inFile || !isalnum(letter))
		//nie znaleziono prawidlowego znaku, zwracam pusty string
		letters[0]='\0';
	else
	{ //przeczytaj plik i pobierz znaki
		do
		{
			letters[count]=letter;
			count++;
			inFile.get(letter);
		}
		while (isalnum(letter) && inFile && (count < MAX_CHARS));
			letters[count]='\0';
		//pomin dodatkowe znaki, ktore sie nie zmiescily
		if(count == MAX_CHARS && isalnum(letter))
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

	if(skip)
	{
		inFile.get(letter);
		while(!isalpha(letter) && inFile) //isalpha zwraca zero jezeli znak nie jest litera z alfabetu, w przeciwnym wypadku zwraca wartosc rozna od 0
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if(!inFile || !isalpha(letter)) //nie znaleziono prawidlowego znaku, zwracam pusty string
		letters[0]='\0';
	else
	{
		do
		{
			letters[count]=letter;
			count++;
			inFile.get(letter);
		}
		while(isalpha(letter) && inFile && (count < MAX_CHARS));
			letters[count]='\0';
		//pomin dodatkowe znaki jesli potrzeba
		if(count == MAX_CHARS && isalpha(letter))
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

	if(skip)
	{ //pomijam znaki biale
		inFile.get(letter);
		while(!isspace(letter) && inFile)
			inFile.get(letter);
	}	
	else
		inFile.get(letter);

	if(!inFile || !isspace(letter)) //nie znaleziono prawidlowego znaku, zwracam pusty string
		letters[0] = '\0';
	else
	{//przeczytaj i zbierz znaki
		do
		{
			letters[count]=letter;
			count++;
			inFile.get(letter);
		}
		while (isspace(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		//pomija dodatkowe znaki
		if(count == MAX_CHARS && letter != ' ')
			do
			{
				inFile.get(letter);
			}
			while ((letter != ' ') && inFile);
	}
}
void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	
	if(skip) //pomin nowe linie
	{
		inFile.get(letter);
		while ((letter=='\n') && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if(!inFile || letter == '\n')
		letters[0]='\0';
	else //przeczytaj i pobierz znaki
	{
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		}
		while((letter!='\n') && inFile && (count < MAX_CHARS));
		letters[count]='\0';
		//pomin dodatkowe znaki
		if(count == MAX_CHARS && letter !='\n')
			do
			{
				inFile.get(letter);
			}
			while((letter!='\n') && inFile);
	}
}

/////////////////////////////////////////////

void StrType::GetString(bool skip, InType charsAllowed)
{
	switch (charsAllowed)
	{
		case ALPHA_NUM : GetAlphaNum(skip, letters, std::cin);
		break;

		case ALPHA : GetAlpha(skip, letters, std::cin);
		break;

		case NON_WHITE : GetNonWhite(skip, letters, std::cin);
		break;

		case NOT_NEW : GetTilNew(skip, letters, std::cin);
		break;
	}
}

void GetAlphaNum(bool skip, char letters[], std::istream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	if(skip)
	{
		inFile.get(letter);
		while(!isalnum(letter) && inFile) //isalnum zwraca !=0 gdy argument jest znakiem alfanum w innym przypadku zwraca 0
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if(!inFile || !isalnum(letter))
		//nie znaleziono prawidlowego znaku, zwracam pusty string
		letters[0]='\0';
	else
	{ //przeczytaj plik i pobierz znaki
		do
		{
			letters[count]=letter;
			count++;
			inFile.get(letter);
		}
		while (isalnum(letter) && inFile && (count < MAX_CHARS));
			letters[count]='\0';
		//pomin dodatkowe znaki, ktore sie nie zmiescily
		if(count == MAX_CHARS && isalnum(letter))
			do
			{
				inFile.get(letter);
			}
			while (isalnum(letter) && inFile);
	}
}

void GetAlpha(bool skip, char letters[], std::istream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;

	if(skip)
	{
		inFile.get(letter);
		while(!isalpha(letter) && inFile) //isalpha zwraca zero jezeli znak nie jest litera z alfabetu, w przeciwnym wypadku zwraca wartosc rozna od 0
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if(!inFile || !isalpha(letter)) //nie znaleziono prawidlowego znaku, zwracam pusty string
		letters[0]='\0';
	else
	{
		do
		{
			letters[count]=letter;
			count++;
			inFile.get(letter);
		}
		while(isalpha(letter) && inFile && (count < MAX_CHARS));
			letters[count]='\0';
		//pomin dodatkowe znaki jesli potrzeba
		if(count == MAX_CHARS && isalpha(letter))
			do
			{
				inFile.get(letter);
			}
			while (isalpha(letter) && inFile);
	}
}

void GetNonWhite(bool skip, char letters[], std::istream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;

	if(skip)
	{ //pomijam znaki biale
		inFile.get(letter);
		while(!isspace(letter) && inFile)
			inFile.get(letter);
	}	
	else
		inFile.get(letter);

	if(!inFile || !isspace(letter)) //nie znaleziono prawidlowego znaku, zwracam pusty string
		letters[0] = '\0';
	else
	{//przeczytaj i zbierz znaki
		do
		{
			letters[count]=letter;
			count++;
			inFile.get(letter);
		}
		while (isspace(letter) && inFile && (count < MAX_CHARS));
		letters[count] = '\0';
		//pomija dodatkowe znaki
		if(count == MAX_CHARS && letter != ' ')
			do
			{
				inFile.get(letter);
			}
			while ((letter != ' ') && inFile);
	}
}
void GetTilNew(bool skip, char letters[], std::istream& inFile)
{
	using namespace std;
	char letter;
	int count = 0;
	
	if(skip) //pomin nowe linie
	{
		inFile.get(letter);
		while ((letter=='\n') && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	
	if(!inFile || letter == '\n')
		letters[0]='\0';
	else //przeczytaj i pobierz znaki
	{
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		}
		while((letter!='\n') && inFile && (count < MAX_CHARS));
		letters[count]='\0';
		//pomin dodatkowe znaki
		if(count == MAX_CHARS && letter !='\n')
			do
			{
				inFile.get(letter);
			}
			while((letter!='\n') && inFile);
	}
}