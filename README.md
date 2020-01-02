# Systems Final Project

**_Stephanie Liu and Christina Tan_**

# Description of project: 
Our project mimics the game 20 Questions. There are two types of players: an answerer and questioner(s). The answerer thinks of an object from one of the following categories: Person, Place, or Thing, and the questioner has to guess the object. The questioner(s) can ask 20 questions to figure out the object. The answerer can only reply with “yes” or “no.” If after 20 questions, the questioner(s) has not guessed the object, the answerer wins. If the questioner does guess the object, the questioner(s) wins and the answer is revealed.

# User interface:
The category is displayed after the answerer has decided on an object. Questioner(s) and answerer take turns asking questions and answering. The number of remaining questions is displayed for all players after each answer. The program also records the number of wins/losses from each player. At the end of the game, the scoreboard appears and players have the option of another round. 

# Systems concepts
- Memory Allocation: 
  At the beginning of the game, memory will be allocated to remember the names of the players and the correct answer. Memory will also be allocated continuously with the score count.
- Processes
- Piping
- Shared Memory/Semaphores
- Networking

# General Functions:
- welcomeScreen()
- playerSelection()
- askObject()
- printScoreboard
- endScreen()

## Timeline:
_Jan 5 -_
  Christina: Implement welcome screen and player selection.
  Stephanie: Implement answerer’s actions of choosing a category and object.
_Jan 8 -_
  Christina: Implement memory allocation on the questioner's end.
  Stephanie: Implement memory allocation on the answerer's end.
_Jan 11 -_
  Christina + Stephanie: Networking between the two players 
_Jan 13 -_
  Christina: Implement end of game screen.
  Stephanie: Start debugging.
_Jan 15 -_
  Christina + Stephanie: Debug.
_Jan 17 -_
Submit final product
