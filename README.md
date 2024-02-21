# CSC3022F Assignment 1:

A word counter program similar to the Unix command "wc".
To run this program from the command line, enter:

**cat data/example.txt | ./bin/myWC**

To properly process example textfiles with a **">"** character starting each line of valid input text (such as in the examples supplied in the assignment tab), comment out line 19 of **main.cpp** and uncomment line 18.

## Using the makefile:

The makefile can be used to compile the program. Run **make** to compile all necessary files and generate the executable.
Run **make run** to execute the program. To change the textfile being tested, copy your textfile into the /data folder and change the name of the textfile under the **run** target to the name of your textfile.

E.g.:
**@cat data/example.txt | ./bin/myWC** ---> **@cat data/newTextFile.txt | ./bin/myWC**

Run the **make clean** command to clean the bin directory of any object files and executable files.

## myWC.h and myWC.cpp
These files are the header file containing the function definitions and the implementation file containing the function implementations respectively. The processing done in **myWC.cpp** includes checking if a character is a valid character or not, processing character count and word count in the textfile, and retrieving the index of the container holding variables of type charInfo for the mastery work.