#include<fstream>
#include<iostream>
#include <conio.h> 
#include <string>
using namespace std;
//Game play funtion
void clrscr();
void Game_play(char** m,int rows,int cols, char play1[], char play2[] ,int& player1_wins ,int& player2_wins ,int& draw )
{
   
    char positon_num;
    for (int i = 1; i <= 9; i++)
    {

        if (i % 2 != 0)
        {
            cout << play1 << " turn 'X' Enter a position Number : ";
            cin >> positon_num;
          
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (m[i][j] == positon_num)
                    {
                        m[i][j] = 'X';
                        if (m[0][0] == 'X' && m[0][1] == 'X' && m[0][2] == 'X' || m[0][2] == 'X' && m[1][2] == 'X' && m[2][2] == 'X' ||
                            m[2][0] == 'X' && m[2][1] == 'X' && m[2][2] == 'X' || m[1][0] == 'X' && m[1][1] == 'X' && m[1][2] == 'X' ||
                            m[0][0] == 'X' && m[1][0] == 'X' && m[2][0] == 'X' || m[0][1] == 'X' && m[1][1] == 'X' && m[2][1] == 'X' ||
                            m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == 'X' || m[0][2] == 'X' && m[1][1] == 'X' && m[2][0] == 'X')
                        {
                            cout <<endl<< "The Winner is " << play1 << endl;
                            player1_wins++;
                            cout << " " << m[0][0] << "   |  " << m[0][1] << "  | " << m[0][2] << endl;
                            cout << "_____|_____|_____" << endl;
                            cout << " " << m[1][0] << "   |  " << m[1][1] << "  | " << m[1][2] << endl;
                            cout << "_____|_____|_____" << endl;
                            cout << " " << m[2][0] << "   |  " << m[2][1] << "  | " << m[2][2] << endl;
                            cout << "     |     |    " << endl;
                            clrscr();
                            goto end_of_both;
                        }

                    }
                }
            }
            cout << " " << m[0][0] << "   |  " << m[0][1] << "  | " << m[0][2] << endl;
            cout << "_____|_____|_____" << endl;
            cout << " " << m[1][0] << "   |  " << m[1][1] << "  | " << m[1][2] << endl;
            cout << "_____|_____|_____" << endl;
            cout << " " << m[2][0] << "   |  " << m[2][1] << "  | " << m[2][2] << endl;
            cout << "     |     |    " << endl;

        }
        else if (i % 2 == 0)
        {
            cout << play2 << " turn 'O' Enter a position Number : ";
            cin >> positon_num;
           
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (m[i][j] == positon_num)
                    {
                        m[i][j] = 'O';
                        if (m[0][0] == 'O' && m[0][1] == 'O' && m[0][2] == 'O' || m[0][2] == 'O' && m[1][2] == 'O' && m[2][2] == 'O' ||
                            m[2][0] == 'O' && m[2][1] == 'O' && m[2][2] == 'O' || m[1][0] == 'O' && m[1][1] == 'O' && m[1][2] == 'O' ||
                            m[0][0] == 'O' && m[1][0] == 'O' && m[2][0] == 'O' || m[0][1] == 'O' && m[1][1] == 'O' && m[2][1] == 'O' ||
                            m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == 'O' || m[0][2] == 'O' && m[1][1] == 'O' && m[2][0] == 'O')
                        {
                            cout <<endl<< "The Winner is " << play2 << endl;
                            player2_wins++;
                            cout << " " << m[0][0] << "   |  " << m[0][1] << "  | " << m[0][2] << endl;
                            cout << "_____|_____|_____" << endl;
                            cout << " " << m[1][0] << "   |  " << m[1][1] << "  | " << m[1][2] << endl;
                            cout << "_____|_____|_____" << endl;
                            cout << " " << m[2][0] << "   |  " << m[2][1] << "  | " << m[2][2] << endl;
                            cout << "     |     |    " << endl;
                            goto end_of_both;
                        }

                    }
                }
            }
            cout << " " << m[0][0] << "   |  " << m[0][1] << "  | " << m[0][2] << endl;
            cout << "_____|_____|_____" << endl;
            cout << " " << m[1][0] << "   |  " << m[1][1] << "  | " << m[1][2] << endl;
            cout << "_____|_____|_____" << endl;
            cout << " " << m[2][0] << "   |  " << m[2][1] << "  | " << m[2][2] << endl;
            cout << "     |     |    " << endl;
        }
    }
    cout << " The Game is draw " << endl;
    draw++;
end_of_both:
    cout << " ";
    
}


void result(char play1[], char play2[], int player1_wins, int player2_wins, int draw) {
    fstream result;
    result.open("Result.txt", ios::out);
    result << "Name   Wins   Draws " << endl;
    result << play1 << "   " << player1_wins << "   " << draw << endl;
    result << play2 << "   " << player2_wins << endl;
    result << "********************************************" << endl;
}

//array data function
void initialize_board(char** m, int rows, int cols) {
    char num = '1';
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m[i][j] = num;
            ++num;
        }
    }
}




//<-1-> Start Game Funtion  

void start_Game(char** m, int rows, int cols, char player1[], char player2[],int player1_wins,int player2_wins,  int draw)
{
    char  chr;
    cout << "Enter player 1 name : ";
    cin >> player1;
    cout << "Enter player 2 name : ";
    cin >> player2;
    cout << endl;
    cout << "Sign for " << player1 << " is  : 'X' " << endl;
    cout << "Sign for " << player2 << " is  : 'O' " << endl;
    do {
        initialize_board(m, rows, cols);
        cout << " " << m[0][0] << "   |  " << m[0][1] << "  | " << m[0][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << " " << m[1][0] << "   |  " << m[1][1] << "  | " << m[1][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << " " << m[2][0] << "   |  " << m[2][1] << "  | " << m[2][2] << endl;
        cout << "     |     |    " << endl;
        Game_play(m,rows,cols, player1, player2, player1_wins, player2_wins, draw);
        result(player1, player2, player1_wins, player2_wins, draw);
        
        
        
        
        cout << "Do you want Rematch with Each other? Yes(y) or No(n) :";
        cin >> chr;
    } while (chr == 'Y' || chr == 'y');
}

//<-2-> Instructions Function
string Instructions() {
    string line, instruction1 = { " " };
    
    fstream instruction;
    instruction.open("Instructions.txt", ios::in);
    if (instruction.is_open()) {
       
            while(getline(instruction,line)) {
                
                instruction1+=line+"\n";
            }
        
       
        
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }
   

    instruction.close();
    return instruction1;
}




int main() {
    int rows = 3,cols=3;
    char** m = new char* [rows];
    for (int i = 0; i <rows; ++i) {
        m[i] = new char[cols];
    }
    /*char num = '1';
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m[i][j] = num;
            ++num;
        }
    }*/

    
        char player1[20], player2[20];
        bool exit = false;
        int win1 = 0, win2 = 0, draw = 0;
        string instruction1 = {" "};
        cout << "********** Wellcome To Tic-Tac-Toe Game **********" << endl;
        while(!exit){
            
            cout << "***** Game Manu *****" << endl;
            cout << "<-1-> Start Game " << endl;
            cout << "<-2-> Instructions " << endl;
            cout << "<-3-> Results " << endl;
            cout << "<-4-> Eixt Game " << endl;
            cout << " Choose Option : ";
            string print;
            int n;
            cin >> n;
            
            switch (n)
            {
            case 1:
                start_Game(m ,cols,rows, player1, player2, win1, win2,draw);
                break;
            case 2:
                cout << endl;
                cout<< Instructions();
                
                break;
            case 3:
                
                break;
            case 4:
                cout << "Eixting..."<<endl;
                exit = true;
                
                break;
            default :
                cout << " Invalid Input! " << endl;
                break;
            }

            
        }

        for (int i = 0; i < rows; ++i) {
            delete[] m[i];
        }
        delete[] m;

    return 0;
    }













