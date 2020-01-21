# Systems Final Project

**_Stephanie Liu and Christina Tan, Period 2_**

# Description of project:
Our project mimics the game 20 Questions. There are two players: an answerer and a questioner. The answerer thinks of an object from one of the following categories: Person, Place, or Thing, and the questioner has to guess the object. The questioner can ask 20 questions to figure out the object. The answerer can only reply with “Y” or “N”. If after 20 questions, the questioner has not guessed the object, the answerer wins and the answer is revealed. If the questioner does guess the object, the questioner wins.

# Reflection / Bugs
- Unfortunately, we were unable to implement all of the features we originally intended to. We were unable to get the code for the section that allows users to play again to work, although our attempts to do so have been commented out in the three files: answerer.c, questioner.c, and main.c.
- Player names sometimes print out weirdly.

# Instructions to use our program:
- Two players from different computers will choose their role (one as answerer, one as questioner).
- In order for a connection to be successful, the questioner must enter the answerer's correct IP address after the answerer has finished entering in the object and is looking for a connection. Our program is limited to two players (one answerer and one questioner).
- The questioner begins by asking a question and the answerer will answer with Y or N.
- Each player must wait and receive a question/answer before entering additional input.
- If questioner guesses correctly, the questioner wins, the game ends and the connection is closed.
- If questioner does not guess it, the answerer wins, the game ends, and the connection is closed.
