#include "strtype.h"

void StrType :: MakeEmpty()
{
	letters[0]='\0';
}

void StrType :: GetStringFile(bool skip, IsType charAllowed, std::ifstream& inFile)
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
