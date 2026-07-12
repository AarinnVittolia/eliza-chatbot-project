# eliza-chatbot-project
ELIZA PSYCHIATRIST CHATBOT
==========================


GROUP MEMBERS
=============

Aarinn Vittolia


PROJECT DESCRIPTION
===================

The ELIZA Psychiatrist Chatbot is a C++ program that simulates a simple
conversation between a user and a psychiatrist. The project is based on
ELIZA, one of the early natural language processing programs.

The user can communicate with the chatbot by entering normal sentences,
common phrases, or short answers. The program does not require a menu or
a special input format. It reads the complete user input and uses C++
regular expressions to find important keywords and sentence patterns.

The program uses regex_match(), regex_search(), and regex_replace() for
regular expression pattern matching and text replacement. Based on the
pattern found in the user's sentence, ELIZA selects and displays a
response related to the topic.

The chatbot contains different response components for Generic Verbs,
Love and Relationships, Concerns, Financial topics, Wellbeing, Education,
and Entertainment. Each component checks regular expression patterns
related to its topic and generates a response when a match is found.

The program contains at least 50 regular expression patterns for matching
different types of user input.

The program also stores previous user responses. If the user enters the
same response more than one time, ELIZA detects the repeated answer and
asks the user to give a different response.

If the program does not find a matching regular expression, it gives a
general response. This makes sure that every user input receives a
response.

The conversation continues until the user enters "bye". When "bye" is
entered, ELIZA displays a goodbye message and the program ends.


PROJECT FILES
=============

main.cpp
    Contains the main() function and starts the ELIZA chatbot.

ConversationManager.cpp
ConversationManager.h
    Controls the conversation flow, repeated response detection,
    program termination, and response processing.

GenericVerb.cpp
GenericVerb.h
    Handles common verb patterns such as have, purchase, travel,
    know, and learn.

Relationship.cpp
Relationship.h
    Handles love and relationship related user input.

Concern.cpp
Concern.h
    Handles serious or concerning words and statements.

Financial.cpp
Financial.h
    Handles money and financial related topics.

Wellbeing.cpp
Wellbeing.h
    Handles exercise, relaxation, sleep, vitamins, and other
    wellbeing topics.

Education.cpp
Education.h
    Handles school, university, courses, studying, and other
    education related topics.

Entertainment.cpp
Entertainment.h
    Handles movies, concerts, music, dancing, restaurants, bars,
    and other entertainment topics.

README.txt
    Contains the project description and instructions for compiling
    and running the program.


COMPILATION INSTRUCTIONS
========================

To compile the program on the CSE Linux machines, open a terminal and
go to the directory containing all project source and header files.

Use the following command:

g++ -std=c++11 main.cpp ConversationManager.cpp GenericVerb.cpp Relationship.cpp Concern.cpp Financial.cpp Wellbeing.cpp Education.cpp Entertainment.cpp -o eliza

If the program compiles successfully, an executable file named "eliza"
will be created.


RUN INSTRUCTIONS
================

After compiling the program, use the following command:

./eliza

ELIZA will display a welcome message and wait for user input.

The user can enter normal sentences, common phrases, or short answers.
The chatbot analyzes the input and displays a related response.

Example:

User: I am worried about my courses.

ELIZA: What part of your courses worries you?

The conversation continues after each response.

To end the conversation, type:

bye

After the user enters "bye", ELIZA displays a goodbye message and the
program ends.


PROGRAM FEATURES
================

The program uses C++ regular expressions for pattern matching.

The program uses regex_match(), regex_search(), and regex_replace().

The program contains at least 50 regular expression patterns.

The program accepts natural language sentences and short answers.

The program responds to every user input.

The program handles Generic Verb responses.

The program handles Love and Relationship responses.

The program handles Concern responses.

The program handles Financial responses.

The program handles Wellbeing responses.

The program handles Education responses.

The program handles Entertainment responses.

The program stores previous user responses.

The program detects repeated user answers and asks for a different
response.

The program provides a general response when no regular expression
pattern is found.

The program ends when the user types "bye".


NOTES
=====

All C++ source files and header files must be kept in the same directory
before compiling the program.

The program is designed to compile using the C++11 standard or later.

No special configuration files are required to compile or run the
program.
