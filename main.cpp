 /* Personal Project 1, Summer 2019
 * Contributor: Timothy White, II
 * Date: 06/ 11/ 2019 
 */ 

#include <iostream>
#include <fstream>
#include <ssstream>
using namespace std;

//Constants
const string QUIT = "q";
const string NOVICE = "nov";
const string ADVANCED = "adv";
const string PRO = "pro";
const string HINT = "hint";
const string READ_GUIDE = "rg";
const string PLAY_NOW = "play";
const string HIGH_SCORE = "hs";

//Struct for user's info
struct user_info
{
    string name;
    int trophies;
    int game_score;
};

//Function prototypes
char to_lowercase(char curr);
void read_command(string cmmnd);
int read_file(string cmmnd, string user_name);
void play_game();
void check_username();

int main (){
	string cmmnd, user_name = "";
	//Get Command
	cout << " Enter a command (rg, play, hs, q) ";
	cin >> cmmnd;
	for (char &curr : cmmnd){
    curr = to_lowercase(curr);
    }
    if (cmmnd == QUIT){
    	return 0;
    } else {
    	read_command(cmmnd);
    }
}

/* Name: to_lowercase
 * Purpose: Ensures user's input is all lowercased
 * Return: Lowercased characters
 * Paramater: char
 */
char to_lowercase(char curr){
    if (curr >= 'A' and curr <= 'Z'){
        return curr + 32;
    }
    return curr;
}

/* Name: read_command
 * Purpose: Reads user command and proceeds accordingly
 * Return: None
 * Paramater: string
 */
void read_command(string cmmnd){
	string user_name = "";
	if (cmmnd == QUIT){
		return;
	}
	else if (cmmnd == READ_GUIDE){
		read_file(cmmnd, user_name);
		cout << " Enter a command (rg, play, hs, q) ";
		cin >> cmmnd;
		read_command(cmmnd);
	}
	else if (cmmnd == HIGH_SCORE){
		read_file(cmmnd, user_name);
		cout << " Enter a command (rg, play, hs, q) ";
		cin >> cmmnd;
		read_command(cmmnd);
	}
	else if (cmmnd == PLAY_NOW){
		play_game();
		return;
	} else {
		cout << "Command is invalid, please try again. " << endl;
		cin >> cmmnd;
		read_command(cmmnd);
	}
}

/* Name: open_guide
 * Purpose: Opens the file for the user to read
 * Return: 0 if file is not able to be opened, 1 if list is printed, 
 		   2 if username is in list, 3 if username is not in list
 * Paramater: string(s)
 */
int read_file(string cmmnd, string user_name){
//Read the neccessary file
	ifstream in;
	int file_length;
	string file_to_open, line; 
	user_name = "";
	if (cmmnd == READ_GUIDE){
		file_to_open = "hangman.readme";
	} else if (cmmnd == HIGH_SCORE) {
		file_to_open = "highscores.dat";
	} else {
		cout << "command not valid";
	}
		in.open(file_to_open);
		in >> file_length;
		if (not in.is_open()){
       		cout << "File can't be opened. ";
       		return 0;
    	}
    /* NOTE: Seperate into print list and check list funcs
    */
    	//Sequence to follow if printing list
    	if (user_name == ""){
			for(int i=0; i < file_length; i++){
				getline(in, line);
				cout << line << endl;
			}
			cout << "" << endl;
			in.close();
			return 1;
		//Sequence to follow if checking list for username	
		} else {
			for(int i=0; i < file_length; i++){
				getline(in, line);
				if (line == user_name){
					return 2;
				}
			}
			return 3;
			in.close();
		}
}
/* Name: play_game
 * Purpose: Runs through the sequence neccessary to play the game
 * Return: None
 * Paramater: None
 */
void play_game(){
	//Check and see if user has trophies
	string user_name;
	int name_in_list;
	cout << "Enter your name " << endl;
	cin >> user_name;
	name_in_list = read_file(HIGH_SCORE, user_name);
	if ((name_in_list == 0) or (name_in_list == 1)){
		return;
	} else if (name_in_list == 2) {
		check_username(user_name)
	}
}
/* Name: check_username
 * Purpose: Get's user's information
 * Return: Struct with user's information
 * Paramater: 
 */
struct check_username(string user_name){
	stringstream ss()
	WORKING ON THIS!!
}
