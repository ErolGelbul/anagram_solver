<div id="top"></div>


<!-- ABOUT THE PROJECT -->
## About
String Manipulation file is a prelude for the Anagram Solver. I have implemented the following functions which the user can select using the menu:
* Input the word
* Reverse the word
* Convert to uppercase
* Convert to lowercase
* Randomise the letters
* Order the letters in alphabetical order
* Quit

Anagram Solver finds the anagram of the word using the datasets provided. Additionally, it performs other fucntions such as:
* Find the largest word available
* Find all 3 letter anagrams
* Find all 5 letter anagrams

Feel free to check it out! I included invdividual tests for each program.

### How to Run the Program

If you would like you can run the files in your own preffered environment by forking the repo, although I provided links to repl.it for both files.

## String Manipulation
Test Log:
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

<!-- Anagram Solver -->
## Anagram Solver


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

END OF TEST LOG

<!-- CONTACT -->
## Contact

Erol Gelbul - [My Website](http://www.erolgelbul.com) - erolgelbul@gmail.com

Project Link: [Painting Program](https://github.com/ErolGelbul/anagram_solver)

<p align="right">(<a href="#top">back to top</a>)</p>

