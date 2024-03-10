#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;

//File: CS112_A1_T5_game3_20230320
/*program: This game is two-player game which generate a random no. of coins and each player remove
 a non-zero square no. and the player who removes the last coin wins (Game 3).*/
//Author: Mohamed Ashraf Said Ibrahim
//ID: 20230320
// Version : 1.2
// Date : 23/2/2023




// Function to check if the number is a perfect square or not
bool check_perfect_square(int n){
    int root = sqrt(n);
    return pow(root,2)==n;
    // if sqrt(n)**2 == n => return true ,else return false
}

int main()
{
    cout<<"Welcome to <Subtract a square> game"<<endl;
    int no_of_tokens;
    int player1_turn;
    int player2_turn;
    while(true){
        //main menu
        cout<<"\nA) Start game\nB) Quit"<<endl;
        char choice;
        cin >> choice;
        char choice_upper = toupper(choice);
        if(choice_upper=='A'){

           while(true){

                no_of_tokens = rand()%1000+100; // generate a random no. of tokens

                if(check_perfect_square(no_of_tokens)){ // make sure the random no. isn't a square no.
                    continue;
                }
                else{
                    break;
                }
           }
        }
        else if(choice_upper == 'B'){ //Exit program
            break;
        }
        else{
            cout<<"Please select a valid choice\n";
            continue;
        }
        // game starts

        while(true){  // player 1 turn

            if(no_of_tokens==0){  // check if the game ended or not after player 2 turn
                break;
            }
            cout<<"No of tokens: "<<no_of_tokens<<endl;
            // player 1 turn
            cout<<"player 1 turn: ";
            cin >>player1_turn;
            while(cin.fail()){ // make sure the entered no. is int
                cout<<"Please enter a number \n";
                cin.clear();
                cin.ignore(256,'\n');
                cin>>player1_turn;
            }
            if(check_perfect_square(player1_turn)&& player1_turn<=no_of_tokens){
                no_of_tokens -= player1_turn;
                cout<<"No of tokens: "<<no_of_tokens<<endl; // Display no. of tokens after player 1 turn
                if(no_of_tokens == 0){
                    cout<<"Congratulations!"<<endl<<"Player 1 wins!\n"; // Declare the winner
                    break;

                }
            }
            else{ // handling errors
                if(player1_turn > no_of_tokens){
                    cout<<"Enter a number lower than number of tokens \n";
                    continue;
                }
                cout<<"Please enter a perfect square number \n";
                continue;
            }
            while(true){   // player 2  turn

            cout<<"player 2 turn: ";
            cin >>player2_turn;
            while(cin.fail()){
                cout<<"Please enter a number \n";
                cin.clear();
                cin.ignore(256,'\n');
                cin>>player2_turn;
            }
            if(check_perfect_square(player2_turn)&& player2_turn<=no_of_tokens){
                no_of_tokens -= player2_turn;


                if(no_of_tokens == 0){
                    cout<<"No of tokens: "<<no_of_tokens<<endl;
                    cout<<"Congratulations!"<<endl<<"Player 2 wins!\n"; // Declare the winner
                    break;

                }
                break;
            }
            else{ // handling errors
                if(player2_turn > no_of_tokens){
                    cout<<"Enter a number lower than number of tokens \n";
                    cout<<"No of tokens: "<<no_of_tokens<<endl;
                    continue;
                }
                cout<<"Please enter a perfect square number \n";
                cout<<"No of tokens: "<<no_of_tokens<<endl;
                continue;
            }
            }

            }//end of the (game starts) loop


    }//end of the (whole program) loop




    return 0;
}
