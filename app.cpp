#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

int main()
{
	LinkedList	list;
	artist *Eminem = new artist("Eminem", "September 26 – Eminem royalties shares to be sold in an IPO", "Rap");
	song *LoseYourSelf = new song("Lose Yourself", 5.23, 144309378, 654000);

	LinkedList::node *eminem = list.add(*Eminem);

	list.displayArtists();

	list.add(*LoseYourSelf, eminem);

	list.displayArtists();

	list.displaySongs(eminem);

	artist *Soken = new artist("Masayoshi Soken", "Take over FFXIV OST production role after Nobuo Uemastsu", "Written entire Shadowbringer soundtrack");

	song *Shadowbringers = new song("Shadowbringers", 6.24, 1456788979, 999999906);
	song *StormOfBlood = new song("Storm Of Blood", 3.58, 175678899, 899690);
	song *Triumph = new song("Triumph", 3.14, 199978879, 899688);
	song *Beauty = new song("Beauty's Wicked Wiles", 5.45, 256678879, 899000);

	LinkedList::node *soken = list.add(*Soken);

	list.displayArtists();

	list.add(*Shadowbringers, soken);
	list.add(*StormOfBlood, soken);
	list.add(*Triumph, soken);
	list.add(*Beauty, soken);

	list.displayArtists();

	list.displaySongs(soken);


	return 0;
}