ELIZA Psychiatrist Chatbot
--------------------------

Group Member:
Aarinn Vittolia


Project Description
-------------------

The ELIZA Psychiatrist Chatbot is a C++ program that simulates a simple
conversation between a user and a psychiatrist. The project is based on
ELIZA, one of the early natural language processing programs.

The user can communicate with the chatbot using normal sentences, common
phrases, or short answers. There is no menu or special input format. The
program reads the user's input and uses C++ regular expressions to find
keywords and sentence patterns.

The program uses regex_match(), regex_search(), and regex_replace() for
pattern matching and text replacement. Based on the pattern found in the
user's sentence, ELIZA generates a response related to the topic.

The chatbot handles different types of user input, including generic
verbs, love and relationships, concerns, financial topics, wellbeing,
education, and entertainment. The program contains at least 50 regular
expression patterns to recognize different user statements.

The program also stores previous user responses. If the user enters the
same response again, ELIZA detects the repeated answer and asks the user
to give a different response. If no regular expression matches the input,
the program gives a general response so that every user input receives an
answer.

The conversation continues until the user types "bye". ELIZA then
displays a goodbye message and ends the program.


Project Files
-------------

main.cpp
  Contains the main() function and starts the ELIZA chatbot.

ConversationManager.cpp
ConversationManager.h
  Controls the conversation flow, repeated response detection, program
  termination, and response processing.

GenericVerb.cpp
GenericVerb.h
  Handles common verb patterns such as have, purchase, travel, know,
  and learn.

Relationship.cpp
Relationship.h
  Handles love and relationship related input.

Concern.cpp
Concern.h
  Handles serious or concerning words and statements.

Financial.cpp
Financial.h
  Handles money and financial related topics.

Wellbeing.cpp
Wellbeing.h
  Handles exercise, relaxation, sleep, vitamins, and other wellbeing
  topics.

Education.cpp
Education.h
  Handles school, university, courses, studying, and other education
  related topics.

Entertainment.cpp
Entertainment.h
  Handles movies, concerts, music, dancing, restaurants, bars, and
  other entertainment topics.

README.txt
  Contains the project description and instructions for compiling and
  running the program.


Compilation Instructions
------------------------

Open a terminal and go to the directory containing all project source
and header files.

Compile the program using:

g++ -std=c++11 main.cpp ConversationManager.cpp GenericVerb.cpp Relationship.cpp Concern.cpp Financial.cpp Wellbeing.cpp Education.cpp Entertainment.cpp -o eliza

If the program compiles successfully, an executable file named "eliza"
will be created.


Run Instructions
----------------

Run the program using:

./eliza

ELIZA will display a welcome message and wait for the user to enter a
sentence. The user can enter normal sentences, common phrases, or short
answers.

Example:

User: I am worried about my courses.
ELIZA: What part of your courses worries you?

The conversation continues after each response.

To end the conversation, type:

bye

ELIZA will display a goodbye message and the program will end.


Notes
-----

All C++ source files and header files must be in the same directory
before compiling the program.

The program uses the C++11 standard because C++ regular expressions are
used for pattern matching.

No special configuration files are required to compile or run the
program.
