# Systems Final Project

**_Stephanie Liu and Christina Tan_**

# Description of project:
Our project mimics the game 20 Questions. There are two types of players: an answerer and questioner(s). The answerer thinks of an object from one of the following categories: Person, Place, or Thing, and the questioner has to guess the object. The questioner(s) can ask 20 questions to figure out the object. The answerer can only reply with “yes” or “no.” If after 20 questions, the questioner(s) has not guessed the object, the answerer wins. If the questioner does guess the object, the questioner(s) wins and the answer is revealed. The questioner that guesses the correct answer becomes the answerer in the next round.

# User interface:
- Welcome screen for name input and player selection.
- The player who is the answerer will be asked to choose a category and decide on an object.
- The category is displayed after the answerer has decided on an object. Questioner(s) and answerer take turns asking questions and answering. If the questioner does not come up with a question in time, a random question will be asked.
- The number of remaining questions is displayed for all players after each answer.
- At the end, the scoreboard appears and players have the option of another round.

# Systems concepts
- Memory Allocation: Memory will be allocated to store player names, the correct answer, the number of the question asked, score count, and time.

- File handling: If the questioner does not come up with a question in time, a random question will be asked from a file of questions specific to the category.

- Signals: An error will be relayed if the answerer returns an answer that is not "yes" or "no".

- Networking: Members from different computers can play the game, 4 players max.

# General Functions:
- welcomeScreen()
- playerSelection()
- askQuestion()
- answerQuestion()
- printScoreboard()
- endScreen()

## Timeline:
<i> Jan 5: <i>

  Christina: Implement welcome screen and player selection.
  Stephanie: Implement answerer’s actions of choosing a category and object.

<i> Jan 8: <i>

  Christina: Implement receiving input and allocating memory on the questioner's end and answerer's end.
  Stephanie: Implement getting a random question from file if questioner runs out of time to ask a question.

<i> Jan 11: <i>

  Christina: Finish implementing allocation of memory on questioner's end and answerer's end.
  Stephanie: Networking between the two players.

<i> Jan 13: <i>

  Christina: Implement end of game screen.
  Stephanie: Start debugging.

<i> Jan 15: <i>

  Christina + Stephanie: Debug.

<i> Jan 17: <i>

  Submit final product.
