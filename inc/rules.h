#ifndef STANDARD_H
#define STANDARD_H

/* Interface for traditional Durak rules */

// Lists are terminated with NULL to have "portable" bound checking
// according to this post: http://stackoverflow.com/a/13583763

// List of suits used
const char *listSuit[] = {"Hearts","Tiles","Clubs","Spades",NULL};

// List of ranks used, in order of value
const char *listRank[] = {"6","7","8","9","10","J","Q","K","A",NULL};

#define HAND_SIZE 6


/* GAME FUNCTIONS AND RULES */

// Create playing deck using rank and suit lists
// NOTE: Automatically shuffles and finds a trump suit
// by uncovering the card at the bottom.
int deckCreate(stackT *deckP, char **listSuit, char **listRank);

// Hand cards to players in party Order until HAND_SIZE is reached for each player
// Reduce stack size on the way
int handCards(partyT *partyP, stackT *stackP, int sizeHand);

// Determine if card `a` beats card `b` using trump suit from the deck
int cardBeats(cardT *aP, cardT *bP, stackT *deckP);

// Determine if a chosen card can be added to the table for the defender to beat
int cardFits(cardT *cardP, tableT *tableP);

// Determine if game has ended
// Check if deck is empty && 1 or no player has cards on his hands
int gameEnded(partyT *partyP, stackT *deckP);

/* TODO: Add more functions for rule-checking */


#endif // STANDARD_H
