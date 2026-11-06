
#include <iostream>  // For input and output
#include <fstream>   // For reading the jokes file
#include <string>    // For text variables
#include <vector>    // For storing multiple jokes
#include <cstdlib>   // For random numbers
#include <ctime>     // For the random seed

using namespace std;

int main() {
    // Open the jokes file
    ifstream inputFile("randomJokes.txt");

    // Check if the file opened
    if (!inputFile.is_open()) {
        cout << "Error: Cannot open randomJokes.txt" << endl;
        return 1;
    }

    // Store the jokes
    vector<string> jokes;
    string line;

    // Read each joke from the file
    while (getline(inputFile, line)) {
        if (!line.empty()) {
            jokes.push_back(line);
        }
    }

    inputFile.close();

    // Check if jokes were loaded
    if (jokes.empty()) {
        cout << "No jokes found in the file." << endl;
        return 1;
    }

    // Set up random selection
    srand(time(0));

    // Welcome message
    cout << "=== Alexa Joke Generator ===" << endl;
    cout << "Type 'Alexa, tell me a joke' or 'quit' to exit." << endl;

    string command;

    // Keep asking for commands
    while (true) {
        cout << "\nEnter command: ";
        if (!getline(cin, command)) {
            break;
        }

        // Exit the program
        if (command == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }

        // Check if the user requested a joke
        if (command == "Alexa, tell me a joke") {
            // Select a random joke
            int randomIndex = rand() % jokes.size();
            string joke = jokes[randomIndex];

            // Find the question mark
            size_t position = joke.find('?');

            if (position != string::npos) {
                // Separate setup and punchline
                string setup = joke.substr(0, position + 1);
                string punchline = joke.substr(position + 1);

                // Display the setup
                cout << setup << endl;

                // Wait before showing punchline
                cout << "Press Enter for the punchline...";
                string response;
                if (!getline(cin, response)) {
                    break;
                }

                // Display the punchline
                cout << punchline << endl;
            }
            else {
                cout << "Invalid joke format." << endl;
            }
        }
        else {
            cout << "Unknown command. Please try again." << endl;
        }
    }

    return 0;
}

