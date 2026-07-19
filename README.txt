ELIZA Psychiatrist Chatbot - Milestone 2
-----------------------------------------

Group Members:
Aarinn Vittolia


Project Description
--------------------

This project simulates a conversation between a user and a psychiatrist,
based on ELIZA, one of the earliest natural language processing programs.
The user communicates using normal sentences, common phrases, or short
answers, and the program uses C++ regular expressions (regex_match(),
regex_search(), regex_replace()) to recognize patterns in the input and
generate related responses.

For Milestone 2, the program was extended with a configuration-driven
session manager, modeled on the same Config/Region/Session pattern used
in the QParking project:

  - On startup, the program reads a configuration file that specifies
    the session grid size and the names of the region file and the
    session records file.
  - It then loads the initial session region: a grid of chat session
    slots, where each cell holds a session ID, "-1" for an empty slot,
    or "R" for a reserved slot.
  - It loads the registered session records (id, username, contact,
    start time, end time) from the session file.
  - It displays the initial session region to the console and saves it
    to initial_region_output.txt.
  - It then starts the normal ELIZA conversation loop, unchanged from
    Milestone 1: the chatbot responds to generic verbs, love/relationship
    topics, concerns, financial topics, wellbeing, education, and
    entertainment topics, detects repeated identical answers and asks
    the user for something different, and ends the session when the
    user types "bye".


Project Files
-------------

main.cpp
  Entry point. Reads the config file, loads the region and session
  files, displays and saves the initial region, then runs the ELIZA
  conversation loop.

Config.cpp / Config.h
  Reads the configuration file (grid size, region file name, session
  file name).

Region.cpp / Region.h
  Loads the session grid from a CSV region file, displays it, and
  saves it back out to initial_region_output.txt.

Session.cpp / Session.h
  Loads registered session records from a CSV session file.

ConversationManager.cpp / ConversationManager.h
  Controls the ELIZA conversation flow, repeated response detection,
  program termination, and dispatch to each functionality component.

GenericVerb.cpp / GenericVerb.h
  Handles common verb patterns such as have, purchase, travel, know,
  and learn.

Relationship.cpp / Relationship.h
  Handles love and relationship related input.

Concern.cpp / Concern.h
  Handles serious or concerning words and statements.

Financial.cpp / Financial.h
  Handles money and financial related topics.

Wellbeing.cpp / Wellbeing.h
  Handles exercise, relaxation, sleep, vitamins, and other wellbeing
  topics.

Education.cpp / Education.h
  Handles school, university, courses, studying, and other education
  related topics.

Entertainment.cpp / Entertainment.h
  Handles movies, concerts, music, dancing, restaurants, bars, and
  other entertainment topics.

TextUtils.cpp / TextUtils.h
  Shared text helper functions (trimming, case conversion, pronoun
  reflection) used across the functionality components.

config.txt
  Sample configuration file: grid rows, grid columns, region file
  name, session file name.

region.csv
  Sample initial session region grid.

sessions.csv
  Sample registered session records.


Compilation Instructions
-------------------------

Open a terminal and go to the directory containing all project source
and header files. Compile using:

g++ -std=c++11 main.cpp Config.cpp Region.cpp Session.cpp ConversationManager.cpp GenericVerb.cpp Relationship.cpp Concern.cpp Financial.cpp Wellbeing.cpp Education.cpp Entertainment.cpp TextUtils.cpp -o eliza

If the program compiles successfully, an executable file named "eliza"
will be created.


Run Instructions
------------------

Run the program using:

./eliza

The program will prompt for a configuration filename. Enter:

config.txt

The program will then load the configuration, session region, and
session records, display and save the initial session region, and
start the ELIZA conversation. Enter normal sentences, common phrases,
or short answers to talk with ELIZA.

To end the conversation, type:

bye

ELIZA will display a goodbye message and the program will end.


Notes
------

All C++ source files and header files must be in the same directory
before compiling the program, along with config.txt, region.csv, and
sessions.csv. The program uses the C++11 standard because C++ regular
expressions are used for pattern matching.
