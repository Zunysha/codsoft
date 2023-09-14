#include<iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};


class base{
	protected:
		char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
		public:
			void DrawBoard()
{
   system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|___" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|___" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

bool DetermineDraw()
{
  if (square[1] == square[2] && square[2] == square[3])

        return true;
    else if (square[4] == square[5] && square[5] == square[6])

        return true;
    else if (square[7] == square[8] && square[8] == square[9])

        return true;
    else if (square[1] == square[4] && square[4] == square[7])

        return true;
    else if (square[2] == square[5] && square[5] == square[8])

        return true;
    else if (square[3] == square[6] && square[6] == square[9])

        return true;
    else if (square[1] == square[5] && square[5] == square[9])

        return true;
    else if (square[3] == square[5] && square[5] == square[7])

        return true;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return true;
    else
        return false;
}

			
		
};
class derived:public base{
	public:
		void GetMove()
{
    	int player = 1;
		bool i;
		string choice;
    	char mark;
    	do{
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';

        if (choice =="1" && square[1] == '1')

            square[1] = mark;
        else if (choice == "2" && square[2] == '2')

            square[2] = mark;
        else if (choice == "3" && square[3] == '3')

            square[3] = mark;
        else if (choice == "4" && square[4] == '4')

            square[4] = mark;
        else if (choice == "5" && square[5] == '5')

            square[5] = mark;
        else if (choice == "6" && square[6] == '6')

            square[6] = mark;
        else if (choice == "7" && square[7] == '7')

            square[7] = mark;
        else if (choice == "8" && square[8] == '8')

            square[8] = mark;
        else if (choice == "9" && square[9] == '9')

            square[9] = mark;
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i=DetermineDraw();

        player++;
        DrawBoard();
}while(i==false);
    	
    if(i==true)

        cout<<" Player "<<--player<<" win ";
    else
        cout<<"   aGame draw   ";

    cin.ignore();
    cin.get();
}



};




 int main()
{ char rt;
do {


    derived game;
    while(game.DetermineDraw() == false)
    {
        game.DrawBoard();
        game.GetMove();
    }

    system("pause");
    cout<<"PRESS Y IF WANT TO PLAY ANOTHER GAME OR ANOTHER KEY TO EXIT:";
    cin>>rt;}while(rt=='y'|| rt=='Y');
}