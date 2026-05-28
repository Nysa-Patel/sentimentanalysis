#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//declare functions
string convertToLower(string textinput);
string analyze(string sentence);

vector<string> positive = {
    "good", "great", "love", "fun", "happy", "awesome"
};
vector<string> negative = {
    "bad", "terrible", "sad", "hate", "terrible"
};

int main()
{
    string answer = "y";
    while (answer == "y"){ //uses loop to allow users to enter multiple sentiments
        string sentence;
        cout<< "Enter a sentence: ";
        getline(cin, sentence);
        
        cout << analyze(sentence) << endl;
        cout << endl;
        
        cout << "Do you want to enter another sentence? y or n : ";
        cin >> answer;
        cin.ignore(); //ignores the previous sentence inputted
    }
}

string convertToLower(string textinput){
    for (char &c : textinput) //loops through each char and directly modifies
    {
        c = tolower(c); //lowercase v in string
    }
    return textinput;
}

string analyze(string sentence){
    //counters for negative and positive words
    int posCount = 0;
    int negCount = 0;
    sentence = convertToLower(sentence); //function to convert all into lowercase
    
    stringstream ss(sentence); //seperates sentecne into words
    string word;

    while (ss >> word) //each word at a time
    {
        for(string posWord : positive) {
            if (word == posWord) {
                posCount++;
            }
        }
        for(string negWord : negative) {
            if (word == negWord) {
                negCount++;
            }
        }
    }
    
    //compares counts
    if (posCount > negCount) { 
        cout << "Positive sentiments: " << posCount << endl;
        cout << "Negative sentiments: " << negCount <<endl;
        return "Sentiment is positive";
    }
    else if (negCount > posCount) {
        cout << "Positive sentiments: " << posCount << endl;
        cout << "Negative sentiments: " << negCount <<endl;
        return "Sentiment is negative";
    }
    else {
        cout << "Positive sentiments: " << posCount << endl;
        cout << "Negative sentiments: " << negCount <<endl;
        return "Sentiment is neutral";
    }
}
