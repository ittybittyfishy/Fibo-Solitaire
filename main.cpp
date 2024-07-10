// Olivia Fishbough
// Fibonacci Solitaire Single File
// Feb 21 2023

/* 
Allows the user to play fibonacci solitaire in a single file

Class:
  Card - Creates a card object
    Functions:
      Card() - Default constructor
      Card(char r, char s) - Constructor with parameters r for the cards rank and s for the cards suit
      void setCard(char r, char s) - Sets the cards rank and suit
      int getValue() - Returns the point value of the card
      void showCard() - Displays the card rank and suit
      
  Deck - Creates a deck of cards
    Functions: 
      Deck() - Default constructor that creates a deck of 52 cards in a vector
      void resetDeck() - Resets the deck
      Card deal() - Deals top card from the deck
      void shuffle() - Shuffles the deck
      bool isEmpty() - Checks if the deck is empty and if so returns true
      void show() - Displays all the cards in the deck
      
  Main: Presents the player with a menu to wither create a deck, shuffle the deck, display the deck, play the game once, automatically play the game until the player wins, or to exit the program. 
  



*/

#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:
  char rank;
  char suit;

/*
  Default constructor. Creates a card with default values
  Parameters: 
    None
*/ 
  Card()
  { 
  }

/* 
  parameter constructor. Used to create card with a specifc rank and suit
  parameters: 
    char r - rank of the card
    char s - suit of the card
*/
  Card(char r, char s)
  {
    rank = r;
    suit = s;
  }

/*
  Sets the rank and suit of the card 
  Parameters:
    char r - rank of the card
    char s - suit of the card
*/
  void setCard(char r, char s)
  {
     rank = r;      suit = s;
  }
/*
  Returns the point value of the card
  Parameters:
    None
  Returns:
    int - point value of the card
*/
  int getValue()
  {
    if (rank == 'A') {return 1;}
    else if (rank == 'K' || rank == 'Q' || rank == 'J') { return 10;}
    else if (rank == '2') { return 2;}
    else if (rank == '3') { return 3;}
    else if (rank == '4') { return 4;}
    else if (rank == '5') { return 5;}
    else if (rank == '6') { return 6;}
    else if (rank == '7') { return 7;}
    else if (rank == '8') { return 8;}
    else if (rank == '9') { return 9;}
    else if (rank == 'T') { return 10;}
    else {return 0;}
  }

/*
  Displays the card rank and suit
  Parameters:
    None
*/
  void show()
  {
    string rankName;
    string suitName;
    // Assigns rank to a name
    if (rank == 'A') {rankName = "A";}
    else if (rank == 'K') { rankName = "K";}
    else if (rank == 'Q') { rankName = "Q";}
    else if (rank == 'J') { rankName = "J";}
    else if (rank == '2') { rankName = "2" ;}
    else if (rank == '3') { rankName = "3";}
    else if (rank == '4') { rankName = "4";}
    else if (rank == '5') { rankName = "5";}
    else if (rank == '6') { rankName = "6";}
    else if (rank == '7') { rankName = "7";}
    else if (rank == '8') { rankName = "8";}
    else if (rank == '9') { rankName = "9";}
    else if (rank == 'T') { rankName = "10";}

    // assigns suit to a name
    if (suit == 'D') { suitName = "♦";}
    else if (suit == 'S') { suitName = "♠";}
    else if (suit == 'C') { suitName = "♣";}
    else if (suit == 'H') { suitName = "♥";}

    // prints completed name
    cout << rankName << suitName;
  }
    
};

class Deck
{
  public:
  Card cardDeck[52] = {};
  int num;

/*
   Default constructor. Creates a deck of 52 cards in a vector
   Parameters: 
      None
*/ 
    Deck() 
    {
      char rank[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
      char suit[4] = {'S','H','D','C'};
      int placement = 0;
      for (int i = 0; i < 4; i++)
        {
          for (int j=0; j < 13; j++)
            {
              cardDeck[placement++] = (Card(rank[j],suit[i]));
            }
        }
    }
/*
    Resets the deck
    Parameters:
      None
*/
    void resetDeck()
    {
      char rank[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
      char suit[4] = {'S','H','D','C'};
      int placement = 0;
      num = 0;
      for (int i = 0; i < 4; i++)
        {
          for (int j=0; j < 13; j++)
            {
              cardDeck[placement++] = (Card(rank[j],suit[i]));
            }
        }
    }
/*
    Deals top card from the deck
    Parameters:
      None
    Returns:
      Card - top card from the deck
*/

    Card deal()
    {
      Card x = cardDeck[0];
      if (num != 52)
        {
          for (int i=0; i<52; i++)
          {
          cardDeck[i] = cardDeck[i+1];
          }
          num += 1;
        }
      return x;
    }

/*
    Shuffles the deck
    Parameters:
      None
*/
    void shuffle()
    {
      for(int i = 0; i < 52; i++)
        {
          int x = rand() % 52;
          int y = rand() % 52;
          auto temp = cardDeck[x];
          cardDeck[x] = cardDeck[y];
          cardDeck[y] = temp;
        }
    }
    // if empty returns true
    bool isEmpty()
    {
      if(num == 52 || num > 52) return true;
      else return false;
    }
/*
    Displays all the cards in the deck
    Parameters:
      None
*/ 
    void show()
    {
      int placement = 0;
      for (int i =0; i < 4; i++)
        {
          for (int j=0; j < 13; j++)
            {
              cardDeck[placement++].show();
              cout << ", ";
            }
          cout << endl;
        }
      }
};



int main() 
{
  bool running = true;
  int choice;
  int games = 0;
  int gamesWon= 0;
  int gamesLost = 0;
  Deck myDeck;

  // Welcomes the player and gives them the menu until they make a valid choice
  cout << "Welcome to Fibonacci Solitare!" <<endl;
  while(running == true && choice != 6)
    {
      cout << "\n1) Create New Deck \n2) Shuffle Deck \n3) Display Deck \n4) Play Fibo Solitare \n5) Win Fibo Solitare \n6) Exit\n" << endl;
      cin >> choice;
      cout << endl;
      // Resets deck
      if (choice == 1)
      {
        myDeck.resetDeck();
        cout << "New deck created!" << endl;
      }
      // Shuffles deck
      else if (choice == 2)
      {
        myDeck.shuffle();
        cout << "Deck shuffled!" << endl;
      }
      // Displays deck
      else if (choice == 3)
      {
        cout << "Your deck: " << endl;
        myDeck.show();
      }
      // Plays a single game of fibo solitaire
      else if (choice == 4)
      {
        int sum = 0;
        int piles = 0;
        int value;
        Card top;

        cout << "Playing Fibonacci Solitaire!!!" << endl;

        // Plays the game until the deck is empty
        while (myDeck.isEmpty() == false)
          {
            top = myDeck.deal();
            top.show();
            cout << ", ";

            value = top.getValue();
            sum += value;
            // If the sum is a fibo number, a new pile is created
            if (sum == 1 || sum == 3 || sum == 5 || sum == 8 || sum == 13 || sum == 21 || sum == 34 || sum == 55 || sum == 89 || sum == 144 || sum == 223 || sum == 377)
            {
              piles += 1;
              cout << "Fibo: " << sum << endl;
              sum = 0;
            }
          }
        games++;
        // If the deck is empty, the player wins
        if (sum == 0)
              {
                cout << "Winner in " << piles << " piles!" << endl;
                gamesWon++;
              }
        // If the deck is not empty, the player loses
        else
        {
          cout << "Last Pile NOT Fibo: " << sum << "\n\nLooser in " << piles << " piles!" << endl;
          gamesLost++;
        }
        // Talleys the games played and resets the deck, returning the player to the menu
        cout << "\nGame wins: " << gamesWon << "\nGames losses: " << gamesLost << "\nTotal games played: " << games << endl;
        
        myDeck.resetDeck();
        myDeck.shuffle();
      }
      // Plays the game until the player wins
      else if (choice == 5)
      {
        
        bool loose = true;

        cout << "Playing Fibonacci Solitaire!!!" << endl;
        // Plays the game until the player wins
        while (loose == true)
          {

            int sum = 0;
            int piles = 0;
            int value = 0;
            Card top;
            // Plays the game until the deck is empty
            while (myDeck.isEmpty() == false)
              {
                top = myDeck.deal();
                top.show();
                cout << ", ";

                value = top.getValue();
                sum += value;
                // If the sum is a fibo number, a new pile is created
                if (sum == 1 || sum == 3 || sum == 5 || sum == 8 || sum == 13 || sum == 21 || sum == 34 || sum == 55 || sum == 89 || sum == 144 || sum == 223|| sum == 377)
                {
                  piles += 1;
                  cout << "Fibo: " << sum << endl;
                  sum = 0;
                } 
              }
            games++;
            // If the deck is empty, the player wins
            if (sum == 0)
              {
                cout << "\nWinner in " << piles << " piles!" << endl;
                gamesWon++;
                loose = false;
              }
            // If the deck is not empty, the player loses
            else
            {
              cout << "Last Pile NOT Fibo: " << sum << "\n\nLooser in " << piles << " piles!\n" << endl;
              gamesLost++;
            } 
            // Talleys the games played and resets the deck, returning the player to the menu
            myDeck.resetDeck();
            myDeck.shuffle();
          }
        cout << "\nGame wins: " << gamesWon << "\nGames losses: " << gamesLost << "\nTotal games played: " << games << endl;
        
      }
    }
}