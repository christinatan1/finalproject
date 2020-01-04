# Systems Final Project

**_Stephanie Liu and Christina Tan_**

# Description of project: 
Our project mimics the game 20 Questions. There are two types of players: an answerer and questioner(s). The answerer thinks of an object from one of the following categories: Person, Place, or Thing, and the questioner has to guess the object. The questioner(s) can ask 20 questions to figure out the object. The answerer can only reply with “yes” or “no.” If after 20 questions, the questioner(s) has not guessed the object, the answerer wins. If the questioner does guess the object, the questioner(s) wins and the answer is revealed. The questioner that guesses the correct answer becomes the answerer in the next round.

# User interface:
The category is displayed after the answerer has decided on an object. Questioner(s) and answerer take turns asking questions and answering. The number of remaining questions is displayed for all players after each answer. The program also records the number of wins/losses from each player. At the end of the game, the scoreboard appears and players have the option of another round. 

# Systems concepts
- Memory Allocation

At the beginning of the game, memory will be allocated to remember the names of the players, the correct answer, and the number of the question being asked (ex: __ / 20 would be displayed). Memory will also be allocated continuously with the score count.

- Processes


- Piping


- Networking

Members from different computers can play the game, 4 players max.

- Signals

Relay an error if answerer returns an answer that is not "yes" or "no"

# General Functions:
- welcomeScreen()
- playerSelection()
- askObject()
- printScoreboard
- endScreen()

## Timeline:
<i> Jan 5: <i>
  
  Christina: Implement welcome screen and player selection.
  Stephanie: Implement answerer’s actions of choosing a category and object.
  
<i> Jan 8: <i>
  
  Christina: Implement memory allocation on the questioner's end.
  Stephanie: Implement memory allocation on the answerer's end.
  
<i> Jan 11: <i>
  
  Christina + Stephanie: Networking between the two players 
  
<i> Jan 13: <i>
  
  Christina: Implement end of game screen.
  Stephanie: Start debugging.
  
<i> Jan 15: <i>
  
  Christina + Stephanie: Debug.
  
<i> Jan 17: <i>
  
Submit final product
