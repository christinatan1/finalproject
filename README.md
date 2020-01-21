# Systems Final Project

**_Stephanie Liu and Christina Tan, Period 2_**

# Description of project:
Our project mimics the game 20 Questions. There are two types of players: an answerer and questioner(s). The answerer thinks of an object from one of the following categories: Person, Place, or Thing, and the questioner has to guess the object. The questioner(s) can ask 20 questions to figure out the object. The answerer can only reply with “yes” or “no.” If after 20 questions, the questioner(s) has not guessed the object, the answerer wins. If the questioner does guess the object, the questioner(s) wins and the answer is revealed. The questioner that guesses the correct answer becomes the answerer in the next round.

# Reflection / Bugs
Unfortunately, we were unable to implement all of the features we originally intended to. We were unable to get the code for the section that allows users to play again to work, although our attempts to do so have been commented out in the three files: answerer.c, questioner.c, and main.c. Additionally, although the random question feature works, we were unable to track the questions that have already been asked and prevent repeated questions.

# User interface:
- Welcome screen for name input and player selection.
- The player who is the answerer will be asked to choose a category and decide on an object.
- The category is displayed after the answerer has decided on an object. Questioner(s) and answerer take turns asking questions and answering. If the questioner does not come up with a question in time, a random question will be asked.
- The number of remaining questions is displayed for all players after each answer.
- At the end, players have the option to play another round.

# Instructions to use our program:
- Two players from different computers will choose their role (one as answerer, one as questioner).
- In order for a connection to be successful, the questioner must enter the other answerer's correct IP address when the answerer has finished entering in the object and is looking for a connection. 
- The questioner will start to ask questions and answerer will answer with Y or N.
- If questioner guesses correctly, the questioner wins, the game ends and the connection is closed.
- If questioner does not guess it, the answerer wins, the game ends, and the connection is closed.
