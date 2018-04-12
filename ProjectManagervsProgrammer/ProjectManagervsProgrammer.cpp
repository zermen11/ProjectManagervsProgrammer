// ProjectManagervsProgrammer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameMenu.h"
#include "GameField.h"
#include "Player.h"


int main()
{
	vector<Player*> select;
	GameMenu Menu;
	Player *Players = new Player();
	GameField *Field = new GameField(Players);
	bool set_ev = false;
	Menu.init();
	Menu.menu_cek();
	while (Menu.getStop()) {
		Menu.menu_init();
		Menu.menu_display();
		Menu.menu_event();
		if(Menu.getPlay()){
			Menu.play_menu();
			if (Menu.getBegin()) {
				Field->Proses();
				Field->Display();
				Field->Mouse_drag();
				Field->set_Times(Menu.getTime());
				cout << Field->get_Times()<<endl;
			}
			else {
				if(!set_ev){
				Field->Init(Field->get_Level());
				Field->set_ev(Menu.get_ev());
				Field->set_queue(Menu.get_queue());
				set_ev = true;
				}

			}
		}
		else if(Menu.getLoad()){
			Menu.load_menu();
		}
		else if(Menu.getCredit()) {
			Menu.credit_menu();
		}
		else if(Menu.getQuit()) {
			Menu.quit_menu();
		}
		al_flip_display();
	}
	Menu.menu_destroy();
}