/*
Created by Alex Vasilenko

No Rights Reserved

Simple text based number guessing game.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


int chooseGame();

void guessTheNumber();
void pickTheNumber();

int getValue();
bool askToPlayAgain();
int generateNumber();
int getBiggestNumber();
void congratulate(int, int);

const int MIN_NUMBER = 10;
int MAX_NUMBER = 100; //default is 100, but user can change it


int main(){
	bool quitGame = false;
    
	do{
		int choice = chooseGame();
		switch(choice){
		case 1:
			guessTheNumber();
			break;
		case 2:
			cout << "\nGame under development.\n";
			break;
		case 3:
			quitGame = true;
			break;
		default:
			cout << "This should not show up, code fails.\n";
			break;
		}
	}while(!quitGame);

    return 0;
}

//===================================================================
//Function to choose game;
//===================================================================
int chooseGame(){
	int input;

	bool goodInput = false;
	
	do
	{
		cout << "\n\nWhat Game do you want to play?\n\n";
		cout << "1) Guess the number\n";
		cout << "2) Pick the number\n";
		cout << "3) Quit\n";
		cout << ">>>";
		cin.clear();
		cin >> input;
		if(input >= 1 && input <= 3 && !cin.fail())
		{
			goodInput = true;
			return input;
		} 
		if(!(input >= 1 && input <= 3) && !cin.fail())
		{
			goodInput = false;
			cout << "\nError, invalid choice " << input;
		}
		if(cin.fail())
		{
			goodInput = false;
			char input2;
			cin.clear();
			cin >> input2;
			cout << "\nError, invalid choice " << input2;
		}
	}while(!goodInput);
}


//===================================================================
//Functions for the first game.
//===================================================================

void guessTheNumber(){
	short trys = 0;
    int randomNumber = 0;
    int userInput = 0;

    bool playAgain = false;
    bool quit = false;

    srand(time(0));

    cout << "Number guessing game!\n";

    do{
        MAX_NUMBER = getBiggestNumber();
        randomNumber = generateNumber();
        bool gotRight = false;
        while(!gotRight){
            userInput = getValue();
            if(userInput == randomNumber){
                trys++;
                gotRight = true;
            }else if(userInput > randomNumber){
                trys++;
                cout << "Too high!\n";
            }else if(userInput < randomNumber && userInput > 0){
                trys++;
                cout << "Too low!\n";
            }
            if(userInput == -1){
                quit = true;
                gotRight = true;
            }
        }
        if(!quit){
            congratulate(trys, randomNumber);
        }

        trys = 0;

        playAgain = askToPlayAgain();
    }while(playAgain);
}


int getBiggestNumber(){
    bool goodInput = false;

    int max = 0;
    char input2;

    while(!goodInput){
        cout << "What should the biggest number be? ('D' for 100)\n>>>";
        cin >> setw(8) >> max;
        if(max >= MIN_NUMBER){
            goodInput = true;
        }else if(max < MIN_NUMBER && !cin.fail()){
            cout << "Error: number must be greater than or equal to " << MIN_NUMBER << ".\n";
        }else if(max > 1000000){
            cout << "Error: number must be less than or equal to 1,000,000.\n";
        }
        if(cin.fail()){
            cin.clear();
            cin >> input2;
            if(input2 == 'd' || input2 == 'D'){
                max = 100;
                goodInput = true;
            }else{
                cout << "Error: ( " << input2 << " ) is not a number or 'D'.\n";
            }
        }
    }
    return max;
}

int getValue(){
    bool goodInput = false;

    int input = 0;
    char input2;

    while(!goodInput){
        cout << "Enter a number 1 - " << MAX_NUMBER << " (Q to give up)\n>>>";
        cin >> setw(8) >> input;
        if(input >= 1 && input <= MAX_NUMBER && !cin.fail()){
            goodInput = true;
        }
        if((input < 1 || input > MAX_NUMBER) && !cin.fail()){
            cout << "Error: value must be 1 - " << MAX_NUMBER << ".\n";
        }
        if(cin.fail()){
            cin.clear();
            cin >> input2;
            if(input2 == 'q' || input2 == 'Q'){
                return -1;
            }
            cout << "Error: ( " << input2 << " ) is not a number.\n";
        }
    }
    return input;
}

bool askToPlayAgain(){
    char input;
    bool goodInput = false;
    while(!goodInput){
        cout << "Do you want to play again? (Y / N)\n>>>";
        cin >> input;
        if(input == 'y' || input == 'Y'){
            goodInput = true;
            return true;
        }else if(input == 'n' || input == 'N'){
            goodInput = true;
            return false;
        }else{
            cout << "Error, not ( Y ) or ( N )\n";
        }
    }
}

/*Returns a randomly generated number.
Can be edited to support arguments.*/
int generateNumber(){
    int min = 1;
    int max = MAX_NUMBER;
    int random = -1;

    random = rand() % (max - min) + min;

    if(random >= min && random <= max){
        return random;
    }
}

void congratulate(int trys, int randomNumber){
    if(trys == 1){
        cout << "Perfect!\n";
        cout << "You guessed " << randomNumber << " on the first try!\n";
    }else if(trys > 1 && trys <= 15){
        cout << "Good Job!\n";
        cout << "It took you " << trys << " trys to find " << randomNumber << "!\n";
    }else{
		cout << "That took a while.\n";
        cout << "It took you " << trys << " trys to find " << randomNumber << "!\n";
	}
}

//===================================================================
//Functions for the second game.
//===================================================================

void pickTheNumber(){
	bool playAgain;
	do
	{
		
	}while(playAgain);
}





