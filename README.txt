ELIZA Psychiatrist Chatbot - Final Submission
-----------------------------------------------

Group Members:
Aarinn Vittolia

Project Description
--------------------

This project simulates a conversation between a user and a psychiatrist, based on ELIZA, one of the earliest natural language processing programs. The user communicates using normal sentences, common phrases, or short answers such as "yes" or "I don't know" -- there is no menu and no fixed input format.

The program uses C++ regular expressions to recognize patterns in the user's input and generate a related response. All three required regex functions are used: regex_match() confirms the user typed the exit command "bye". regex_search() is used across all seven functionality components (56 patterns total) to detect keywords and phrases in the user's input. regex_replace() is used in TextUtils::reflect() to swap first- and second-person pronouns (e.g. "my mother" becomes "your mother") so captured text can be echoed back naturally, the way the original ELIZA did.

The program stores every normalized user response. If the exact same response is entered twice in a row, ELIZA asks the user to say something different instead of answering normally. If no component's patterns match the input, ELIZA falls back to a rotating set of generic prompts so every input still receives a response. The conversation ends when the user types "bye".

Project Files
-------------

main.cpp - Entry point. Starts the ELIZA conversation loop. Contains only int main().

ConversationManager.cpp / ConversationManager.h - Controls the overall conversation: reading input, detecting "bye", catching repeated identical answers, dispatching to each functionality component in order, and falling back to a generic response when nothing matches.

GenericVerb.cpp / GenericVerb.h - Handles common verb patterns such as have, purchase, travel, know, and learn.

Relationship.cpp / Relationship.h - Handles love and relationship related input (love, spouse, girlfriend, boyfriend, breakups).

Concern.cpp / Concern.h - Handles serious or concerning statements (hate, anger, fear, worry, and statements naming suicide, which receive a distinct, supportive response).

Financial.cpp / Financial.h - Handles money, savings, investments, debt, and bankruptcy related topics.

Wellbeing.cpp / Wellbeing.h - Handles exercise, vitamins, relaxation, sleep, tiredness, and stress.

Education.cpp / Education.h - Handles school, university, courses, studying, exams, and graduation related topics.

Entertainment.cpp / Entertainment.h - Handles concerts, movies, dancing, restaurants, and bars.

TextUtils.cpp / TextUtils.h - Shared text helper functions used across the components: lowercasing, trimming, and pronoun reflection (implemented with regex_replace()).

Compilation Instructions
-------------------------

Open a terminal in the directory containing all of the .cpp and .h files listed above and run:

g++ -std=c++11 main.cpp ConversationManager.cpp TextUtils.cpp GenericVerb.cpp Relationship.cpp Concern.cpp Financial.cpp Wellbeing.cpp Education.cpp Entertainment.cpp -o eliza

This produces an executable named "eliza". The program requires the C++11 standard because it uses the <regex> library.

Run Instructions
------------------

Run the program using:

./eliza

ELIZA will print a welcome message and wait for input. Type ordinary sentences, short phrases, or answers like "yes" or "I don't know". Type "bye" at any time to end the conversation; ELIZA will print a goodbye message and the program will exit.
