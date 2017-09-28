#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
class play_cards
{
public:
	void play_cards::load();
	void play_cards::printdeck();
	void play_cards::shuffle();
	void play_cards::play();
	void play_cards::starting();
	void play_cards::rules();
	void play_cards::wins();
	int play_cards::total(char who);
	int play_cards::deal();
	bool play_cards::over(char who);
	
private:
	struct deck
	{
		string card_name;
		string card_type;
		int card_value;
		bool dealt;
	};
	deck card[52];
	int i,count,n;
	double pWins,cWins, games;

	struct hand
	{
		int pCard;
		hand *next;
	};
	hand *pCurrent, *pPrev, *pFirst,*cCurrent, *cPrev,*cFirst;

};
int main() //just calls the play_cards class and runs play().
{
	play_cards value;
	value.play();
	system("pause");
    return 0;
}
void play_cards::rules()
{
	cout << "The rules for 21:" <<endl << "Each player gets 2 cards to start, the dealer(computer)'s second card is unknown " <<endl;
	cout << "The value of the card is the face value, the face cards are ten, and the ace is either eleven or 1" <<endl;
	cout << "The goal is to get to twenty-one points without going over." << endl << "If you go over, you lose."<<endl;
	cout << "You may take as many cards as you like until you go bust (go over twenty-one points)." << endl;
	cout << "The dealer must take a card if he is under seventeen points" << endl;
	cout << "There is only one deck in play. It gets shuffled if it goes under sixteen cards" << endl;
}

void play_cards::load()
	{
	pFirst = new hand; //starting node for player
	pFirst->next = 0;
	pPrev =pFirst;
	cFirst = new hand; //starting node for computer
	cFirst->next = 0;
	cPrev = cFirst;

	card[0].card_name="TWO";
	card[0].card_type="heart";
	card[0].card_value=2;
	card[0].dealt=false;
	card[1].card_name="THREE";
	card[1].card_type="heart";
	card[1].card_value=3;
	card[1].dealt=false;
	card[2].card_name="FOUR";
	card[2].card_type="heart";
	card[2].card_value=4;
	card[2].dealt=false;
	card[3].card_name="FIVE";
	card[3].card_type="heart";
	card[3].card_value=5;
	card[3].dealt=false;
	card[4].card_name="SIX";
	card[4].card_type="heart";
	card[4].card_value=6;
	card[4].dealt=false;
	card[5].card_name="SEVEN";
	card[5].card_type="heart";
	card[5].card_value=7;
	card[5].dealt=false;
	card[6].card_name="EIGHT";
	card[6].card_type="heart";
	card[6].card_value=8;
	card[6].dealt=false;
	card[7].card_name="NINE";
	card[7].card_type="heart";
	card[7].card_value=9;
	card[7].dealt=false;
	card[8].card_name="TEN";
	card[8].card_type="heart";
	card[8].card_value=10;
	card[8].dealt=false;
	card[9].card_name="ACE";
	card[9].card_type="heart";
	card[9].card_value=11;
	card[9].dealt=false;
	card[10].card_name="JACK";
	card[10].card_type="heart";
	card[10].card_value=10;
	card[10].dealt=false;
	card[11].card_name="QUEEN";
	card[11].card_type="heart";
	card[11].card_value=10;
	card[11].dealt=false;
	card[12].card_name="KING";
	card[12].card_type="heart";
	card[12].card_value=10;
	card[12].dealt=false;
		
	card[13].card_name="TWO";
	card[13].card_type="diamond";
	card[13].card_value=2;
	card[13].dealt=false;
	card[14].card_name="THREE";
	card[14].card_type="diamond";
	card[14].card_value=3;
	card[14].dealt=false;
	card[15].card_name="FOUR";
	card[15].card_type="diamond";
	card[15].card_value=4;
	card[15].dealt=false;
	card[16].card_name="FIVE";
	card[16].card_type="diamond";
	card[16].card_value=5;
	card[16].dealt=false;
	card[17].card_name="SIX";
	card[17].card_type="diamond";
	card[17].card_value=6;
	card[17].dealt=false;
	card[18].card_name="SEVEN";
	card[18].card_type="diamond";
	card[18].card_value=7;
	card[18].dealt=false;
	card[19].card_name="EIGHT";
	card[19].card_type="diamond";
	card[19].card_value=8;
	card[19].dealt=false;
	card[20].card_name="NINE";
	card[20].card_type="diamond";
	card[20].card_value=9;
	card[20].dealt=false;
	card[21].card_name="TEN";
	card[21].card_type="diamond";
	card[21].card_value=10;
	card[21].dealt=false;
	card[22].card_name="ACE";
	card[22].card_type="diamond";
	card[22].card_value=11;
	card[22].dealt=false;
	card[23].card_name="JACK";
	card[23].card_type="diamond";
	card[23].card_value=10;
	card[23].dealt=false;
	card[24].card_name="QUEEN";
	card[24].card_type="diamond";
	card[24].card_value=10;
	card[24].dealt=false;
	card[25].card_name="KING";
	card[25].card_type="diamond";
	card[25].card_value=10;
	card[25].dealt=false;
		
	card[26].card_name="TWO";
	card[26].card_type="spade";
	card[26].card_value=2;
	card[26].dealt=false;
	card[27].card_name="THREE";
	card[27].card_type="spade";
	card[27].card_value=3;
	card[27].dealt=false;
	card[28].card_name="FOUR";
	card[28].card_type="spade";
	card[28].card_value=4;
	card[28].dealt=false;
	card[29].card_name="FIVE";
	card[29].card_type="spade";
	card[29].card_value=5;
	card[29].dealt=false;
	card[30].card_name="SIX";
	card[30].card_type="spade";
	card[30].card_value=6;
	card[30].dealt=false;
	card[31].card_name="SEVEN";
	card[31].card_type="spade";
	card[31].card_value=7;
	card[31].dealt=false;
	card[32].card_name="EIGHT";
	card[32].card_type="spade";
	card[32].card_value=8;
	card[32].dealt=false;
	card[33].card_name="NINE";
	card[33].card_type="spade";
	card[33].card_value=9;
	card[33].dealt=false;
	card[34].card_name="TEN";
	card[34].card_type="spade";
	card[34].card_value=10;
	card[34].dealt=false;
	card[35].card_name="ACE";
	card[35].card_type="spade";
	card[35].card_value=11;
	card[35].dealt=false;
	card[36].card_name="JACK";
	card[36].card_type="spade";
	card[36].card_value=10;
	card[36].dealt=false;
	card[37].card_name="QUEEN";
	card[37].card_type="spade";
	card[37].card_value=10;
	card[37].dealt=false;
	card[38].card_name="KING";
	card[38].card_type="spade";
	card[38].card_value=10;
	card[38].dealt=false;
		
	card[39].card_name="TWO";
	card[39].card_type="club";
	card[39].card_value=2;
	card[39].dealt=false;
	card[40].card_name="THREE";
	card[40].card_type="club";
	card[40].card_value=3;
	card[40].dealt=false;
	card[41].card_name="FOUR";
	card[41].card_type="club";
	card[41].card_value=4;
	card[41].dealt=false;
	card[42].card_name="FIVE";
	card[42].card_type="club";
	card[42].card_value=5;
	card[42].dealt=false;
	card[43].card_name="SIX";
	card[43].card_type="club";
	card[43].card_value=6;
	card[43].dealt=false;
	card[44].card_name="SEVEN";
	card[44].card_type="club";
	card[44].card_value=7;
	card[44].dealt=false;
	card[45].card_name="EIGHT";
	card[45].card_type="club";
	card[45].card_value=8;
	card[45].dealt=false;
	card[46].card_name="NINE";
	card[46].card_type="club";
	card[46].card_value=9;
	card[46].dealt=false;
	card[47].card_name="TEN";
	card[47].card_type="club";
	card[47].card_value=10;
	card[47].dealt=false;
	card[48].card_name="ACE";
	card[48].card_type="club";
	card[48].card_value=11;
	card[48].dealt=false;
	card[49].card_name="JACK";
	card[49].card_type="club";
	card[49].card_value=10;
	card[49].dealt=false;
	card[50].card_name="QUEEN";
	card[50].card_type="club";
	card[50].card_value=10;
	card[50].dealt=false;
	card[51].card_name="KING";
	card[51].card_type="club";
	card[51].card_value=10;
	card[51].dealt=false;
	}
void play_cards::printdeck()
{	
	 //loop to print all cards
       for (i=0; i<=51; ++i)
        {
    	if((i==13)||(i==26)||(i==39))
    		cout<<endl;
            cout<<card[i].card_name<<" "<<card[i].card_type<<" " <<card[i].card_value<<" " +card[i].dealt<<endl;
        }
}
	
void play_cards::shuffle() //sets card[i].dealt to false AKA Shuffle
{
	for (i=0; i<=51;i++)
	{
		card[i].dealt = false;
	}
}

int play_cards::deal() //returns a random int between 0 and 51, used to draw a card
{
	int deals=0;
	if(count >=37)
	{
		shuffle();
		count=0;
	}

	else
	{
		srand((int) time(0));
		do
		{
			deals = (rand()%52);
		}while(card[deals].dealt == true);

		card[deals].dealt = true;
		count++;
	}
	return deals;
}

bool play_cards::over(char who) //who says whether this check is for the computer or player, function is used to see if the computer or the player busted
{
	int total=0;
	bool bust;

	if (who =='p')
	{
		pCurrent = pFirst->next;
		while(pCurrent != 0)
		{
			total = total + card[pCurrent->pCard].card_value;
			pCurrent = pCurrent->next;
		}
		
		pCurrent = pFirst->next;
		while(pCurrent!=0) // checks for an ace
		{
			if(card[pCurrent->pCard].card_name == "ACE" && total > 21 )
			{
				total = total - 10;
			}
			pCurrent = pCurrent->next;
		}
	}

	if (who =='c')
	{
		cCurrent = cFirst->next;
		while(cCurrent != 0) // calculates the total value of all the cands in the hand
		{
			total = total + card[cCurrent->pCard].card_value; 
			cCurrent = cCurrent->next;
		}
		
		cCurrent = cFirst->next;
		while(cCurrent!=0)
		{
			if(card[cCurrent->pCard].card_name == "ACE" && total > 21 ) // checks for an ace
			{
				total = total - 10;
			}
			cCurrent = cCurrent->next;
		}
	}
	if(total>21)
		bust = true;
	else
		bust = false;
	return bust;
}

int play_cards::total(char who) //Function that returns the total value of cards in either the players or the computers hand. 
{
	bool ace = false;
	int points = 0,aceCount = 0;
	cCurrent = cFirst->next;
	pCurrent = pFirst->next;

	if(who =='p')
	{
		while (pCurrent!=0)
		{
			points = points + card[pCurrent->pCard].card_value;
			if(card[pCurrent->pCard].card_name == "ACE")
			{
				ace = true;
				aceCount ++;
			}
			pCurrent = pCurrent->next;
		}

	}

	if(who == 'c')
	{
		while(cCurrent!=0)
		{
			points = points + card[cCurrent->pCard].card_value;
			if(card[cCurrent->pCard].card_name == "ACE")
			{
				ace = true;
				aceCount ++;
			}
			cCurrent = cCurrent->next;
		}
	}
	
	if (ace && points >21) // Same thing as in over(), Checks for ace, just different algorithum. 
	{
		for(int i =1; i<=4;i++)
		{
			if (aceCount >= i && points >21)
				points = points - 10;			
		}
	}
	return points;
}

void play_cards::starting() //The start of a game. Deal 2 cards to both the player and the computer
{
	cPrev = cFirst;
	pPrev = pFirst;
	
	for (int i=1; i<=2; i++)
	{
		cCurrent = new hand;
		pCurrent = new hand;
		pCurrent->pCard = deal();
		cCurrent->pCard = deal();
		cout << "The card that you got: " << card[pCurrent->pCard].card_name << " of " << card[pCurrent->pCard].card_type << "s" <<endl;
		if(i==1)
			cout << "The card the computer got: "<< card[cCurrent->pCard].card_name << " of " << card[cCurrent->pCard].card_type<< "s" <<endl;
		else
			cout << "The computer's second card is hidden." << endl;
		cCurrent->next = 0;
		cPrev ->next = cCurrent;
		cPrev = cCurrent;
		pCurrent->next = 0;
		pPrev ->next = pCurrent;
		pPrev = pCurrent;
	}
}

void play_cards::wins()
{
	double percentage = 0;
	percentage = pWins/games * 100;
	cout <<"There were " << games << " games played" << endl;
	cout <<"The player won " << pWins << " games" << endl;
	cout <<"The computer won " << cWins << " games" << endl;
	cout <<"The player won " << percentage << "% of the games" << endl;
}

void play_cards::play() //The main function. Calls other functions in the class and runs the program.
{
	int pPoints = 0,cPoints = 0;
	pWins = 0; cWins = 0, games = 0;
	string cont,another;	
	load();
	rules();
	cout <<"Would you like to play? (Enter Yes/No)" << endl;	
	cin >>cont;
	while(cont != "Yes" && cont != "No")
	{
		cout << "Please Enter Yes or No" << endl;
		cin >>cont;
	}
	cout << endl;
	
	while (cont =="Yes")
	{
		starting();
		cout << "Would you like another card(Yes/No)";
		cin >> another;
		
		while(another == "Yes" && !over('p'))
		{
			pCurrent = new hand;
			pCurrent->pCard = deal();
			cout << "The card that you got: " << card[pCurrent->pCard].card_name << " of " << card[pCurrent->pCard].card_type << "s" <<endl;
			
			pCurrent->next =0;
			pPrev->next = pCurrent;
			pPrev = pCurrent;
			if(!over('p'))
			{
				cout << "Would you like anther card?(Yes/No)";
				cin >> another;
			}
		}

		pPoints = total('p');
		if(over('p'))
		{
			cout << "You lost because you busted with: " <<pPoints<< " points" << endl;
			games ++;
			cWins ++;
		}
		cCurrent = cFirst->next;
		cCurrent =cCurrent->next;
		cout << "The second card the computer got: " << card[cCurrent->pCard].card_name << " of " << card[cCurrent->pCard].card_type << "s" <<endl;
		cPoints = total('c');
		if(over('p'))
			cout << "The computer had " << cPoints << " points." << endl;
		
		if(!over('p'))
		{
			while(cPoints <17)
			{
				cCurrent = new hand;
				cCurrent->pCard = deal();
				cout << "The card the computer got: "<< card[cCurrent->pCard].card_name << " of " << card[cCurrent->pCard].card_type<< "s" <<endl;
				cPoints = card[cCurrent->pCard].card_value + cPoints;
				cCurrent->next=0;
				cPrev->next = cCurrent;
				cPrev = cCurrent;
			}
			if(!over('c'))
			{				
				if(pPoints == cPoints)
				{
					cout << "There was a tie! You both had " << pPoints << " points"<< endl;
					games ++;
				}
				else if (pPoints< cPoints)
				{
					cout << "You lose with " << pPoints << " points." << endl;
					cout << "The computer wins with " << cPoints << " points" << endl;
					games ++;
					cWins ++;
				}
				else
				{
					cout << "You win with " << pPoints << " points." << endl;
					cout <<"The computer loses with " << cPoints << " points." << endl;
					games ++;
					pWins ++;
				}
			}
			if(over('c'))
			{
				cout << "You won because the computer busted." << endl;
				cout << "You had " << pPoints << " points." << endl;
				cout <<"The computer loses with " << cPoints << " points." << endl;
				games ++;
				pWins ++;
			}
		}
		cout << "Would you like to play again (Yes/No)?";
		cin >>cont;
		
		while(cont != "Yes" && cont != "No")
		{
			cout << "Please Enter Yes or No" << endl;
			cin >>cont;
		}
		cout << endl;
	}	
	wins();
}
