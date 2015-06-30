/*
 * War.h
 *
 *  Created on: Mar 20, 2015
 *      Author: jdesroches
 */

#ifndef WAR_H_
#define WAR_H_
#include "IntArrayShuffle.h"
#include "Card.h"


/**
 * Main Game class, allows user to play a card game of War with the computer
 * @class War
 */
class War {
	public:
		War(){
			// Notify App has started
			std::cout<<"Starting War"<<std::endl;
			BuildDeck();
			std::cout<<"Built Deck"<<std::endl;


			DealDeck();
		};
		virtual ~War(){
			// Notify App has now ended
			std::cout<<"Exiting War";
		};
	private:
		Card Deck[52];
		Card* PlayerDeck;
		Card* CPUDeck;
		int count();
		void BuildSuite();

		/**
		 * Builds the starting Deck
		 * @method BuildDeck
		 */
		void BuildDeck(){
			// define suite names
			char *s[] = {
					"hearts",
					"diamonds",
					"spades",
					"clubs"
			};

			// loop through suites and compile suite set
			for(int i = 0; i < countCharArray(s); i++){
				BuildSuite(s[i]);
			}

		}

		/**
		 * Return the array count of an array of character arrays
		 * @method countCharArray
		 * @param {char*} arr[]
		 */
		template<int N>
		int countCharArray(char* (&arr)[N])
		{
			return N;
		}

		/**
		 * Return the array count of an array of cards
		 * @method countCharArray
		 * @param {char*} arr[]
		 */
		template<int N>
		int countCardArray(Card (&arr)[N])
		{
			return N;
		}


		/**
		 * Build the card set for a suite
		 * @method BuildSuite
		 * @param {char[]} suite
		 */
		void BuildSuite(char* suite){
			int SuiteSize = 13;
			int cur;

			for(int i = 0; i < SuiteSize; i++){
				// create card to be inserted into the deck
				Card newCard;
				newCard.suite = suite;
				newCard.value = i;
				newCard.charValue = CardCharValue[i];

				// pass card into deck
				this->Deck[cur] = newCard;
				cur++;

			}
		}

		/**
		 * Shuffles the deck
		 * @method ShuffleDeck
		 */
		void DealDeck(){
			// shuffle the deck int values
			int card[countCardArray(this->Deck)];
			for(int i = 0; i < countCardArray(this->Deck); i++){
				card[i] = i;
			}
			IntArrayShuffle::randomize(card);

			int num = 0;
			// deal cards to player and CPU
			for(int i = 0; i < countCardArray(this->Deck); i++){
				this->PlayerDeck[i] = this->Deck[num];
				this->CPUDeck[i] = this->Deck[num+1];


				// temporarily spew results
				std::cout<<"Player's Deck"<<std::endl;
				std::cout<<this->PlayerDeck[i].charValue
										<<" of "<<this->PlayerDeck[i].suite
										<<"="<<this->PlayerDeck[i].value
										<<std::endl;

				std::cout<<"CPU's Deck"<<std::endl;
				std::cout<<this->CPUDeck[i].charValue
										<<" of "<<this->CPUDeck[i].suite
										<<"="<<this->CPUDeck[i].value
										<<std::endl;
				num = num + 2;
			}
		}

};


#endif /* WAR_H_ */
