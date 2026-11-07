# Challenge 2 – Random Joke Generator

## About the Program

This C++ program works like a simple Alexa joke generator. The user types "Alexa, tell me a joke" and the program selects a random joke from a text file called `randomJokes.txt`. It displays the question first and waits for the user to press Enter before showing the punchline.

## What I Used

I used vectors, loops, if statements and file handling. I also used `ifstream` to read the jokes from the text file, `rand()` to select a random joke and `getline()` to read the user's input.

## Testing

I tested the program by requesting different jokes, entering incorrect commands and using the quit option. I also checked what happens when the jokes file is missing.

## How to Run

Open `challenge2_jokes.cpp` in VS Code and compile it using a C++ compiler. Make sure `randomJokes.txt` is in the same folder before running the program in the terminal.
