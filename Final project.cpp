#include<iostream>
using namespace std;
void mark()
{
    int n, x[6],y[6],z[6];
    struct marks
    {
           int maths,phy,chem,comp,eng;
    };       
    struct stud
    {
           char name[20];
           marks score;
           float avg;
    }child[20000];
    cout<<"Enter number of student's details you want to enter\n";
    cin>>n;
    cout<<"Enter name and then marks for maths, phy, chem, com & eng out of 100 for the no. of students entered\n";
    for(int i=0;i<n;i++)
    {
            cin>>child[i].name;
            cin>>child[i].score.maths;
            cin>>child[i].score.phy;
            cin>>child[i].score.chem;
            cin>>child[i].score.comp;
            cin>>child[i].score.eng;
            child[i].avg=(child[i].score.maths+child[i].score.phy+child[i].score.chem+child[i].score.comp+child[i].score.eng)/5;
    }
	cout<<"IN THE PICTORIAL REPRESENTATION: *=10 AND @=1\n";        
    for (int j=0;j<n;j++)
    {
        x[0]=child[j].score.maths/10;x[1]=child[j].score.phy/10;x[2]=child[j].score.chem/10;
        x[3]=child[j].score.comp/10;x[4]=child[j].score.eng/10;x[5]=child[j].avg/10;
        y[0]=child[j].score.maths-x[0]*10;y[1]=child[j].score.phy-x[1]*10;y[2]=child[j].score.chem-x[2]*10;
        y[3]=child[j].score.comp-x[3]*10;y[4]=child[j].score.eng-x[4]*10;y[5]=child[j].avg-x[5]*10;
        cout<<child[j].name<<endl;
        cout<<"MATHS            :";
        for(int i=0;i<x[0];i++)
        cout<<"*";
        for(int i=0;i<y[0];i++)
        cout<<"@";
		cout<<endl;
        cout<<"PHYSICS          :";
         for(int i=0;i<x[1];i++)
        cout<<"*";
        for(int i=0;i<y[1];i++)
        cout<<"@";
		cout<<endl;
        cout<<"CHEMISTRY        :";
         for(int i=0;i<x[2];i++)
        cout<<"*";
        for(int i=0;i<y[2];i++)
        cout<<"@";
		cout<<endl;
        cout<<"COMPUTER SCIENCE :";
         for(int i=0;i<x[3];i++)
        cout<<"*";
        for(int i=0;i<y[3];i++)
        cout<<"@";
		cout<<endl;
        cout<<"ENGLISH          :";
         for(int i=0;i<x[4];i++)
        cout<<"*";
        for(int i=0;i<y[4];i++)
        cout<<"@";
		cout<<endl;
        cout<<"AVERAGE          :";
         for(int i=0;i<x[5];i++)
        cout<<"*";
        for(int i=0;i<y[5];i++)
        cout<<"@";
		cout<<endl;
		cout<<endl;
    }
    system("pause");
} 
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

int checkwin(void);
void board(void);

void ttt()
{
	int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2==0)?2:1;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			exit(0);
		}
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";
		system("pause");

}
int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}
void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}
int main()
{
    char i,j;
    cout<<" Menu: \n";
    cout<<"1. Tic-tac-toe \n2. Score Analysis \n3. Exit \nEnter your choice: ";
    do{
              cin>>i;
              if(i=='1')
              ttt();
              else if(i=='2')
              mark();
              else if(i=='3')
              exit(0);
              else
              cout<<"Wrong choice";
              cout<<"Want to continue?: ";
              cin>>j;if(j=='Y')
              cout<<"Enter choice no: ";
    }while(j=='Y');
    system("pause");
}
              
              
         
