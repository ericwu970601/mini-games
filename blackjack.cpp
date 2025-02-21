/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int getCard() {
    int card = rand() % 13 + 1;
    return (card > 10) ? 10 : card;
}

int getHandValue(const vector<int>& hand) {
    int total = 0, aces = 0;
    for (int card : hand) {
        total += card;
        if (card == 1) aces++;
    }
    while (aces > 0 && total + 10 <= 21) {
        total += 10;
        aces--;
    }
    return total;
}

void printHand(const vector<int>& hand, bool hideFirstCard = false) {
    for (size_t i = 0; i < hand.size(); ++i) {
        if (i == 0 && hideFirstCard) {
            cout << "[Hidden] ";
        } else {
            cout << "[" << hand[i] << "] ";
        }
    }
    cout << endl;
}

int main() {
    srand(time(0));
    vector<int> playerHand, dealerHand;
    playerHand.push_back(getCard());
    playerHand.push_back(getCard());
    dealerHand.push_back(getCard());
    dealerHand.push_back(getCard());

    cout << "Welcome to Blackjack!" << endl;
    int playercardcount=2;
    int dealercardcount=2;
    while (true) {
        cout << "\nYour hand: ";
        printHand(playerHand);
        cout << "Dealer's hand: ";
        printHand(dealerHand, true);

        int playerTotal = getHandValue(playerHand);
        if (playerTotal > 21) {
            cout << "Bust! You lose." << endl;
            break;
        }

        cout << "Hit or Stand? (h/s): ";
        char choice;
        cin >> choice;

        if (choice == 'h') {
            playerHand.push_back(getCard());
            playercardcount+=1;
        } else {
            break;
        }
    }

    int playerTotal = getHandValue(playerHand);
    if (playerTotal <= 21) {
        while (getHandValue(dealerHand) < 17) {
            dealerHand.push_back(getCard());
            dealercardcount+=1;
        }

        int dealerTotal = getHandValue(dealerHand);
        cout << "\nDealer's hand: ";
        printHand(dealerHand);

        if (dealerTotal > 21 || playerTotal > dealerTotal||playercardcount>=5) {
            cout << "You win!" << endl;
        } else if (playerTotal < dealerTotal||dealercardcount>=5) {
            cout << "Dealer wins." << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
    }
    cout<<playercardcount;
    return 0;
}
