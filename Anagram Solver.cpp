#include <iostream> //declares the standard devices cin, cout, clog, cerr; http://www.cplusplus.com/reference/iostream/
#include <string> //declares string types and conventions including begin & end iterator; http://www.cplusplus.com/reference/string/
#include <algorithm> //declares a collection of ranged functions; http://www.cplusplus.com/reference/algorithm/
#include <random> //declares random number generation facilities; http://www.cplusplus.com/reference/random/
#include <fstream>//declares a set of standard file stream devices that can be used to to create, read and use files
#include <ctime>//declares a set of functions, macros and types to work with date and time information, e.g. the time() function is used to get the current timE
#include <vector> 

//create a fixed identifier (a bit like an unchangeable global variable) with a string value; the compiler will automatically use the string for each instance of the identifier 
#define cDATAFILE "Words_75K_PreSubmissionTesting.csv" //data file being used, upload a data file to repl.it and change the "xxx" in order to change the file name being used

using namespace std; //tell the compiler that by default to use the “std” – this means that we don’t need to keep saying “std::cout” we can just use: “cout”

//PROTOTYPE FUNCTIONS: Decleration
string Ordering_Machine (string desiredString);
void Find_Anagrams(string originalString);

//GLOBAL VARIABLES
int iFileLines;
vector<string> rawDataStrings;
vector<string> orderedDataStrings;


//lets get the number of the lines in the file
void FileLineFounder_Machine(void) {

  ifstream dbFile; 
	dbFile.open(cDATAFILE);

  int FileLineCounter;
  string Fileline;
  ifstream file(cDATAFILE);
  while (getline(file, Fileline)) {
    FileLineCounter++;
  }
  iFileLines = FileLineCounter; 

  //cout << endl << iFileLines << endl;
  
	dbFile.close();
}


void ReadFile(void) { //this function reads a specific text filed line by line and displays the result

  ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
	dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
	//once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use


	string currentWord; //declare a variable of type string that can be used to hold each line as the file is read
  string currentWordOrdered;


  string Fileline;
  ifstream file(cDATAFILE);
  while (getline(file, Fileline)) {
    iFileLines++;
  }

  rawDataStrings.reserve(iFileLines);
  orderedDataStrings.reserve(iFileLines);

  int i = 0; //index for creating arrays
	while(!dbFile.eof()) { //this sets up a loop that repeats until we have read every line in the opened file; line by line.
		  //lets take a closer look:
		  //in essence, "while (TRUE) { do this stuff }"
		  //repeats (loops) everything inside the '{' and '}' while this this condition in the "while(TRUE)" is true
		  //"dbFile.eof()" is a special method/function similar to "dbFile.open(cDATAFILE)" that returns true or false depending on whether we are at the End of the File (eof)
		  //the '!' character is used to logically say "NOT" - in this case the instruction "while(!dbFile.eof()){   ... }" means "repeat this '...' while   we are NOT at the end of the file"
	  	getline(dbFile, currentWord); //use getline function to access/put the current line of dbFile into the variable 'currentword', 

      currentWordOrdered = Ordering_Machine(currentWord);
      
      //cout << endl << currentWordOrdered << endl;
      //cout << endl << currentWord << endl;

      //updating our vector (starts from 0)
      rawDataStrings.push_back(currentWord);
      orderedDataStrings.push_back(currentWordOrdered);

      i++;
  	}
	//if we are here there the program has read each line until it got to the end of the file
	dbFile.close();//close the connection to the file (otherwise the file will remain locked to other users and this program)
}

string Ordering_Machine (string desiredString) {

string localString; //declare a local variable called localString
localString = desiredString; //set the localString to originalString

string tempSaveOne; //create a string for saving the letter before making it capital (i1 (index1) letter)
string tempSaveTwo; //create a string for saving the letter before making it capital (i2 (index2) letter)

tempSaveOne = localString; //setting tempSaveOne to localString
tempSaveTwo = localString; //setting tempSaveOne to localString

int lengthofOriginal; //setting a local variable for lenght of the string in integer
lengthofOriginal = localString.length(); //lenght of the string in integer value

string orderedString; //declaring a local variable for the string that will be updated each cycle
orderedString = localString; //orderedString is set to localString

int i1 = 0; //comparing first letter index
int i2 = 1; //comparing second letter index

  for (int iloop1 = 0; iloop1 < lengthofOriginal; iloop1++) {

    i1 = 0; //setting i1 index to 0 for the upcoming loop, so location 0, which will be the first letter
    i2 = 1; //setting i2 index to 1 for the upcoming loop, so location 1, which will be the next letter

    for (int i = 0; i < lengthofOriginal-1; i++) {

    string comparingString = orderedString; //comparingString should also be updated to orderedString where the final string is saved after the following operations

    //cout << endl << endl << "orderedString BEFORE operation: " << orderedString << endl;

    tempSaveOne[i1] = orderedString[i1]; //saving the first letter before being changed to uppercase
    tempSaveTwo[i2] = orderedString[i2]; //saving the second letter before being changed to uppercase

    //below "comparingString"'s become only capital letters to compare
      if ( comparingString[i1] > 90 ) {
       comparingString[i1] = comparingString[i1] - 32;
      }
       if ( comparingString[i2] > 90 ) {
      comparingString[i2] = comparingString[i2] - 32;
      }

      //depending on the size of the letters they are being swapped
      if ( comparingString[i1] > comparingString[i2] ) {
      orderedString[i1] = tempSaveTwo[i2]; //tempSaveTwo goes into the first place of the updating string
      orderedString[i2] = tempSaveOne[i1]; //tempSaveOne goes into the next place of the updating string
      }

      for (int i = 0; i <= lengthofOriginal; i++) {
      //it will replace the letter located in the i location (which will increase each loop) by 32 which is the number to make a letter capital, if it is lower case(>90)
        if (orderedString[i] > 90) {
        orderedString[i] = orderedString[i] - 32;
        }
      }

    i1++; //inc the string index
    i2++; //inc the string index

    localString = orderedString; //localString is now set to the string that was being updated in the loop
    }
  }
  return localString; //return the value contained in the localstring local variable
}


void QuitNow(void) { //the program quits
  exit(EXIT_SUCCESS); //execute the c++ exit function and pass it c++ contant value called EXIT_SUCCESS; 
}


std::string Get_Word(void) { //function that will allow the user to enter a word
  string UserString; //declears a local string, user's word will be stored here.
  getline(cin, UserString); //this getline is helpful for capturing strings with white spaces since cin >> terminates after whitespaces
  cout << endl << "\nEnter a new word or phrase: "; //asking the user for a word or phrase
  getline(cin, UserString); //get the input value from the user and store it in the local variable "UserString" 
  return UserString; //pass this variable to the demanding instruction
}


void Find_Anagrams(string originalString) { //function that will allow the user to enter a word
  
  string localString;
  localString = originalString;

  string localStringOrdered;
  localStringOrdered = Ordering_Machine(localString);

  string localStringCompareExisting;
  localStringCompareExisting = localString;

  int len; //declare a local variable called len of type integer
  len = localStringCompareExisting.length();
  //this will loop until the lenght of the word
  for (int i = 0; i <= len; i++) {
        //if statement changes the character to lower case, if the character is uppercase(<97) and adds 32, however if you add 32 to 0 (space) it will become a the "@" sign, therefore, the && operator is added to only execute this addition if the letter we are dealing with is not the " " space.
        if ((localStringCompareExisting[i] < 97) && (localStringCompareExisting[i] != 32)) {
          localStringCompareExisting[i] = localStringCompareExisting[i] + 32;
        }
      }

      int idataLine;

      string rawDataCompare;
      string foundAnagram;

      int count = 0;

      cout << endl << "Found the following anagrams for current word: " << endl;


      for (int idataLine = 0; idataLine < iFileLines; idataLine++) {
          
        
        rawDataCompare = orderedDataStrings.at(idataLine);

        if ( (localStringOrdered == rawDataCompare) && (localStringCompareExisting != rawDataStrings.at(idataLine)) ) {

          foundAnagram = rawDataStrings.at(idataLine);
          cout << foundAnagram << endl;
          count++;
          
        }
      }
      cout << endl << "Found " << count << " anagrams of " << localString << "." << endl;
}


void Largest_Word_Available(string originalString) {

  vector<string> LargestWord;
  LargestWord.reserve(iFileLines);


  string localString;
  localString = originalString;

  string localStringOrdered;
  localStringOrdered = Ordering_Machine(localString);

  int lenoflocal;
  lenoflocal = localStringOrdered.length();

  string currentDataWord;

  int counter;
  int LargestValueFound;

  for (int imain = 0; imain < iFileLines; imain++) {

    int i1 = -1;
    int score = 0;
    currentDataWord = orderedDataStrings.at(imain);

    string refreshlocal;
    refreshlocal = localStringOrdered;

    int lenofcurrent;
    lenofcurrent = currentDataWord.length(); 

    if (lenoflocal >= lenofcurrent) {

      jump1:

      i1++;
      int i2 = 0;

      //cout << endl << refreshlocal << endl; 

      //cout << endl << currentDataWord << endl; 


      for (int i = 0; i < lenoflocal; i++) {

        if ( currentDataWord[i1] == refreshlocal[i2] ) {
          
          score++;
          refreshlocal.erase (refreshlocal.begin()+i2);
          goto jump1;

          //cout << endl << refreshlocal << endl; 
        } else {
          i2++;
        }

        //cout << endl << i2 << endl;
          if ( score == lenofcurrent) {
          counter++;
            string currentDataWordOrganized;
            currentDataWordOrganized= rawDataStrings.at(imain);
            LargestWord.push_back(currentDataWordOrganized);
          break;
          }
      }
    }  
  }

  int samelenghtcount;
  int integerLargest = 0;
  int maxLargestWord = LargestWord.size();
  
  vector<string> highestlenStrings;
  int sizeforLargest;

  for ( int indexforlargestlen = 0; indexforlargestlen < maxLargestWord; indexforlargestlen++) {

    string FindLargestLen;
    FindLargestLen = LargestWord.at(indexforlargestlen);

    int lenofWord;
    lenofWord = FindLargestLen.length(); 


    if ( lenofWord >= integerLargest ) {

      if ( lenofWord > integerLargest ) {
        samelenghtcount = 0;
        highestlenStrings.clear();
      }


      integerLargest = lenofWord;
      LargestValueFound = indexforlargestlen;

       if ( lenofWord == integerLargest) {
        samelenghtcount++;
        highestlenStrings.push_back(FindLargestLen);
         = highestlenStrings.size();
      }

    }
  }

  if ( counter > 0 ) {

    cout << endl << "Largest Word Available: " << LargestWord.at(LargestValueFound) << endl;
    cout << "Number of other words found in the same lenght as " << LargestWord.at(LargestValueFound) << " " << samelenghtcount << endl;

    for (int i = 0; i > )

  } else {

    cout << endl << "Sorry no word found. " << endl;
  
  }
}

/*
void Test(string originalString) {

  for(int i = 0; i < iFileLines)
}
*/


void Menu(void) { //function displays the menu to the user
  
  int startTicks, stopTicks; //declare the variables that will be used to hold integer values for the current clock time
	int totalTicks; //declare a variable to hold the total value
	float timeSeconds; //declare a floating point variable to hold the converted tick time to seconds
	startTicks=clock(); //get the number of clock ticks consumed by the processor since the program started

  stopTicks=clock(); //get the number of clock ticks consumed by the processor since the program started; more times will have happened since we last took the time
	totalTicks = stopTicks - startTicks; //work out the difference in ticks
	timeSeconds = totalTicks/double(CLOCKS_PER_SEC) * 1000;//convert the ticks into seconds

  string currentString= "alert"; //variable that gets its data from GetWord function, this variable starts with the student ID to be displayed at the "current word/phrase:"
  string modifiedString= "nothing"; //variable used for the reverseWord function
  string menuOption; //a string variable since the entered data may be a character or a number, more info on if statement down below
  int intforMenu;
  
  do { //start an endless loop - this is so the associated code block repeats forever
    cout << endl << "C++ Anagram Solver Challenge" << endl << endl; //display a title for the menu
    cout << "\t1. Enter a word or phrase (current word/phrase is: " << currentString << ")." << endl;
    cout << "\t2. Find an anagram of the word." << endl;
    cout << "\t3. Find the largest word containing (most of) these letters." << endl;
    cout << "\t6. Test!" << endl;
    //cout << "\t4. Find all possible 3 letters words that are also anagrams." << endl;
    //cout << "\t5. Find all possible 5 letters words that are also anagrams." << endl;
    
    cout << endl << "\t0. Quit the program.";

    cout << endl << endl << "The System Took: " << timeSeconds << " seconds to complete the operation!" << endl;

    cout << "\nPlease enter a valid option (1 - 6 or 0 to quit): ";
    cin >> menuOption; //store the choice made by the user in the variable menuOption

    
    if ( (menuOption != "0") && (menuOption != "1") && (menuOption !="2") && (menuOption != "3") && (menuOption != "4") )
    { //if menuOption 0-6 is NOT chosen this error message will be displayed
      cout << "Unfortunately, '" << menuOption << "' is not a valid option, please try again." << endl << endl;
    //this if statement executes a message to the user that the option they have chosen is not valid other than the menu options we have which are 0 to 6
    } else {
    // 0 to 6 is belongs to this section where NO error message will be displayed
      int intforMenu = stoi(menuOption); //this changes  the string to integer is necessary because switch statement does not accept strings
    
    switch(intforMenu) { //'switch' statement that calls the menuOption given by the user and chooses a case
      case 1: //this basically "if the menuOption = 1", option 1 should call the function GetWord 
        currentString = Get_Word(); //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
      case 2: //"if the menuOption = 2", option 2 should call the function Find_Anagrams
        Find_Anagrams(currentString);
        //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
      case 3: //"if the menuOption = 2", option 2 should call the function Find_Anagrams
        Largest_Word_Available(currentString);
        //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute

        /*
        case 6: //"if the menuOption = 2", option 2 should call the function Test
        Test(currentString);
        //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
        */

      case 0: //"if the menuOption = 0", option 0 should call the function QuitNow
        cout << endl << endl << "Are you sure(Y/N)?" << endl; //asking user YES or No if they want to quit
        string userAnswer; //variable where user's answer is stored
        cin >> userAnswer; //user entering Y or N

        if ( (userAnswer == "Y") || (userAnswer == "y") )  //if they entered Y or y, the program will go to Quit now function else it will do nothing and display the menu again
        {
        QuitNow(); //calls the function that quits the program
        }
        
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
    }
    }
  } while(true); //this tells the computer the conditions to break the "do" loop - while true is always true and therefore will continue forever; in essence and endless loop
}

int main() { 
//this is the required function that will automatically execute when the program is run

  ReadFile();

  FileLineFounder_Machine();

  Menu(); //start the program menu function
  
}



/*
TEST LOG

3/20/19
I came up with an algorithm, that would not just reorder the string entered by the user, but would reduce the chars that were same to 1. For instance: "Anagram" would look like "Agmnr". I thought this would be useful because my point system would function better at it. (Talked about the point system in the algorithm, if I still used it). Overall, it was not necessary at all... FAILURE.
*/