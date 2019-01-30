// General approach for me would be to create a map. Where the head of snake
// or the start of ladder would be mapped to the block it finally leaves the player at.

// This approach is to demonstarate the usage of OOP

#include <bits/stdc++.h>
using namespace std;

// The structure of snakes
struct snakes{
	int head;
	int tail;
};

// The structure of ladders
struct ladders{
	int start;
	int end;
};


// The structure of players
struct players{
	int initial;
	int turn;
	int location;
};

// The vector of snakes,ladders and players
vector <snakes> snake;
vector <ladders> ladder;
vector <players> player;

// Creating snakes
void insert_snake(int a, int b)
{
	
		snakes temp1;
		temp1.head=a;
		temp1.tail=b;
		snake.push_back(temp1);
}

// Creating ladders
void insert_ladder(int a, int b)
{
	
		ladders temp1;
		temp1.start=a;
		temp1.end=b;
		ladder.push_back(temp1);
}

// Creating players
void insert_player(int a, int b,int c)
{
	
		players temp1;
		temp1.initial=a;
		temp1.turn=b;
		temp1.location=c;
		player.push_back(temp1);
}

// Sorting the players according to their turns
bool player_sorter(players const& lhs, players const& rhs) {
    return lhs.turn > rhs.turn;
}

// Create the list of players and sort them on their turns
void create_all_players(int num)
{
	// The player with the highest roll gets the first chance
	// In case two players have the same number, the player who rolls first gets the first chance
	for(int i=1;i<=num;i++)
	{
		int b=rand() % 6 + 1;
		insert_player(i,b,0);
	}
	sort(player.begin(), player.end(), &player_sorter);
	for(int i=0;i<num;i++)
	{
		player[i].turn=i+1;
		cout<<"Player "<<player[i].initial<<" will get "<<player[i].turn<<" turn"<<endl;
	}
}

// The message displayed whenever someone wins the game
void victory_message(int winner)
{
	
				cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
				cout<<"XX Congratulations! Player "<<winner<<" wins!! XX\n";
				cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
}

// If there's a snake head, demote the player to snake tail
// If there's a laddet, promote player to top of ladder
int check_snakes_and_ladders(int a)
{
	int len=snake.size();
	for(int i=0;i<len;i++)
	{
		if(snake[i].head==a)
		{
			cout<<"Awww! You got bit by a snake!\n";
			return snake[i].tail;
		}
	}
	len=ladder.size();
	for(int i=0;i<len;i++)
	{
		if(ladder[i].start==a)
		{
			cout<<"Awesome! You just found a ladder!\n";
			return ladder[i].end;
		}
	}
	return a;
}

// The entire code for hoe the gameplay happens
void gameplay(int num)
{
	// We move till be have a winner
	while(1)
	{
		for(int i=0;i<num;i++)
		{
			// Generating random dice number
			int b=rand() % 6 + 1;
			cout<<"Player "<<player[i].initial<<" rolled "<<b<<" on the dice\n";
			// No movement if the player's new location will be greater than 100
			if(b+player[i].location>100)
			{
				continue;
			}
			// The victory condition
			else if(b+player[i].location==100)
			{
				victory_message(player[i].initial);
				return;
			}
			// The general condition
			else
			{
				player[i].location=b+player[i].location;
			}
			// If there's a snake/ladder at the location, moving the player accordingly 
			// and printing the ocation after that
			player[i].location=check_snakes_and_ladders(player[i].location);
			cout<<"Player "<<player[i].initial<<" new position is "<<player[i].location<<endl;
		}
	}
}

// we can also use a single structure/class for snake and ladder programatically speaking
// doing what we are doing here helps us at a conceptual level
int main() {
	
	int choice1=0;
	cout<<"Enter 1 to make your own snakes and ladder.\nEnter 2 to get our already customised snake and ladder\n";
	cin>>choice1;
	if(choice1==1)
	{
		cout<<"Enter total snakes";
		int num;
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			cout<<"Enter the head and tail of snake "<<i<<"\n";
			int a,b;
			cin>>a>>b;
			insert_snake(a,b);
		}
		cout<<"Enter total ladders";
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			cout<<"Enter the start and end of ladder "<<i<<"\n";
			int a,b;
			cin>>a>>b;
			insert_ladder(a,b);
		}
		cout<<"Snakes and ladders game ready!\n";
	}
	else if(choice1==2)
	{
		insert_snake(37,17);
		insert_snake(99,7);
		insert_snake(31,14);
		insert_snake(73,53);
		insert_ladder(5,25);
		insert_ladder(10,29);
		cout<<"Snakes and ladders game ready!\n";
	}
	int num;
	cout<<"Enter number of players\n";
	cin>>num;
	create_all_players(num);
	// All players are created and their turns assigned
	cout<<"The game starts!! \n";
	gameplay(num);
	return 0;
}

// Improvements possible:
// 1. Extra chance on rolling a 6
// 2. Could've used only the position and player number field in player. If there were space constraints.
// Logically this solution seems better
// 3. Logic to check that snake heads don't start at the same point. 
// Or that snake heads and ladders don't start at the same point or create a loop.
// 4. Keeping checks on limits of snakes and ladders to be between 1 and 99 inclusive.
// 5. A more faster way to search if snake/ladder exists at a certain position using binary search.
