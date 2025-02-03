#include <iostream>

using namespace std;

void splitSentence(char sentence[], string words[], int& wordCount) {
    string temp = "";  // Temporary string to build each word
    int i = 0;
    wordCount = 0;  // Initialize word count
    while (sentence[i] != '\0' && wordCount < 100) {  // Iterate through the sentence, max words = 100
        if (sentence[i] != ' ') {
            temp += sentence[i];  // Add character to the current word
        } else {
            if (!temp.empty()) {  // If temp is not empty, we have a word
                words[wordCount] = temp;  // Add the word to the array
                wordCount++;
                temp = "";  // Reset temp for the next word
            }
        }
        i++;
    }
    // Handle the last word (if any)
    if (!temp.empty() && wordCount < 100) {
        words[wordCount++] = temp;  // Add the last word to the array
    }
}

int main() {
    char sentence[256];  // Character array for storing input sentence
    cout << "Enter a sentence: ";
    cin.getline(sentence, 256);  // Read the full sentence

    // Storing characters in an array format
    cout << "Characters: [";
    for (int i = 0; sentence[i] != '\0'; i++) {
        cout << "'" << sentence[i] << "'";
        if (sentence[i + 1] != '\0') cout << ", ";
    }
    cout << "]" << endl;

    string words[100];  // Array to store words (max 100 words)
    int wordCount = 0;  // To track the number of words found

    splitSentence(sentence, words, wordCount);

    // Display words in array format
    cout << "Words: [";
    for (int i = 0; i < wordCount; ++i) {
        cout << "\"" << words[i] << "\"";
        if (i < wordCount - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
