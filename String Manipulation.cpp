#include <iostream> //defines the standard devices cin, cout, clog, cerr
#include <string> //defines string types and conventions including begin & end iterator
#include <algorithm> //defines a collection of ranged functions
#include <random> //defines random number generation facilities

using namespace std; //tell the compiler that by default to use the “std”

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

//Algorith for Reverse_Word: take the originalString, start from the end of the string, put the first word in the originalString to the last letter's position in the originalString, do this until index reaches 0.
std::string Reverse_Word(string originalString) { //function that will reverse the current word, also this function is designed to expect one argument (called originalString) and returns a string
  string localString; //declate a local variable called localstring
  int len; //declare a local variable called len of type integer
  //cout << "Original String: " << originalString << "\n"; //lets us see the originalString
  len = originalString.length(); //execute a special function (part of the 'string' datatype) that returns the number of character contined in the variable
  //cout << "Total Length: " << len << "\n"; //lets us see the lenght of the string

  //this block of code loops backwards through the "originalString" variable
  for (int i = len; i >= 0; i--) {
    //this executes a loop that uses and decreases a local and temporary variable (i) staring with the value contained in 'len' while 'i' is great than/equal to 0
    localString = localString + originalString[i]; //essentially this instruction adds the specific letter at position 'i' in the string variable 'originalString' to the 'localstring' variable
  }
  //at this point the 'localString' variable should now contain the same information as originalString
  return localString; //return the value contained in the localstring local variable
}

//Algorithm for To_Upper: take each letter and if they are above 90 ASCII value, which means they should be lower case, then -32 from their value, which will convert them to the upper case, look at the ASCII table for more information. (The reason we don't have a seperate line of code to display their value is because of the feature in C++ version 11, where it does not require for the programmer to do so, but identifies their value automatically.)
std::string To_Upper(string originalString) { //this function is designed to expect one argument (called originalString) and returns a string

string localString; //declare a local variable called "localString"
//cout << "Original String: " << originalString << "\n"; //gives us the originalString

int len; //declare a local variable called len of type integer
len = originalString.length(); //execute a special function (part of the 'string' datatype) that returns the number of character contined in the variable

//this loop will start from the first letter and keep going until the last letter
for (int i = 0; i <= len; i++) {
  //it will replace the letter located in the i location (which will increase each loop) by 32 which is the number to make a letter capital, if it is lower case(>90)
  if (originalString[i] > 90) {
    originalString[i] = originalString[i] - 32;
  } 
  localString = originalString;
  //localString is being set to the changed/altered temporary string
}
return localString; //return the value contained in the localstring local variable
}

//Algorithm for To_Lower: take each letter that are smaller than 97 and not 32(that is the whitespace), and add 32 to it to make it uppercase
std::string To_Lower(string originalString) { //this function is designed to expect one argument (called originalString) and returns a string

string localString; //declare a local variable called localString
//cout << "Original String: " << originalString << "\n"; //lets us see the originalString before

int len; //declare a local variable called len of type integer
len = originalString.length();
//this will loop until the lenght of the word
for (int i = 0; i <= len; i++) {
  //if statement changes the character to lower case, if the character is uppercase(<97) and adds 32, however if you add 32 to 0 (space) it will become a the "@" sign, therefore, the && operator is added to only execute this addition if the letter we are dealing with is not the " " space.
  if ((originalString[i] < 97) && (originalString[i] != 32)) {
    originalString[i] = originalString[i] + 32;
  } 
  localString = originalString;
  //localString is being set to the changed/altered temporary string
}
return localString; //return the value contained in the localstring local variable
}

//Algorithm for Randomise_Word: create 2 strings and set both of them to originalString, take a random letter from the first string, delete that letter from the first string(so that we can't pick it again), place it on the location 0 (first letter location) on the second string. Repeat until you run out of letters in the first string.
std::string Randomise_Word(string originalString) { //this function is designed to expect one argument (called originalString) and returns a string

string localString; //declare a local variable called localString
localString = originalString; //set the localString to originalString

int lengthofOriginal; //declare a local variable called len of type integer
lengthofOriginal = localString.length(); //execute a special function (part of the 'string' datatype) that returns the number of character contined in the variable

//cout << endl << "First String Length: " << lengthofOriginal << endl;

//NOTE: I would like to call these strings as Arrays because I prefer them to identify as an Array of letters, since I will be working on them one by one with an index (personal preference)
string previousArray = localString; //place the word in the previosarray, set it up (array of characters)
string newArray = localString; //place the word in the newarray,set it up (array of characters)

//cout << endl << "PreviousArray BEFORE operations: " << previousArray << endl;
//cout << endl << "NewArray BEFORE operations: " << newArray << endl;

//this loop will start from the first letter and keep going until the last letter
for (int i = 0; i < lengthofOriginal; i++) {
  //execute this function as much as times as the letters there are in the word

  random_device rd; // obtain a random number from hardware
  int n; //declare a local integer "n"
  n = (rd() % previousArray.length()); //"n" will be the remainder of the random number found (this is a huge number) divided by the lenght of the previous array, this will give us an integer value in "n" from 0 to lengthofOriginal-1
  int letterDeleterPointer; //index of the letter that will be deleted
  letterDeleterPointer = n; //setting that random number to the deleter index

  //cout << endl << "Location to be replaced in newArray: " << i << endl;
  //cout << endl << "Random location generated (max = previousArraylenght): " << n << endl;
  //cout << endl << "Pointer for the letter to be deleted: " << letterDeleterPointer << endl;
  //cout << endl << "Letter of newArray being replaced: " << newArray[i] << endl;
  //cout << endl <<"Letter of the previousArray being replaced in newArray: " << previousArray[letterDeleterPointer] << endl; 

  newArray[i] = previousArray[letterDeleterPointer]; //sets the index letter of the new string to the random letter selected from the previous array that will be deleted later

  previousArray.erase (previousArray.begin()+letterDeleterPointer); //erases the random letter selected from the previous string

  //cout << endl << "Letter of newArray AFTER: " << newArray[i] << endl;
  //cout << endl << "previousArray string AFTER: " << previousArray << endl;
  //cout << endl << "newArray string AFTER: " << newArray << endl << endl << endl;

  originalString = newArray; //fully randomized word is now in originalString
  localString = originalString;
  //localString is being set to the changed/altered temporary string
  } 
return localString; //return the value contained in the localstring local variable
}

//Algorithm for Order_Word: take originalString, look at the first and the second letter, compare them, if first one has a higher value than the second one swap their locations, in this case they should be both capital to compare since lower case letters have more value on the ASCII table, therefore we need to save these letters beforehand, then turn them into capital letters for comparing, make a comparingString, place these two letters in the necessary order in another string "orderedString", update this string every loop, maximum loop must be the times the length of the string, so lets say z is the first letter, it will have to go all the way to the end, then z should be moved lenght times.
std::string Order_Word(string originalString) {

string localString; //declare a local variable called localString
localString = originalString; //set the localString to originalString

string tempSaveOne; //create a string for saving the letter before making it capital (i1 (index1) letter)
string tempSaveTwo; //create a string for saving the letter before making it capital (i2 (index2) letter)

tempSaveOne = localString; //setting tempSaveOne to localString
tempSaveTwo = localString; //setting tempSaveOne to localString

int lengthofOriginal; //setting a local variable for lenght of the string in integer
lengthofOriginal = localString.length(); //lenght of the string in integer value

//cout << endl << "This is the lenght of the currentString: " << lengthofOriginal << endl; 

string orderedString; //declaring a local variable for the string that will be updated each cycle
orderedString = localString; //orderedString is set to localString

int i1 = 0; //comparing first letter index
int i2 = 1; //comparing second letter index

//this will loop until the lenght times of the string is reached, ex string: "Hello" will be executed 4 times, this 4 and not 5, this is because location 0 (zero) is the 1st location of the string which is "H".
  for (int iloop1 = 0; iloop1 < lengthofOriginal; iloop1++) {

    i1 = 0; //setting i1 index to 0 for the upcoming loop, so location 0, which will be the first letter
    i2 = 1; //setting i2 index to 1 for the upcoming loop, so location 1, which will be the next letter

    //this loop is where the letters are being moved with the bubble sort algorithm, and it will loop until the lenght-1 times of the string, this is because we already have 2 index integers goes until A = {0-1, 1-2, 2-3, 3-4, 4-5}, so if our string is "Hello" then this should be executed 4 times not 5, since |A| = 5 and we start from 0, not 1.
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
      //cout << endl << "orderedString AFTER operation: " << orderedString << "  i1:" << i1 << "  i2:" << i2 << endl;

    i1++; //inc the string index
    i2++; //inc the string index

    localString = orderedString; //localString is now set to the string that was being updated in the loop
    }
  }
  return localString; //return the value contained in the localstring local variable
}


void Menu(void) { //function displays the menu to the user
  string currentString= "17062941"; //variable that gets its data from GetWord function, this variable starts with the student ID to be displayed at the "current word/phrase:"
  string modifiedString= "nothing"; //variable used for the reverseWord function
  string menuOption; //a string variable since the entered data may be a character or a number, more info on if statement down below
  int intforMenu;
  
  do { //start an endless loop - this is so the associated code block repeats forever
    cout << endl << "C++ String Manipulation Challenge" << endl << endl; //display a title for the menu
    cout << "\t1. Enter a word or phrase (current word/phrase is: " << currentString << ")." << endl;
    cout << "\t2. Reverse the current word." << endl;
    cout << "\t3. Convert the current word to uppercase." << endl;
    cout << "\t4. Convert the current word to lowercase." << endl;
    cout << "\t5. Randomise the letters in the current word." << endl;
    cout << "\t6. Sort the letters in the current word in ascending alphbetic order." << endl;
    cout << "\t0. Quit the program.";
    cout << "\n\n\tThe last word/phrase returned was: " << modifiedString << endl;
    cout << "\nPlease enter a valid option (1 - 6 or 0 to quit): ";
    cin >> menuOption; //store the choice made by the user in the variable menuOption

    
    if ( (menuOption != "0") && (menuOption != "1") && (menuOption != "2") && (menuOption != "3") && (menuOption != "4") && (menuOption != "5") && (menuOption != "6") )
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
      case 2: //"if the menuOption = 2", option 2 should call the function Reverse_Word 
        modifiedString = Reverse_Word(currentString); //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
      case 3: //"if the menuOption = 3", option 3 should call the function To_Upper
        modifiedString = To_Upper(currentString); //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
      case 4: //"if the menuOption = 4", option 4 should call the function To_Lower
        modifiedString = To_Lower(currentString); //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
      case 5: //"if the menuOption = 5", option 5 should call the function Randomise_Word
        modifiedString = Randomise_Word(currentString); //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute

      case 6: //"if the menuOption = 6", option 6 should call the function Order_Word
        modifiedString = Order_Word(currentString); //call the function and store any returned value in the local variable currentString
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be execute
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

int main() { //this is the required function that will automatically execute when the program is run
  Menu(); //start the program menu function
}

/*
TEST LOG

5.May.2019:

    Get_Word function
-Was not able to get a phrase, but only a word, this is caused by the cin >> taking whitespaces as termination, therefore I used "getline(cin, UserString)" and it was a SUCCESS.
    menuOption
-Here the menuOption was declared as a string on the given task, therefore I had to convert it to an integer because the switch statement required an integer not a string, I used int "intforMenu = stoi(menuOption)" conversion and this worked out perfectly, now the switch statement works SUCCESS.
    QuitNow function
-added the EXIT_SUCCESS to it which when executed ends the program, placed this into all of my if statements about menu options which were given specifically for each decision case, SUCCESS.

11.May.2019

    Reverse_Word function
-string is being updated starting from the last position, the index defines the replacement, starting from the first letter replacing the last letter (starting at the location len (in this case, the last letter)) SUCCESS.
    To_Upper function
-basically, takes a letter indicated by the index, if higher than 90, -32 its value (more information on the algorithm). SUCCESS.
    To_Lower function
-this has the same idea as To_Upper, however when you say <97, you also include the whitespace, so the if statment should exclude the whitepsace (more information on the if statement comment on this function) SUCCESS.

12.May.2019

    Randomise_Word function
-algorithm is given above the function
-found a code to erase a letter from a string: "previousArray.erase (previousArray.begin()+letterDeleterPointer)"
-took a huge random number from the hardware, divided it to the lenght of the string, acquired the remainder of this division to pick a random letter from the string. "random_device rd; int n = (rd() % previousArray.length());"
SUCCESS.

13.May.2019

  Order_Word function
-algorithm is given above the function
-Had problems with the result a little bit, and created a lot of testing statements with "cout <<", I was able to identify the problem was with saving the wrong temporary file to the wrong location
-for the first test I realized my repetitions were not enough, I thought about the maximum amount of repetition required, so I found out the most repetition would be needed if the first letter had the highest value, therefore needed to most repetitions, that would require there to be lenght x repetitions, but since we start from 0 (because 0 is the first location on the string), then it should be lenght-1 times. SUCCESS

END OF TEST LOG
*/
