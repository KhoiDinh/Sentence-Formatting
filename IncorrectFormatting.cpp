//inputs: char incorrect[]
//output: char correction[]
// program that takes in sentence and fixes the capitalization and spacing

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void fix(); // fixes a sentence's capitalization and spacing
#define limit 99
char incorrect[limit +1];// creates empty starting array
char correction[limit +1];
int j = 0;


int _tmain(int argc, _TCHAR* argv[])
{
	memset(correction, 0 , sizeof(correction));
	cout << "Enter a sentence of at most " << limit <<" characters: " << endl;
	do
	{
		cin.getline(incorrect, limit-j);// gets user's input
		fix();// function that fixes sentence
		if (correction[j - 1] != ' ')
		{
			
			correction[j] = ' ';
			j++;
		}
		
	} while (incorrect[strlen(incorrect)-1] != '.' && j < limit-1);
	
	correction[0] = toupper(correction[0]);
	 if (correction[j - 1] == '.')
	{
		correction[j] = '\0';
	}
	correction[j] = '\0';
	cout << '"' << correction << '"' << endl;
	return 0;
}

void fix()// function that fixes sentence
{
	int i = 0;
	for (i = 0; incorrect[i]; i++)
	{
		if (isspace(incorrect[i]))
		{
			incorrect[i] = ' ';
		}
	}
	for (i = 0; i < strlen(incorrect); i++)
	{
		if (incorrect[i] == ' ')
		{
			if (correction[j - 1] == ' ')
			{
				continue;
			}
			correction[j] = incorrect[i];
			
			j++;
		}
		else if (incorrect[i] == '.' && correction[j - 1] == ' ')
		{
			correction[j - 1] = '.';
		}
		
		else
		{			
				correction[j] = tolower(incorrect[i]);
				j++;		
		}
	
	}
	return;   //returns fixed sentence
}


