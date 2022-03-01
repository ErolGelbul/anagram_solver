#include <iostream> //declares the standard devices cin, cout, clog, cerr
#include <string> //declares string types and conventions including begin & end iterator
#include <algorithm> //declares a collection of ranged functions
#include <random> //declares random number generation facilities
#include <fstream> //declares a set of standard file stream devices that can be used to to create, read and use files
#include <ctime> //declares a set of functions, macros and types to work with date and time information, e.g. the time() function is used to get the current time
#include <vector> //enables the use of sequence containers representing arrays that can change in size
#include <thread> //a thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space.
#include <chrono> //chrono library is used to deal with date and time. 

//create a fixed identifier (a bit like an unchangeable global variable) with a string value; the compiler will automatically use the string for each instance of the identifier 
#define cDATAFILE "Words_75K_PreSubmissionTesting.csv" //data file being used, upload a data file to repl.it and change the "xxx" in order to change the file name being used

using namespace std; //tell the compiler that by default to use the “std”


//Prototype Functions
string Ordering_Machine (string desiredString);
void Find_Anagrams(string originalString);

//Global Variables
double seconds;
int iFileLines;
int xLetterGroup;
float timeTaken;

//Global Vectors
vector<string> rawDataStrings;
vector<string> orderedDataStrings;
vector<string> XLetterOrderedWords;
vector<string> XLetterRawWords;


//this function does not request or return any variable, it counts the amount of elements in the file, by reading line by line
void FileLineFounder_Machine(void) {

  ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
  dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
  //once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use

  int FileLineCounter; //declare a variable to hold an integer, counter
  string Fileline; //declare a variable to hold a string,
  ifstream file(cDATAFILE); //the name cDATAFILE defined up on line 10 will replace it
  //this while loop will get each string from the file until it reaches to the last string
  while (getline(file, Fileline)) {
    FileLineCounter++; //each time this loops FileLineCounter will be incremented by 1
  }
  iFileLines = FileLineCounter; //total count will be stored to the global variable iFileLines in order to be used on the upcoming functions
  
  dbFile.close(); //close the connection to the file (otherwise the file will remain locked to other users and this program)
}

//this function's purpose is to read each line from the file and send it to the "Ordering_Machine" function where each string from the file will be ordered. Later this fucntion will store them in 2 vectors, one of them ordered, one of them original(raw).
void ReadFile(void) { //this function reads a specific text filed line by line and displays the result

  ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
  dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
  //once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use

  string currentWord; //declare a variable of type string that can be used to hold each line as the file is read
  string currentWordOrdered; //declare a variable of type string that will be used to hold the ordered version of the currentWord

  while(!dbFile.eof()) { //this sets up a loop that repeats until we have read every line in the opened file; line by line.
    //lets take a closer look:
    //in essence, "while (TRUE) { do this stuff }"
    //repeats (loops) everything inside the '{' and '}' while this this condition in the "while(TRUE)" is true
    //"dbFile.eof()" is a special method/function similar to "dbFile.open(cDATAFILE)" that returns true or false depending on whether we are at the End of the File (eof)
    //the '!' character is used to logically say "NOT" - in this case the instruction "while(!dbFile.eof()){   ... }" means "repeat this '...' while   we are NOT at the end of the file"
    getline(dbFile, currentWord); //use getline function to access/put the current line of dbFile into the variable 'currentword', 

    currentWordOrdered = Ordering_Machine(currentWord); //sending the currentWord to an ordering function, then storing the returned string to currentWordOrdered varialbe
      
    //Testing Measures
    //cout << endl << "Current word: " << currentWord << endl;
    //cout << endl << "Ordered version of the current word: " << currentWordOrdered << endl;

    rawDataStrings.push_back(currentWord); //adds an element at the end of the vector, the current word
    orderedDataStrings.push_back(currentWordOrdered); // adds an element at the end of the vector, the ordered version of the current word
  }
  //if we are here there the program has read each line until it got to the end of the file
  dbFile.close();//close the connection to the file (otherwise the file will remain locked to other users and this program)
}

//this function returns a string and expects a string, it's purpose is to take each line by the ReadFile function, the string taken is put into the desiredString string, and at the end it returns a string that is alphabetical order and all upper case letters.
string Ordering_Machine (string desiredString) {

  string localString; //declare a local variable called localString
  localString = desiredString; //set the localString to desiredString

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

      //Testing Measure 1
      //cout << endl << endl << "BEFORE operation: " << orderedString << endl;

      tempSaveOne[i1] = orderedString[i1]; //saving the first letter before being changed to uppercase
      tempSaveTwo[i2] = orderedString[i2]; //saving the second letter before being changed to uppercase

      //below "comparingString"'s become only capital letters to compare
      if ( comparingString[i1] > 96 ) {
       comparingString[i1] = comparingString[i1] - 32;
      }
       if ( comparingString[i2] > 96 ) {
      comparingString[i2] = comparingString[i2] - 32;
      }

      //depending on the size of the letters they are being swapped
      if ( comparingString[i1] > comparingString[i2] ) {
      orderedString[i1] = tempSaveTwo[i2]; //tempSaveTwo goes into the first place of the updating string
      orderedString[i2] = tempSaveOne[i1]; //tempSaveOne goes into the next place of the updating string
      }

      for (int i = 0; i <= lengthofOriginal; i++) {
      //it will replace the letter located in the i location (which will increase each loop) by 32 which is the number to make a letter capital, if it is lower case(>90)
        if (orderedString[i] > 96) {
        orderedString[i] = orderedString[i] - 32;
        }
      }

      i1++; //inc the string index
      i2++; //inc the string index

      localString = orderedString; //localString is now set to the string that was being updated in the loop

      //Testing Measure 2(Last)
      //cout << "AFTER operation: " << localString << endl;
    }
  }
  return localString; //return the value contained in the localstring variable
}


void QuitNow(void) { //the program quits
  exit(EXIT_SUCCESS); //execute the c++ exit function and pass it c++ contant value called EXIT_SUCCESS; 
}


string Get_Word(void) { //function that will allow the user to enter a word

  string UserString; //declears a local string, user's word will be stored here.
  getline(cin, UserString); //this getline is helpful for capturing strings with white spaces since cin >> terminates after whitespaces
  cout << endl << "\nEnter a new word or phrase: "; //asking the user for a word or phrase
  getline(cin, UserString); //get the input value from the user and store it in the local variable "UserString" 

  return UserString; //pass this variable to the demanding instruction
}

//Algorithm for Find_Anagrams: reorder the entire data file into alphabetical and uppercase order. Put all these ordered strings into a vector. Also put the raw (original) words from the data file into a vector. (Both vertices will include the each word in the same order, eg. raw word Anagram will be in vector's 15th location, the ordered version AAAGMNR will be in 15th location of the other vector). We will get the originalString from the user and compare each word with the string user has provided. Display the string if it is an anagram. Count how many times we are displaying. At the end display the count.
void Find_Anagrams(string originalString) { //function that will allow the user to find anagrams of the word they have entered
  
  string localString; //declare a local variable called localString
  localString = originalString; //set the localString to desiredString

  string localStringOrdered; //declare a local variable called localStringOrdered that will keep the ordered version of the user's string
  localStringOrdered = Ordering_Machine(localString); //send localString to the Ordering Machine which will return an alphabetically ordered and all upper case string back into localStringOrdered local variable

  string localStringCompareExisting; //a local variable to copy the localString in for comparing purposes, this is necessary since the localString will be altered
  localStringCompareExisting = localString; //setting the comparing string as localString;

  int len; //declare a local variable called len of type integer
  len = localStringCompareExisting.length(); //len will be the length of the localStringcomparing variable

  //this will loop until the lenght of the word
  for (int i = 0; i <= len; i++) {

    //if statement changes the character to upper case, if the character is uppercase(<91) and adds 32, however if you add 32 to 0 (space) it will become a the "@" sign, therefore, the && operator is added to only execute this addition if the letter we are dealing with is not the " " space.
    if ((localStringCompareExisting[i] < 91) && (localStringCompareExisting[i] != 32)) {
      localStringCompareExisting[i] = localStringCompareExisting[i] + 32;
    }
  } 

  string rawDataCompare; //declare a local string type variable, that will hold the original (raw) version of the string from the datafile
  string foundAnagram; //declare a local string type variable, that if an anagram is found, the word from the data file will be held here

  int count = 0; //declare a local integer type variable, that will count the times when an anagram is found

  cout << endl << "Found the following anagrams for current word: " << endl; //display a message to the user before the anagram words

  //create a loop, that will loop until it scans all the strings in the data file
  for (int idataLine = 0; idataLine < iFileLines; idataLine++) {
          
    rawDataCompare = orderedDataStrings.at(idataLine); //set the rawDataCompare string to the orderedDataStrings starting at the index idataLine

    //if statement that analyzes if the localString's ordered version is the same as raw data string ready to be compared, but the localStrings comparable version shouldnt be the same as the raw version of the data file string, which basically means if the user has entered "lager" and if there is a string that already exists in the data file, exact word "lager" shouldn't be taken into anagram string
    if ( (localStringOrdered == rawDataCompare) && (localStringCompareExisting != rawDataStrings.at(idataLine)) ) {
          
      foundAnagram = rawDataStrings.at(idataLine); //if conditions are met, foundAnagram must be set to the original(raw) version of the data string at location idataLine
      cout << foundAnagram << endl; //display the string
      count++; //increment the count of anagrams found
    }
  }
  cout << endl << "Found " << count << " anagrams of " << localString << "." << endl; //finnally display the count and user's string.
}


//Algorithm for Largest_Word_Available: take the ordered version of the string provided by the user. Check each word's ordered version from the data file, if each letter in the word belongs to a letter in the originalString's ordered version. If so, save that word in a vector. Now we have all the words we can create with these letters given by the user. Compare each one of them in size. If we get a bigger size as we are comparing, reset everything, put the size to X, count up all the strings which have the same size. If encountered with a larger word, reset, repeat. Display the first fetched word, and the count at the end.
void Largest_Word_Available(string originalString) {

  vector<string> LargestWord; //declare a local vector that will hold the largest words found from the data file

  string localString; //declare a local string type variable
  localString = originalString; //set the localString to desiredString

  string localStringOrdered; //declare a local string type variable
  localStringOrdered = Ordering_Machine(localString); //send the localString to the Ordering Machine and put the returned value from the Ordering Machine into localStringOrdered

  int lenoflocal; //declare a local integer type variable
  lenoflocal = localStringOrdered.length(); //set lenoflocal to the ordered version of the local string's length

  string sameDataWord; //declare a local string type variable
  string rawDataWord; //declare a local string type variable
  string currentDataWord; //declare a local string type variable

  int counter; //declare a local integer type variable
  int LargestValueFound; //declare a local integer type variable
  int sizeofSameWord = 0; //declare a local integer type variable and set it to zero

  //below (for loop) is for the case if the entered letters can make up a word on their own(all of the letters), since we need to distinguish this case, this will loop until it reaches all the data strings
  for (int isame = 0; isame < iFileLines; isame++) {
    
    sameDataWord = orderedDataStrings.at(isame); //set the sameDataWord to the orderedDataString at the location isame (index of this loop)
    rawDataWord = rawDataStrings.at(isame); //set the rawDataWord to the RawDataStrings at the location isame (index of this loop)
    
    // following if statement identifies if the string entered by the user is the same as the string in the datafile, or alternatively if all the letters entered by the user can be arranged into a word on its own
    if ( sameDataWord == localStringOrdered ) {
      
      //if so display this case to the user, giving out the exact word the data file
      cout << endl << "You can create a word using all of the letters! For example: " << rawDataWord << endl;
      
      //the for loop below counts the amount of other words that can be created from all the letters entered by the user, and will do so until it reaches the end of the file
      for (int isamecounter = 0; isamecounter < iFileLines; isamecounter++) {

        sameDataWord = orderedDataStrings.at(isamecounter); //sameDataWord is going to be set to orderedDataStrings at the location isameCounter

        //following if statement identifies if the string in the data file is exactly the same as the entered string by the user
        if ( sameDataWord == localStringOrdered ) {

          sizeofSameWord++; //if so the we increment the sizeofSameWord
        } 
      }

      //display the sizeofSameWord to the user (here -1 is necessary since the loop will count the user's word as well, so it needs to be subtracted)
      cout << "You can also create up to " << sizeofSameWord-1 << " word(s) with these letters!" << endl;

      //this return statement causes the function to exit, since we have already found the largestwordavailabe and don't want to continue
      return;
    }
  }

  //the rest of the function represents another way to identify the largestwordavailable, now that we know the string entered by the user is not an exact string on the data file, but a larger set of letters

  //for statement will loop, starting from 0 until it reaches the end of the data File
  for (int imain = 0; imain < iFileLines; imain++) {

    int i1 = -1; //declare a local integer type variable
    int score = 0; //declare a local integer type variable
    currentDataWord = orderedDataStrings.at(imain); //set the currentDataWord to orderedDataStrings vector's location at imain

    string refreshlocal; //declare a local string type variable
    refreshlocal = localStringOrdered; //set the refreshlocal to localStringOrdered

    int lenofcurrent; //declare a local integer type variable
    lenofcurrent = currentDataWord.length(); //set the lenofcurrent to the length of the currentDataWord

    //the upcoming instructions will only be executed if lenght of localstring is greater than or equal to length of the current Data File string
    if (lenoflocal >= lenofcurrent) {

      jump1: //declare a jump point for jump1

      i1++; //inc i1
      int i2 = 0; //declare a local variable i2 starting at 0

      //the following for statement will keep looping until it reaches the lenght of the user's string (length of the localstring)
      for (int i = 0; i < lenoflocal; i++) {

        //following instructions will only be executed if currentDataWord's i1th char (starting with 0th location) is the same as refreshlocal's (localStringOrdered) i2th char (starting with 0th location)
        if ( currentDataWord[i1] == refreshlocal[i2] ) {
          
          score++; //increment score (an indicator to see if the largestwordavailable satisfies our condition)
          refreshlocal.erase (refreshlocal.begin()+i2); //erase the character on refreshlocalString at location i2 
          goto jump1; //jump to "jump1"

        } else {
          i2++; //inc i2, move to the other char on refreshlocal
        }

        if ( score == lenofcurrent) {
          counter++; //inc the counter, this will let us identify if we got a largestwordavailabe or not to display necessary message to the user (at the end of the function)
          string currentDataWordOrganized; //declare a local string type variable
          currentDataWordOrganized= rawDataStrings.at(imain); //set this previously declared variable to rawDataStrings (original strings from data file) at location imain (same pointer where we picked up our ordereddataword)
          LargestWord.push_back(currentDataWordOrganized); //push back(place) the currentDataWordOrganized into the LargestWord vector
          break; //if this if statement is executed, and reached to this point break this for loop
        }
      }
    }  
  }

  int samelengthcount; //declare a local integer type variable
  int integerLargest = 0; //declare a local integer type variable 
  int maxLargestWord = LargestWord.size(); //set the maxLargestWord to LargestWord vector's size

  vector<string> highestlenStrings; //declare a string type vector named "highestlenStrings"
  int sizeforLargest; //declare a local integer type variable
  string FindLargestLen; //declare a local string type variable

  //create a for instruction that will loop until it reaches the LargestWord vector's size
  for ( int indexforlargestlen = 0; indexforlargestlen < maxLargestWord; indexforlargestlen++) {

    string FindLargestLen; //declare a local string type variable
    FindLargestLen = LargestWord.at(indexforlargestlen); //set the FindLargestLen to the LargestWord vector's indexforlargestlen's location

    int lenofWord; //declare a local integer type variable
    lenofWord = FindLargestLen.length(); //set this previous variable to the length of the FindLargestLen

    //At this point we have all the possible words that can be created using the letters user has entered, the next step should be focused on identifying the longest word that can be creating using the letters. If we had a word that had only 3 letters, but now we have found a word that can be created with 4 letters, we should reset, moreover, find and count all the 4 letter words if/until we reach a word that can be created with 5 letters.

    //execute the following instructions if lenofWord is bigger than or equal to integerLargest(starts with 0 to set it initially)
    if ( lenofWord >= integerLargest ) {

      //execute the following instructions if lenofWord is bigger than integerLargest
      if ( lenofWord > integerLargest ) {
        //this is a special ocasion if we move to a higher length word, everything gets reset
        samelengthcount = 0; //samelength set to 0
        highestlenStrings.clear(); //clear the higestlenStrings vector
      }

      integerLargest = lenofWord; //set the integerLargest to the length of the word(FindLargestLen)
      LargestValueFound = indexforlargestlen; //set the LargestVaueFound to indexforlargestlen integer
      
      //the following instructions will be executed only if lenofWord is the SAME as integerLargest
      if ( lenofWord == integerLargest) {

        samelengthcount++; //inc samelengthcount
        highestlenStrings.push_back(FindLargestLen); //add the FindLargestLen string into the highestlenStrings vector
        sizeforLargest = highestlenStrings.size(); //set sizeforLargest to the size of the previous vector (update the sizeforLargest)
      }
    }
  }

  //The last part of the function is responsible for displaying the results to the user depending on the counter we have included: if we have found at least 1 largestword the following cout's will be executed, if we didn't have any words to create from the set of letters entered by the user, the else part is executed
  if ( counter > 0 ) {

    cout << endl << "Largest Word Available: " << LargestWord.at(LargestValueFound) << endl;
    cout << "Number of OTHER words found in the same lenght as " << LargestWord.at(LargestValueFound) << ":  " << samelengthcount-1 << endl;
    //if we wish to see all the strings we have achieved in the same size of our largestword, we can create a loop to display each string one by one, starting from 0 and ending at the size of the vector, the vector's name is highestlenStrings, so use highestlenStrings.at(i) to display
  } else {

    cout << endl << "Sorry no word found. " << endl;
  }
}


//the function below expects an integer number, and returns nothing. It's purpose is to keep all the strings in both orderedDataStrings vector and rawDataStrings vector at the same length. (What ever length is given in the "int number" parameter.)
void Length_Ordering_Machine(int number) {

  int maxletters; //declare a local integer type variable
  maxletters = number; //give the expected parameter to this variable

  string orderedWord; //declare a local string type variable
  int lenofOrderedWord; //declare a local integer type variable

  string rawWord; // declare a local string type variable

  for ( int i = 0; i < iFileLines; i++) {
    
    orderedWord = orderedDataStrings.at(i); //hold the string that will be taken from the orderedData vector, in orderedWord, to get its length basically
    lenofOrderedWord = orderedWord.length(); //get the length of the orderedWord

    rawWord = rawDataStrings.at(i); //hold the string that will be taken from the rawData vector, in rawWord

    //execute the following instructions only if the length of the word in the data file is the same as the number we have requested (int number) 
    if ( lenofOrderedWord == number ) {
      
      XLetterOrderedWords.push_back(orderedWord); // add orderedWord to the end of the global vector XLetterOrderedWords
      XLetterRawWords.push_back(rawWord); //add rawWord to the end of the global vector xLetterRawWords
    }
  }
  //set the global variable xLetterGroup to the size of the very XLetterOrderedWords vector filled
  xLetterGroup = XLetterOrderedWords.size();
}

//Algorithm for Find_All_3_Letter_Anagrams: this function will be using the XLetterOrderedWords vector and XLetterRawWords vector, that will be prepared before this function is executed, by Length_Ordering_Machine. Starting from the first string in this vector, whole vector will be scanned to see if there is an anagram of this string. The main string will be erased as well as any string that is an anagram of it. These strings are going to be set in local variables in order to not lose them, to be able to compare and save the rawWord. At the end of each scan, strings will be displayed if there is an anagram found or not. (I have specifically left the testing works for this function, since this one was a little more complicated and seeing each cycle is appeared a lot more necessary)
void Find_All_3_Letter_Anagrams(void) {

  vector<string> anagramGroup; //declare a local string type vector that will hold the anagram words
  
  int changingSize; //declare a local integer type variable that will be the limit for the loops
  changingSize = xLetterGroup; //set the changingSize variable to xLetterGroup global variable

  string currentWord; //declare a local string type variable
  string currentRawWord; //declare a local string type variable
  string nextWord; //declare a local string type variable
  string nextRawWord; //declare a local string type variable

  int i1 = 0; //declare and set the local integer type variable to 0, this is a variable that should always be 0,since we will be asking for the first string of the vector over and over again, since we delete the one we pick each time

  //this for loop is for picking the first string (0th location) from the vector each time until we reach the size of the vector. Which starts out with xLetterGroup, and later altered depending on the actions.
  for ( int iword = 0; iword < changingSize; iword++) {

    currentWord = XLetterOrderedWords.at(i1); //set the currentWord to the string inside of the vector XLetterOrderedWords at location i1
    currentRawWord = XLetterRawWords.at(i1); //set the currentRawWord to the string inside of the vector XLetterRawWords at location i1

    XLetterOrderedWords.erase(XLetterOrderedWords.begin()+i1); //erase the string from the vector XLetterOrderedWords at location i1
    XLetterRawWords.erase(XLetterRawWords.begin()+i1); //erase the string from the vector XLetterRawWords at location i1

    anagramGroup.push_back(currentRawWord); //place the string currentRawWord into the vector anagramGroup (at the end of the vector)

    changingSize = XLetterOrderedWords.size(); //update the changingSize integer to the size of the vector XLetterOrderedWords, since we are erasing elements

    //this for loop is for choosing the next word to compare with the currentWord, until we reach the end of the vector XLetterOrderedWords
    for ( int inext = 0; inext < changingSize; inext++ ) {
      
      //cout << "Max range before: " << XLetterOrderedWords.size() << endl;

      nextWord = XLetterOrderedWords.at(inext); //set the nextWord string to the string from vector XLetterOrderedWords at location inext
      nextRawWord = XLetterRawWords.at(inext); //set the nextRawWord string to the string from vector XLetterRawWords at location inext

      //cout << endl << "currentRawWord: " << currentRawWord << endl;
      //cout << "currentWord position: " << i1 << endl;
      //cout << endl << "nextrawWord: " << nextRawWord << endl;
      //cout << "nextWord position: " << inext << endl;

      //the purpose of this if statement is to identify if the currentWord is the same as nextWord (finds out if nextWord is an anagram or not)
      if ( currentWord == nextWord ) {

        anagramGroup.push_back(nextRawWord); //add the nextRawWord to the end of the anagramGroup vector

        //since nextWord is an anagram of the currentWord, it is time to erase them from both vectors for upcoming comparisons
        XLetterOrderedWords.erase(XLetterOrderedWords.begin()+inext); //erase the string at inext location on the vector XLetterOrderedWords
        XLetterRawWords.erase(XLetterRawWords.begin()+inext); //erase the string at inext location on the vector XLetterRawWords

        changingSize = XLetterOrderedWords.size(); //update the changingSize integer to the size of the vector XLetterOrderedWords, since we are erasing elements
        
        //cout << endl << "Found One Anagram!" << endl;

        inext--; //dec inext in this case, since we are erasing additional strings, next string will be in inext's current value. Since we inc inext every cycle in the for loop, we need to dec for once.

      }

      //cout << endl << "Index of Ordered Vector: " << inext << endl;
      //cout << "Max range after: " << changingSize << endl;
      //cout << endl << "End of the Scan on currentWord" << endl << endl << endl;
    }

    int sizeofAnagrams; //declare a local string type variable 
    sizeofAnagrams = anagramGroup.size(); //set this variable to the size of the vector that holds all the anagrams found for the specific word

    //if statement that decides if we got any anagrams of the word or not, so that we can display the correct output to the user
    if ( sizeofAnagrams > 1 ) {

      cout << endl << endl << "Anagram/Anagrams found for " << anagramGroup.at(0) << " is/are: ";

      for ( int idisplay = 1; idisplay < sizeofAnagrams; idisplay++) {
          
        cout << anagramGroup.at(idisplay) << " ";
      }
    }

    anagramGroup.clear(); //done with the elements of this anagram set, move on to the next one
    changingSize--; //dec the changingSize integer variable for the next loop
  }

  cout << endl; //seperation
}

//Algorithm for Find_All_5_Letter_Anagrams: I didn't want to copy and paste the same instructions for this function, therefore, I decided to create the Length_Ordering_Machine which expects one integer value, and that is the 3 or 5 letter anagram requirement. The menu option runs that first. The application in 5 Letter Anagram will eventually be the same as 3 Letter Anagram, therefore when this function is executed 3 Letter Anagram function is executed but only with a different parameter for Length_Ordering_Machine.
void Find_All_5_Letter_Anagrams(void) {

  Find_All_3_Letter_Anagrams();
}


/*
//This function is only used for testing certain parts of other functions but mostly global variables

void Test(string originalString) {

}
*/


void Menu(void) { //function displays the menu to the user

  double newSeconds; //declare a local double type varialbe

  //set the t1 as the current clock as soon as Menu runs
  auto t1 = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::seconds(1));

  //if statement below is to keep the seconds 0 at the start of the program, since we don't have a function that was ran by the user, it should start out with 0.
  if ( (seconds - newSeconds) < 0 ) {

    seconds = 0;
    newSeconds = 0;
  }

  string currentString= "alert"; //variable that gets its data from GetWord function, this variable starts with the student ID to be displayed at the "current word/phrase:"
  string modifiedString= "nothing"; //variable used for the reverseWord function
  string menuOption; //a string variable since the entered data may be a character or a number, more info on if statement down below
  int intforMenu;
  
  do { //start an endless loop - this is so the associated code block repeats forever
    cout << endl << "C++ Anagram Solver Challenge" << endl << endl; //display a title for the menu
    cout << "\t1. Enter a word or phrase (current word/phrase is: " << currentString << ")." << endl;
    cout << "\t2. Find an anagram of the word." << endl;
    cout << "\t3. Find the largest word containing (most of) these letters." << endl;
    cout << "\t4. Find all possible 3 letters words that are also anagrams." << endl;
    cout << "\t5. Find all possible 5 letters words that are also anagrams." << endl;
    /*cout << "\t6. Test!" << endl; */
    
    cout << endl << "\t0. Quit the program." << endl << endl;

    cout << endl << "Time taken to complete the last function was: " << seconds - newSeconds << "ms" << endl;

    newSeconds = seconds;
  
    cout << "\nPlease enter a valid option (1 - 6 or 0 to quit): ";
    cin >> menuOption; //store the choice made by the user in the variable menuOption

    if ( (menuOption != "0") && (menuOption != "1") && (menuOption !="2") && (menuOption != "3") && (menuOption != "4") && (menuOption != "5") /* && (menuOption != "6") */ )
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
      case 4: //"if the menuOption = 2", option 2 should call the function Find_Anagrams
        Length_Ordering_Machine(3);
        Find_All_3_Letter_Anagrams();
        //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
      case 5: //"if the menuOption = 2", option 2 should call the function Find_Anagrams
        Length_Ordering_Machine(5);
        Find_All_5_Letter_Anagrams();
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
    //set the t3 as the current clock at the end of the Menu
    auto t3 = std::chrono::high_resolution_clock::now();
    //t3-t1 to get the time spent during this function
    seconds = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t1).count();

  } while(true); //this tells the computer the conditions to break the "do" loop - while true is always true and therefore will continue forever; in essence and endless loop
}


int main() { 
//this is the required function that will automatically execute when the program is run

  //start the program with the following functions
  ReadFile();
  FileLineFounder_Machine();
  Menu();
}


/*
---------------- TEST LOG ----------------

Note: Apologies, if the dates in test log do not match perfectly. I had my test log written in a word document with no dates. I tried to match them as best as I can, nonetheless. (Didn't want to put // on every line until I found a better way of doing so.)

3/18/19 | Get_Word | SUCCESS 
This function was also asked in Task 1 of the assignment, I have replicated it from my previous work, it was pretty straight forward, user is asked for a string, the string is saved here and returned

3/18/19 | Read_File | FAILED
I wanted to use the read file function as a tool to get each word from the file into an array, therefore I had to declare a global array, but this was problematic for me. I had to set the size of the array if I wanted to declare it. So I could prepare a function that would count the amount of strings available in the Data File, but the problem here is now that, the first function that will be executed is going to be int main function and the complier will want to look for the size of the global variable, array, I have declared but I cannot specify it, because my function won't run without me specifying it. Additionally, I cannot run my string counter function (for the file) before my main. I need alternative methods for this.

3/19/19 | Read_File | SUCCESS
After dealing with arrays, as I was researching the web, I have came across "vector" library, an array that can be declared easily and does not require any sort of size measurements since it shrinks and enlarges as the array increases or decreases in size. I decided to put all the strings I can get from the Data File into a vector and play around with them for later use. I also declared other vectors to hold the ordered version of the datafile strings.

3/20/19 | Find_Anagrams | FAILED
I came up with an algorithm, that would not just reorder the string entered by the user, but would reduce the chars that were same to 1. For instance: "Anagram" would look like "Agmnr" (only 1 "a" instead of 3 "a"s). I thought this would be useful because my point system would function better at it. (Talked about the point system in the algorithm, if I still used it). Overall, it was not necessary at all...

3/21/19 | Find_Anagrams | SUCCESS
This time the currentWord would be reodered and then saved into the end of a vector (and the original word is saved to another vector at the same location as the ordered one on another vector) . From here the new vector would be scanned if the ordered version of the user's string (originalString) is the same as the currentWord's ordered version. And then it is displayed to the user.

3/21/19 | Largest_Word_Available | FAILED
The algorithm for this function was a bit complicated at first and too extensive. I haven't included my trial versions in the test log, because I had over 10 tries on this. At the end I have reached to a successful largest word finder. However, the "exit status 1" error kept showing up. I have scrapped the algorithm for this, since it was over-complicated.

3/22/19 | Largest_Word_Available | FAILED
This turn, I wanted to start out more organized. I took all the orderedStrings from the DataFile and scanned each string if, any of the strings from the orderedStrings had a character that does not belong to the user's string's. Moreover, created a score based system. Each time a character from the userString was inside of the orderedString from the DataFile, that string would get a point. This started out pretty well but got exit status 1 error again.

3/22/19 | Largest_Word_Available | FAILED
I have realized I left out small details. I have implemented a code that would not accept any string from the orderedWord file that is larger than the user's entered string. Since we cannot duplicate certain characters from the user's string, this code would be useful. That was not the issue, still got exit status 1 error.

3/23/19 | Largest_Word_Available | SUCCESS
The exit status 1 error, was appearing because of the vector and the loop. The loop wasn't able to finish itself because of my actions with the vector itself. I was erasing words from the vector wasn't taking into account how it would effect the loop (I was taking it into account, but I couldn't identify how it was effecting it). Therefore, I came up with the idea of updating the loop max value, every loop, this was easy to execute since the max value of the loop was the size of the vector I was using.

3/24/19 | Find_All_3_Letter_Anagrams | FAILED
In this function the datafile strings had to be limited down to their length. Therefore, I have created a length ordering machine function that would narrow the vectors down to the requested length, in this case 3 letters only. Basically, this function was supposed to scan the new formed 3 letter vector and see which ones were an anagram of one another. It initiates by analyzing the first one, and then scans the rest of the 3 letter vector. If there is a word that is the same, it is then added to another vector to display later. At the end of both loops, the last vector is displayed and then cleared. My intention was to repeat until it reaches the end of the 3 letter vector but it gives me the exit status 1 error. Since I am pointing at a location in the vector that is empty. This is because I am deleting strings from the main vector as I go.

3/25/19 | Find_All_3_Letter_Anagrams | SUCCESS
To avoid the previous complication, I decided to remove the first string that I am taking as a sample to scan the rest of the 3 letter vector (Of course I replace it in a local variable first). This method worked out perfectly. Also I have used the "updating loop limit each cycle" technique from my largest_Word_Available function.

3/25/19 | Find_All_5_Letter_Anagrams | SUCCESS
Just changed the Length_Ordering_Machine input to 5 and called the Find_All_3_Letter_Anagrams function.

---------------- END OF THE TEST LOG ----------------

*/
