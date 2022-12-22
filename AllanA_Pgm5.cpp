// Ashley Allan, 2228 CS 2010 Section 1004, MOWeFri 11:30am-12:20pm

//Program 5: Books, File:AllanA_Pgm5, Due:10/30/2022

/*
Purpose: To analyze and report the results of a reading competition
Input: pgm5.txt file (names of readers, amount of books read)
Processing: reads input from file and sorts names and amount of books into two separate arrays; counts the total amount of readers; displays the reader names
and amount of books read in a numbered list; calculates the winner and loser based on amount of books read; calculates the total number of books read by all readers
Output: Displays a numbered list of readers and amount of books they read; displays the winner who read the most books; displays the loser who read the least books;
displays the total amount of books read by the group

Reflection: While I was very pleased to be able to figure out how to write most of this program by myself, it was difficult to troubleshoot. I cam across errors throughout
but I continued to finish the program, and I found that fixing the errors one by one after I finished writing the program was beneficial in this sense. Since this wasn't
particularly a large program, it was better to fix all of my errors at the end of it. I had help from both the professor and the LA about how to troubleshoot, and with that
I successfully debugged the program and perfected it. I really liked the simplicity of this assignment because it allowed me to focus on the important things that I've
learned from this chapter and past chapters without making me stress over the length and the amount of details that needed to be met (Like program 4, as much as I love
a challenge). 
*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	const int MAX_BOOKS = 25; //Determines amount of data read from the file 
	string readers[MAX_BOOKS]; //Array that stores reader names 
	int books[MAX_BOOKS]; //Array that stores number of books read by readers 
	int numReaders = 0; //Stores number of readers 
	int i = 0; //Declares index for loops

	int mostBooks = 0; //Holds reader name and value of books read for the one who read the most books 
	string winner;
	int leastBooks = 100; //Holds reader name and value of books read for the one who read the least books
	string loser; 

	int totalBooksRead = 0; //Holds total amount of books read  

	int count = 0; //Holds the total number of readers
	int indxMostBooks; //Hold the numbers of the readers who had the most and least books
	int indxLeastBooks;

	ifstream infile;

	infile.open("pgm5.txt"); //Opens text file

	if (infile.fail()) { //Verifies that file is successfully opened 
		infile.close();
		return 1;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (!infile.eof()) { //Reads contents until end of the file 

			infile >> readers[i]; //Reads file contents and sorts into respective arrays 
			infile >> books[i]; 
				
			if (books[i] < 0) { //Corrects invalid (negative) values to positive integer
					books[i] = abs(books[i]);
				}
			++i;
			++count;
	} 
	
	infile.close(); //Closes file 

	for (i = 0; i < count; ++i) { //Outputs list of readers and amount of books read
		++numReaders;
		cout << "Reader " << numReaders << " named " << readers[i] << " read " << books[i] << " books." << endl; //Displays numbered list of readers and amount of books read
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (i = 0; i < count;  ++i) { //Finds reader that read the most books and reader that read the least books
		if (books[i] > mostBooks) {
			mostBooks = books[i];
			indxMostBooks = i;
		}
		if (books[i] < leastBooks) {
			leastBooks = books[i];
			indxLeastBooks = i;
		}
	}

	for (i = 0; i < count; ++i) { //Calculates total number of books read
		totalBooksRead = totalBooksRead + books[i];
	}
	//Display of who read the most books, who read the least books, and the total number of books read by the group:
	cout << "The winner is reader " << indxMostBooks + 1 << ", " << readers[indxMostBooks] << ", who read " << books[indxMostBooks] << " books." << endl; 
	cout << "The loser is reader " << indxLeastBooks + 1 << ", " << readers[indxLeastBooks] << ", who read " << books[indxLeastBooks] << " books." << endl; 
	cout << "In total, all readers collectively read " << totalBooksRead << " books." << endl; 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}