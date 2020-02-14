 /* Personal Project 1, Summer 2019
 * Contributor: Timothy White, II
 * Date: 06/ 11/ 2019 
 */ 

#include <iostream>
#include <fstream>
#include <sstream>
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
const string HIGH_SCORE_LIST = "highscores.dat";

//Struct for user's info
struct User_info
{
    string name;
    int trophies;
    int game_score;
};

//Struct for characters user can choose


//Function prototypes
char to_lowercase(char curr);
void read_command(string cmmnd);
void read_file(string cmmnd);
void play_game();
struct User_info *check_username(string user_name);

int main(){
	string cmmnd;
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
};

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
	if (cmmnd == QUIT){
		return;
	}
	else if (cmmnd == READ_GUIDE){
		read_file(cmmnd);
		cout << " Enter a command (rg, play, hs, q) ";
		cin >> cmmnd;
		read_command(cmmnd);
	}
	else if (cmmnd == HIGH_SCORE){
		read_file(cmmnd);
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

/* Name: read_file
 * Purpose: Opens the file for the user to read
 * Return: none
 * Paramater: string(s)
 */
void read_file(string cmmnd){
//Read the neccessary file
	ifstream in;
	string file_to_open, line;
	if (cmmnd == READ_GUIDE){
		file_to_open = "README";
	} else if (cmmnd == HIGH_SCORE) {
		file_to_open = "highscores.txt";
	} else {
		cout << "command not valid";
	}
	in.open(file_to_open);
	if (not in.is_open()){
		cout << "File can't be opened. ";
		return;
    	}
	while(!in.eof()){
		getline(in, line);
		cout << line << endl;
	}
	cout << "" << endl;
	in.close();
	return;
}
/* Name: play_game
 * Purpose: Runs through the sequence neccessary to play the game
 * Return: None
 * Paramater: None
 */
void play_game(){
	//Check and see if user has trophies
	User_info curr_user;
	string user_name;
	cout << "Enter your name " << endl;
	cin >> user_name;
	if (user_name == ""){
		cout << "You didn't enter a name silly! I'm gonna leave now..."
		<< " Goodbye :-)" << endl;
	}
	curr_user = *check_username(user_name);
	// if (curr_user == nullptr)
}
/* Name: check_username
 * Purpose: Get's user's information
 * Return: Struct with user's information
 * Paramater: 
 */
struct User_info *check_username(string user_name){
	User_info *curr_user = new User_info; 
	ifstream in;
	string line, info;
	in.open("highscores.txt");
	if (not in.is_open()){
		cout << "File can't be opened. ";
	}
	// Check the username list to find if the user already exists
	while (!in.eof()){
		getline(in, line);
		stringstream ss(line);
		ss >> info;
		if(user_name == info){
			curr_user->name = info;
			ss >> curr_user->game_score;
			ss >> curr_user->trophies;
			//Test to make sure struct is right
			cout << curr_user->name << endl;
			cout << curr_user->game_score << endl;
			cout << curr_user->trophies << endl;
			// high score list is still open
			User_info *temp = curr_user;
			delete curr_user;
			return temp;
		}
	}
	delete curr_user;
	curr_user = nullptr;
	return curr_user;
}
/* Name: check_char_available
 * Purpose: Get the name of the characters that the user can choose from
 * Return: string array with names of characters
 * Paramater: 
 */
// string check_char_available(int trophies){
// 	string chars_avail[];
// 	if (trophies = 0){

// 	} else if (trophies == 1){

// 	} else if (trophies == 2){

// 	} else if (trophies == 3){

// 	} else if (trophies == 4){

// 	} else if (trophies == 5 ){

// 	} else {
// 		cout << "invalid number of trophies";
// 	}
// }


