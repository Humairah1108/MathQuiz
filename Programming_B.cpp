// Name: 
//ID: 
//BSc(hons) Computer Science Year 1 Group A2

#define _CRT_SECURE_NO_WARNINGS 
//using crt_secure_no_warnings to be able to generate the current time and date 
//VS studio does not allow the use of localtime and ctime without defining _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<time.h>
#include<iomanip>
#include<sstream>
using namespace std;
//--------------------------------------------------------------MATHS LEARNING TOOL FOR GRADE V------------------------------------
class QA {
	string question, ans, displayAnswer;
	int mark1, mark2, mark3, mark4;
public:
	//constructors
	QA();
	QA(string q, string aa, string disp_ans, int m1, int m2, int m3, int m4);
	string getquestion();
	void setquestion(string q);

	string getans();
	void setans(string aa);
	string getDisp_Ans();
	void setDisp_Ans(string da);

	int getmark1();
	void setmark1(int m1);
	int getmark2();
	void setmark2(int m2);
	int getmark3();
	void setmark3(int m3);
	int getmark4();
	void setmark4(int m4);

	string removeuppercases(string str);
	string removeSpaces(string str);
	void srand(int seed);
	void menu1();
	~QA();
};
QA::QA() {
	question = "";
	ans = "";
	displayAnswer = "";
	mark1 = 0;
	mark2 = 0;
	mark3 = 0;
	mark4 = 0;
}
QA::QA(string q, string aa, string da, int m1, int m2, int m3, int m4) {
	question = q;
	ans = aa;

	displayAnswer = da;
	mark1 = m1;
	mark2 = m2;
	mark3 = m3;
	mark4 = 0;
}
string QA::getquestion() {
	return question;
}
void QA::setquestion(string q) {
	question = q;
}
string QA::getans() {
	return ans;
}
void QA::setans(string aa) {
	ans = aa;
}
string QA::getDisp_Ans() {
	return displayAnswer;
}
void QA::setDisp_Ans(string da) {
	displayAnswer = da;
}
int QA::getmark1() {
	return mark1;
}
void QA::setmark1(int m1) {
	mark1 = m1;
}
int QA::getmark2() {
	return mark2;
}
void QA::setmark2(int m2) {
	mark2 = m2;
}
int QA::getmark3() {
	return mark3;
}
void QA::setmark3(int m3) {
	mark3 = m3;
}
int QA::getmark4() {
	return mark4;
}
void QA::setmark4(int m4) {
	mark4 = m4;
}

//method to display menu
void QA::menu1() {
	//generating the current date and time
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "date and time is " << dt << endl;
	cout << "Welcome to the Math learning tool for grade V" << endl;
	cout << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*         1: Numbers One                          *" << endl;
	cout << "*         2: Numbers Two                          *" << endl;
	cout << "*         3: Measure                              *" << endl;
	cout << "*         4: Exam-Styled                          *" << endl;
	cout << "*         5: Display Profile                      *" << endl;
	cout << "*         6: Exit Program                         *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}
//method to removed upper cases from a string
string QA::removeuppercases(string str) {
	string word = "";
	for (auto x : str) {

		if (isupper(x)) {
			x = x + 32;
		}
		word = word + x;
	}
	return word;
}
//method to remove spaces from a string
string QA::removeSpaces(string str) {
	std::string str_no_ws;
	for (char c : str) if (!std::isspace(c)) str_no_ws += c;
	return str_no_ws;
}
//random method
void QA::srand(int seed) {

}

//Destructor for parent class QA
QA::~QA() {}
//_____________________________________________________________________________________________________________________________________
//class to store information about the user, keeping track of the user's progress
class Profile {
	string name, wrong_ques;
	int age;
public:
	//constructors
	Profile();
	Profile(string n, int ag, string wq);

	string getname();
	void setname(string n);
	int getage();
	void setage(int ag);
	string getwrong_ques();
	void setwrong_ques(string wq);

	//desctructor
	~Profile();
};
//contructor
Profile::Profile() {
	name = "";
	age = 0;
	wrong_ques = "";
}
Profile::Profile(string n, int ag, string wq) {
	name = n;
	age = ag;
	wrong_ques = wq;
}
string Profile::getname() {
	return name;
}
void Profile::setname(string n) {
	name = n;
}
int Profile::getage() {
	return age;
}
void Profile::setage(int ag) {
	age = ag;
}
string Profile::getwrong_ques() {
	return wrong_ques;
}
void Profile::setwrong_ques(string wq) {
	wrong_ques = wq;
}
//Destructor for Class Profile
Profile::~Profile() {}
//_____________________________________________________________________________________________________________________________________

//main program
int main() {
	srand((unsigned)time(0));
	//changes background and font colour
	system("Color 70");

	//creates variable choice to store the choice of user after the menu is displayed
	int choice, age;
	string name;
	Profile User_Info;

	cout << "Enter your name: ";
	getline(cin, name);
	User_Info.setname(name);
	cout << endl;
	bool valid = false;
	
	do {
		valid = false;
		cout << "Enter your age: ";
		while (!(cin >> age)) {
			cout << endl;
			cout << "ERROR: You must enter an integer! ";
			// Clear input stream
			cin.clear();
			// Discard previous input
			cin.ignore(123, '\n');
			//leaves a line
			cout << endl;
			//prompts the user to input again
			cout << "Enter your age: ";
		}
		if ((age > 4) || (age < 100)) {
			valid = true;
			User_Info.setage(age);

			//Greets the user
			cout << endl;
			cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
			cout << "*       Welcome to the Math Learning Platform,        *" << endl;
			cout << "*" << setw(29) << User_Info.getname() << setw(25) << "*" << endl;
			cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * " << endl;
			cout << endl;

			cout << "Press Enter to start..." << endl;
			cin.get();
			cin.get();

			cout << endl;
			//Displays a menu for the user to choose his/her level of choice
			QA menu;
			menu.menu1();
			cout << endl;

			//Prompts the user to enter a  choice
			cout << "Enter your choice: ";
			// allows input to variable choice

			while (!(cin >> choice))
			{
				cout << endl;
				cout << "ERROR: You must enter an integer!! ";
				// Clear input stream
				cin.clear();
				// Discard previous input
				cin.ignore(123, '\n');
				//leaves a line
				cout << endl;
				//prompts the user to input again
				cout << "Enter your choice: ";
			}
			
			//creates an array of objects ques,ques2,ques3,ques4 based on the class QA
			QA ques[25];
			QA ques2[10];
			QA ques3[25];
			QA ques4[30];
			Profile userinfo[10];
			Profile userinfo2[10];
			Profile userinfo3[10];
			Profile userinfo4[15];
			//while choice is not equal to 5, go in loop
			while (choice != 6) {
				//generating the current date and time
				time_t now = time(0);
				char* dt = ctime(&now);
				cout << "date and time is " << dt << endl;


				string str = dt;
				int wcount = 0;
				string datetime[5];
				istringstream ss(str);
				// Traverse through all words 
				while (ss.good() && wcount < 5) {
					//store each 'word' in the array date time at the postion (wcount)
					ss >> datetime[wcount];
					//we increment the count 
					wcount++;
				}

				//store each word in at each position in the variables day, month, dd, time, yy respectively
				string day = datetime[0];
				string mm = datetime[1];
				string dd = datetime[2];
				string time = datetime[3];
				string yy = datetime[4];

				string t = "";
				//array hhmmsec stores the hours,minutes,seconds at positions 0,1,2 respectively
				string hhmmsec[3];
				//counter which increments if an hour,min or sec is found after a punctuation
				int tcount = 0;
				for (auto x : time)
				{
					//checks if the current character is a punctuation
					if (ispunct(x))
					{
						//cout << t << endl;
						hhmmsec[tcount] = t;//if the character is a punctuation, then it goes in the array at position (tcount value)
						tcount++;
						t = ""; //clears the variable t so that it can store the next values
					}
					else
					{
						//else we continue to add up the characters if we have not found a punctuation
						t = t + x;
					}
				}
				//cout << t << endl;
				//assigns the value to the array at the position (tcount value)
				hhmmsec[tcount] = t;
				string hour = hhmmsec[0];
				string min = hhmmsec[1];
				string sec = hhmmsec[2];

				string timestamped_file = dd + "_" + mm + "_" + yy + "_" + hour + "_" + min + "_" + sec + ".txt";

				if (choice == 1) {
					//open text file Q_L1 which contains level 1 questions (easy questions)
					ifstream n1("Numbers.txt");

					if (!n1.is_open())
						cout << "Error opening file Numbers.txt!" << endl;
				
					string line_1;
					//while not end of file Q_L1.txt
					while (!n1.eof()) {
						for (int i = 0; i < 25; i++) {
							getline(n1, line_1);
							ques[i].setquestion(line_1);
						}
					}
					n1.close(); // closes text file Q_L1

					ifstream n2("Numbers_Answer.txt"); //opens text file A_L1 which contains corresponding answers for the questions from text file Q_L1
					string  line_2; //variable to store one line from the text file

					for (int i = 0; i < 25; i++) {
						//write line[i] to line_2
						getline(n2, line_2);
						ques[i].setDisp_Ans(line_2);
						string word = ques[i].removeuppercases(line_2);

						//sets the i th answer in the class
						ques[i].setans(ques[i].removeSpaces(word));

					}

					n2.close(); // closes text file A_L1

					cout << endl;
					string answer;
					int mark1 = 0;
					//---------------------------------
					int r;
					int rn[10];
					int count = 0;
					for (int i = 0; i < 10; i++) {
						rn[i] = 0;
					}
					//count till 10
					while (count < 10) {
						//generates a  random number between 0 and 20, and assigns it to variable r
						r = rand() % 25;
						//boolean variable to check if existing random number is found
						bool found = false;
						for (int i = 0; i < 10; i++) {
							//if the random number generated already exist in the array rn, then  generate another random number
							//this is to ensure that the array only contains distinct/different random numbers
							if (rn[i] == r) {
								found = true;
								break;
							}
						}
						//if the random number is not found in the array, then add it to the array
						if (!found) {
							rn[count] = r;
							count++; // increment count by one
						}
					}
					//-----------------------------------------------------
					string wrqu1[10];

					for (int i = 0; i < 10; i++) {
						wrqu1[i] = "emp";
					}
					cin.ignore();
					for (int i = 0; i < 10; i++) {

						cout << endl; //leaves a line
						//Displays the question
						cout << i + 1 << ". " << ques[rn[i]].getquestion() << endl;
						//prompts the user to input an answer
						cout << "Answer: ";
						getline(cin, answer);//Allows the user to input his/her answer to the question

						string a1, a2;
						a1 = ques[i].removeSpaces(answer);
						a2 = ques[i].removeuppercases(a1);
						//Checks if the user input matches the corresponding answer for the question
						if (a2 != ques[rn[i]].getans()) {
							//displays the correct answer
							cout << "Wrong! The correct answer is " << ques[rn[i]].getDisp_Ans() << "." << endl;
							//stores the question that the user has wrongly attempted
							wrqu1[i] = ques[rn[i]].getquestion();
							//counts the number of wrong answers

						}
						else {
							//if user got the correct answer, displays Correct! on the screen and his/her mark is incremented
							cout << "Correct!" << endl;
							//marks increment if correct answer given
							mark1++;
							//sets the mark
							ques[i].setmark1(1);
						}
					}

					for (int i = 0; i < 10; i++) {
						userinfo[i].setwrong_ques(wrqu1[i]);
					}
					cout << endl;// leaves a line
					//Displays the total marks obtained by the user after working out the questions
					cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
					cout << "*           Total marks obtained: " << mark1 << "/10                  *" << endl;
					//Displays the kind of performance that the user has done
					if (mark1 <= 5) {

						cout << "*               Poor Performance!                       *" << endl;
						cout << "*      Don't give up and practice more questions! ^-^   *" << endl;
						cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
					}
					else {
						if ((mark1 > 5) && (mark1 < 10)) {

							cout << "*               Good Performance!                       *" << endl;
							cout << "*                 Keep it up! :D                        *" << endl;
							cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
						}
						else {
							cout << "*          Excellent Performance!                       *" << endl;
							cout << "*             Keep it up! :O                            *" << endl;
							cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;

						}
					}
				}
				else {
					if (choice == 2) {
						ifstream n3("Numbers2_Ques.txt");
						if (!n3.is_open()) {
							cout << "Error opening file Numbers2_Ques.txt!" << endl;
						}
						else {
							//cout << "File Numbers2_Ques.txt opened successfully!" << endl;
						}

						string line_3;
						while (!n3.eof()) {
							for (int i = 0; i < 10; i++) {
								getline(n3, line_3);
								ques2[i].setquestion(line_3);
							}
						}

						//closes file Numbers_Ques.txt
						n3.close();

						ifstream n4("Numbers2_Ans.txt");
						if (!n4.is_open()) {
							cout << "Error opening file A_L2.txt!" << endl;
						}
						else {
							//cout << "File Numbers2_Ans.txt opened successfully!" << endl;
						}
						//variable line_4 to store content of a line
						string line_4;

						for (int i = 0; i < 10; i++) {
							//reads the number on a specific line and stores it in variable line_4
							getline(n4, line_4);
							//sets the i th answer to the class
							ques2[i].setDisp_Ans(line_4);

							//removes spaces and punctuation from answers

							string word = ques2[i].removeuppercases(line_4);

							//sets the i th answer in the class
							ques2[i].setans(ques2[i].removeSpaces(word));
						}

						//closes file Numbers2_Ans.txt
						n4.close();
					
						//--------------------------------------------
						cout << endl;
						int r2;
						int rn2[5];
						for (int i = 0; i < 5; i++) {
							rn2[i] = 0;
						}
						int count = 0;
						//count till 5
						while (count < 5) {
							//generates a  random number between 0 and 20, and assigns it to variable r
							r2 = rand() % 10;
							//boolean variable to check if existing random number is found
							bool found = false;
							for (int i = 0; i < 5; i++) {
								//if the random number generated already exist in the array rn, then  generate another random number
								//this is to ensure that the array only contains distinct/different random numbers
								if (rn2[i] == r2) {
									found = true;
									break;
								}
							}
							//if the random number is not found in the array, then add it to the array
							if (!found) {
								rn2[count] = r2;
								count++; // increment count by one
							}
						}
						string answer2;
						//variable mark2 to store the total marks that the user has obtained after working out the questions
						int mark2 = 0;
						//displays 5 questions for the user to work out

						string wrqu2[5];
						for (int i = 0; i < 5; i++) {
							wrqu2[i] = "emp";
						}
						cin.ignore();
						for (int i = 0; i < 5; i++) {
							cout << endl;
							//gets the question from class and displays it
							cout << ques2[rn2[i]].getquestion() << endl;
							cout << "Answer: ";
							//allows user to input his/her answer
							getline(cin, answer2);
							string b1, b2;
							b1 = ques2[i].removeSpaces(answer2);
							b2 = ques2[i].removeuppercases(b1);
							//checks if the user has entered the correct answer
							if (b2 != ques2[rn2[i]].getans()) {

								cout << "Wrong! The correct answer is " << ques2[rn2[i]].getDisp_Ans() << "." << endl;
								wrqu2[i] = ques2[rn2[i]].getquestion();

							}
							else {
								//if user got the correct answer, displays Correct! on the screen and his/her mark is incremented
								cout << "Correct!" << endl;
								mark2++;
								ques2[i].setmark2(1);
							}
						}
						for (int i = 0; i < 5; i++) {
							userinfo2[i].setwrong_ques(wrqu2[i]);
						}

						cout << endl;// leaves a line
						//Displays the total marks obtained by the user after working out the questions
						cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
						cout << "*           Total marks obtained: " << mark2 << "/5                   *" << endl;
						//Displays the kind of performance that the user has done
						if (mark2 <= 10) {
							//Displays this if the user has failed
							cout << "*               Poor Performance!                       *" << endl;
							cout << "*      Don't give up and practice more questions! ^-^   *" << endl;
							cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
						}
						else {
							if ((mark2 > 10) || (mark2 < 20)) {
								//Displays this if the user has not got full marks but still did a good job
								cout << "*               Good Performance!                       *" << endl;
								cout << "*                 Keep it up! :D                        *" << endl;
								cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
							}
							else {
								//Displays this if the user has got full marks
								cout << "*          Excellent Performance!                       *" << endl;
								cout << "*             Keep it up! :O                            *" << endl;
								cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
								cout << "__________________________________________________________________________________________________________________________________________" << endl;
							}
						}

					}
					else {
						if (choice == 3) {
							ifstream n5("Measure_Ques.txt");
							if (!n5.is_open()) {
								cout << "Error opening file Measure_Ques.txt!" << endl;
							}
							else {
								//cout << "File Measure_Ques.txt opened successfully!" << endl;
							}
							string line_5;
							while (!n5.eof()) {
								for (int i = 0; i < 25; i++) {
									getline(n5, line_5);
									ques3[i].setquestion(line_5);
								}
							}
	
							//closes file Numbers_Ques.txt
							n5.close();

							ifstream n6("Measure_Ans.txt");
							if (!n6.is_open()) {
								cout << "Error opening file Measure.txt!" << endl;
							}
							else {
								//cout << "File Measure_Ans.txt opened successfully!" << endl;
							}
							//variable line_4 to store content of a line
							string line_7;

							for (int i = 0; i < 25; i++) {
								//reads the number on a specific line and stores it in variable line_4
								getline(n6, line_7);
								//sets the i th answer to the class

								ques3[i].setDisp_Ans(line_7);
								//removes spaces and punctuation from answers

								string word = ques3[i].removeuppercases(line_7);

								//sets the i th answer in the class
								ques3[i].setans(ques3[i].removeSpaces(word));
							}

							//closes file Numbers2_Ans.txt
							n6.close();
							//----------------------------------------
	
							cout << endl;
							int r3;
							int rn3[10];
							for (int i = 0; i < 10; i++) {
								rn3[i] = 0;
							}
							int count = 0;
							//count till 5
							while (count < 10) {
								//generates a  random number between 0 and 20, and assigns it to variable r
								r3 = rand() % 25;
								//boolean variable to check if existing random number is found
								bool found = false;
								for (int i = 0; i < 10; i++) {
									//if the random number generated already exist in the array rn, then  generate another random number
									//this is to ensure that the array only contains distinct/different random numbers
									if (rn3[i] == r3) {
										found = true;
										break;
									}
								}
								//if the random number is not found in the array, then add it to the array
								if (!found) {
									rn3[count] = r3;
									count++; // increment count by one
								}
							}
							string answer3;
							//variable mark2 to store the total marks that the user has obtained after working out the questions
							int mark3 = 0;

							string wrqu3[10];
							for (int i = 0; i < 10; i++) {
								wrqu3[i] = "emp";
							}
							//displays 5 questions for the user to work out
							cin.ignore();
							for (int i = 0; i < 10; i++) {
								cout << endl;
								//gets the question from class and displays it
								cout << ques3[rn3[i]].getquestion() << endl;
								cout << "Answer: ";
								//allows user to input his/her answer
								getline(cin, answer3);
								string c1, c2;
								c1 = ques3[i].removeSpaces(answer3);
								c2 = ques3[i].removeuppercases(c1);
								//checks if the user has entered the correct answer
								if (c2 != ques3[rn3[i]].getans()) {
									cout << "Wrong! The correct answer is " << ques3[rn3[i]].getDisp_Ans() << "." << endl;
									wrqu3[i] = ques3[rn3[i]].getquestion();
								}
								else {
									//if user got the correct answer, displays Correct! on the screen and his/her mark is incremented
									cout << "Correct!" << endl;
									ques3[i].setmark3(1);
								}
							}

							for (int i = 0; i < 10; i++) {
								userinfo3[i].setwrong_ques(wrqu3[i]);
							}
							cout << endl;// leaves a line
							//Displays the total marks obtained by the user after working out the questions
							cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
							cout << "*           Total marks obtained: " << mark3 << "/10                   *" << endl;
							//Displays the kind of performance that the user has done
							if (mark3 <= 15) {
								//Displays this if the user has failed
								cout << "*               Poor Performance!                       *" << endl;
								cout << "*      Don't give up and practice more questions! ^-^   *" << endl;
								cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
							}
							else {
								if ((mark3 > 10) || (mark3 < 20)) {
									//Displays this if the user has not got full marks but still did a good job
									cout << "*               Good Performance!                       *" << endl;
									cout << "*                 Keep it up! :D                        *" << endl;
									cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
								}
								else {
									//Displays this if the user has got full marks
									cout << "*          Excellent Performance!                       *" << endl;
									cout << "*             Keep it up! :O                            *" << endl;
									cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
									cout << "__________________________________________________________________________________________________________________________________________" << endl;
								}
							}
						}
						else {
							if (choice == 4) {
								ifstream n7("Exam_Ques.txt");
								if (!n7.is_open()) {
									cout << "Error opening file Exam_Ques.txt!" << endl;
								}
								else {
									//cout << "File Exam_Ques.txt opened successfully!" << endl;
								}

								string line_7;
								while (!n7.eof()) {
									for (int i = 0; i < 30; i++) {
										getline(n7, line_7);
										ques4[i].setquestion(line_7);
									}
								}
								//---------------------------------------------
								/*cout << endl;
								cout << "Questions are:" << endl;
								cout << endl;
								for (int i = 0; i < 30; i++) {
									cout << ques4[i].getquestion() << endl;
								}*/
								//--------------------------------------------
								//closes file Numbers_Ques.txt
								n7.close();

								ifstream n8("Exam_Ans.txt");
								if (!n8.is_open()) {
									cout << "Error opening file Exam.txt!" << endl;
								}
								else {
									//cout << "File Exam_Ans.txt opened successfully!" << endl;
								}
								//variable line_4 to store content of a line
								string line_8;

								for (int i = 0; i < 30; i++) {
									//reads the number on a specific line and stores it in variable line_4
									getline(n8, line_8);
									//sets the i th answer to the class
									ques4[i].setDisp_Ans(line_8);

									//removes spaces and punctuation from answers

									string word = ques4[i].removeuppercases(line_8);

									//sets the i th answer in the class
									ques4[i].setans(ques4[i].removeSpaces(word));
								}

								//closes file Numbers2_Ans.txt
								n8.close();
								//----------------------------------------
						
								cout << endl;
								int r4;
								int rn4[15];
								for (int i = 0; i < 15; i++) {
									rn4[i] = 0;
								}
								int count = 0;
								//count till 5
								while (count < 15) {
									//generates a  random number between 0 and 20, and assigns it to variable r
									r4 = rand() % 30;
									//boolean variable to check if existing random number is found
									bool found = false;
									for (int i = 0; i < 15; i++) {
										//if the random number generated already exist in the array rn, then  generate another random number
										//this is to ensure that the array only contains distinct/different random numbers
										if (rn4[i] == r4) {
											found = true;
											break;
										}
									}
									//if the random number is not found in the array, then add it to the array
									if (!found) {
										rn4[count] = r4;
										count++; // increment count by one
									}
								}
								string answer4;
								//variable mark2 to store the total marks that the user has obtained after working out the questions
								int mark4 = 0;

								string wrqu4[15];
								for (int i = 0; i < 15; i++) {
									wrqu4[i] = "emp";
								}
								//displays 5 questions for the user to work out
								cin.ignore();
								for (int i = 0; i < 15; i++) {
									cout << endl;
									//gets the question from class and displays it
									cout << ques4[rn4[i]].getquestion() << endl;
									cout << "Answer: ";
									//allows user to input his/her answer
									getline(cin, answer4);
									string d1, d2;
									d1 = ques4[i].removeSpaces(answer4);
									d2 = ques4[i].removeuppercases(d1);
									//checks if the user has entered the correct answer
									if (d2 != ques4[rn4[i]].getans()) {
										cout << "Wrong! The correct answer is " << ques4[rn4[i]].getDisp_Ans() << "." << endl;
										wrqu4[i] = ques4[rn4[i]].getquestion();
									}
									else {
										//if user got the correct answer, displays Correct! on the screen and his/her mark is incremented
										cout << "Correct!" << endl;
										mark4++;
										ques4[i].setmark4(1);
									}
								}

								for (int i = 0; i < 15; i++) {
									userinfo4[i].setwrong_ques(wrqu4[i]);
								}
								cout << endl;// leaves a line
								//Displays the total marks obtained by the user after working out the questions
								cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
								cout << "*           Total marks obtained: " << mark4 << "/15                   *" << endl;
								//Displays the kind of performance that the user has done
								if (mark4 <= 15) {
									//Displays this if the user has failed
									cout << "*               Poor Performance!                       *" << endl;
									cout << "*      Don't give up and practice more questions! ^-^   *" << endl;
									cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
								}
								else {
									if ((mark4 > 10) || (mark4 < 20)) {
										//Displays this if the user has not got full marks but still did a good job
										cout << "*               Good Performance!                       *" << endl;
										cout << "*                 Keep it up! :D                        *" << endl;
										cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
									}
									else {
										//Displays this if the user has got full marks
										cout << "*          Excellent Performance!                       *" << endl;
										cout << "*             Keep it up! :O                            *" << endl;
										cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
										cout << "_____________________________________________________________________________________________________________" << endl;
									}
								}

							}
							else {
								if (choice == 5) {
									//------------------------------------
									cout << "___________________________________________________________________" << endl;
									cout << endl;
									cout << "Welcome To Your Profile!" << endl;
									cout << endl;
									cout << "Name: " << User_Info.getname() << endl;
									cout << "Age: " << User_Info.getage() << endl;
									cout << endl;
									cout << endl;
									cout << "Select a chapter to view your performance" << endl;
									cout << endl;
									cout << "1: Numbers One" << endl;
									cout << "2: Numbers Two" << endl;
									cout << "3: Measurement" << endl;
									cout << "4: Exam=Styled" << endl;
									cout << endl;
									int choice1;
									cout << "Enter your choice: ";
									cin >> choice1;
									if (choice1 == 1) {
										cout << "_____________________________________________________________________________________________________________" << endl;
										cout << endl;
										int total1 = 0;
										for (int i = 0; i < 10; i++) {
											total1 += ques[i].getmark1();
										}
										cout << "Score for Numbers One: " << total1 << "/10" << endl;
										cout << endl;
										cout << "Wrongly attempted questions are: " << endl;
										cout << endl;
										if (total1 == 0) {
											cout << "You have not yet done this exercise!" << endl;
										}
										else {
											ofstream f1(timestamped_file.c_str());
											f1 << "This file contains your performance during the quiz on Numbers One on " << dt << endl;
											f1 << endl;
											f1 << "Name : " << User_Info.getname() << endl;
											f1 << "Age   " << User_Info.getage() << endl;
											f1 << "Total Marks obtained: " << total1 << "/10" << endl;
											f1 << endl;
											f1 << "The questions that you have wrongly attempted are as follows." << endl;
											f1 << endl;
											int a = 0;
											for (int i = 0; i < 10; i++) {
												if (userinfo[i].getwrong_ques() != "emp") {
													cout << a + 1 << ". " << userinfo[i].getwrong_ques() << endl;
													f1 << a + 1 << ". " << userinfo[i].getwrong_ques() << endl;
													a++;
												}
											}
											f1.close();
										}
									}
									else {
										if (choice1 == 2) {

											int total2 = 0;
											for (int i = 0; i < 10; i++) {
												total2 += ques2[i].getmark2();
											}
											cout << "Numbers Two: " << total2 << endl;
											cout << endl;
											if (total2 == 0) {
												cout << "You have not yet done this exercise!" << endl;
											}
											else {
												ofstream f2(timestamped_file.c_str());
												f2 << "This file contains your performance during the quiz on Numbers Two on " << dt << endl;
												f2 << endl;
												f2 << "Name : " << User_Info.getname() << endl;
												f2 << "Age   " << User_Info.getage() << endl;
												f2 << "Total Marks obtained: " << total2 << "/5" << endl;
												f2 << endl;
												f2 << "The questions that you have wrongly attempted are as follows." << endl;
												f2 << endl;
												int b = 0;
												for (int i = 0; i < 5; i++) {
													if (userinfo2[i].getwrong_ques() != "emp") {
														cout << b + 1 << ". " << userinfo2[i].getwrong_ques() << endl;
														f2 << b + 1 << ". " << userinfo2[i].getwrong_ques() << endl;
														b++;
													}
												}
												f2.close();
											}
										}
										else {
											if (choice1 == 3) {
												cout << "_____________________________________________________________________________________________________________" << endl;
												int total3 = 0;
												for (int i = 0; i < 10; i++) {
													total3 += ques3[i].getmark3();
												}
												cout << "Measurement: " << total3 << endl;
												cout << endl;
												if (total3 == 0) {
													cout << "You have not yet done this exam!" << endl;
												}
												else {
													ofstream f3(timestamped_file.c_str());
													f3 << "This file contains your performance during the quiz on Measurement on " <<dt<< endl;
													f3 << endl;
													f3 << "Name : " << User_Info.getname() << endl;
													f3 << "Age   " << User_Info.getage() << endl;
													f3 << "Total Marks obtained: " << total3<<"/10" << endl;
													f3 << endl;
													f3 << "The questions that you have wrongly attempted are as follows." << endl;
													f3 << endl;
													int c = 0;
													for (int i = 0; i < 10; i++) {
														if (userinfo3[i].getwrong_ques() != "emp") {
															cout << c + 1 << ". " << userinfo3[i].getwrong_ques() << endl;
															f3 << c + 1 << ". " << userinfo3[i].getwrong_ques() << endl;
															c++;
														}
													}
													f3.close();
												}
											}
											else {
												if (choice1 == 4) {
													cout << "_____________________________________________________________________________________________________________" << endl;
													int total4 = 0;
													for (int i = 0; i < 15; i++) {
														total4 += ques4[i].getmark4();
													}
													cout << "Exam-Styled: " << total4 << endl;
													cout << endl;
													if (total4 == 0) {
														cout << "You have not yet done this exercise!" << endl;
													}
													else {
														ofstream f4(timestamped_file.c_str());
														f4 << "This file contains your performance during the quiz on Exam-Styled Quiz on " << dt << endl;
														f4 << endl;
														f4 << "Name : " << User_Info.getname() << endl;
														f4 << "Age   " << User_Info.getage() << endl;
														f4 << "Total Marks obtained: " << total4 <<"/15"<< endl;
														f4 << endl;
														f4 << "The questions that you have wrongly attempted are as follows." << endl;
														f4 << endl;
														int d = 0;
														for (int i = 0; i < 15; i++) {
															if (userinfo4[i].getwrong_ques() != "emp") {
																cout << d + 1 << ". " << userinfo4[i].getwrong_ques() << endl;
																f4 << d + 1 << ". " << userinfo4[i].getwrong_ques() << endl;
																d++;
															}
														}
														f4.close();
													}
												}
												else {
													cout << "Invalid Choice!" << endl;
												}
											}
										}
									}
								}
								else {
									//checks if the user has made an invalid input
									cout << "Invalid choice!!" << endl;
								}
							}

						}

					}
				}
				cout << endl;
				//displays menu again
				menu.menu1();
				//Prompts user to make a choice again
				cout << "Enter your choice: ";
				//allows input to variable choice
				while (!(cin >> choice))
				{
					cout << endl;
					cout << "ERROR: You must enter an integer! ";
					// Clear input stream
					cin.clear();
					// Discard previous input
					cin.ignore(123, '\n');
					//leaves a line
					cout << endl;
					//prompts the user to input again
					cout << "Enter your choice: ";
				}
				//leaves a line
				cout << endl;
			}
		}
		else {
			cout << "Please, enter a reasonable age!" << endl;
			cout << endl;
		}
	} while (valid == false);
	return 0;
}
