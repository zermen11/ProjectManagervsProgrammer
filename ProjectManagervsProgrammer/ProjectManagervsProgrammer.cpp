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
	bool level[6] = { true ,false ,false ,false ,false ,false };
	Menu.init();
	Menu.menu_cek();
	leveling:
	while (Menu.getStop()) {
		Menu.menu_init();
		Menu.menu_display();
		Menu.menu_event();
		if(Menu.getPlay()){
			Menu.play_menu();
			if (Menu.getBegin()) {
				if (level[0]) {
					Field->Init(Field->get_Level());
					level[0]= false;
				}
				else if(level[1]) {
					Field->Init(Field->get_Level());
					level[1] = false;
				}
				else if (level[2]) {
					Field->Init(Field->get_Level());
					level[2] = false;
				}
				else if (level[3]) {
					Field->Init(Field->get_Level());
					level[3] = false;
				}
				else if (level[4]) {
					Field->Init(Field->get_Level());
					level[4] = false;
				}
				else if (level[5]) {
					Field->Init(Field->get_Level());
					level[5] = false;
				}
				Field->Proses();
				Field->Display();
				Field->Mouse_drag();
				Field->set_Times(Menu.getTime());
				cout << Field->get_Times()<<endl;
			}
			else {
				if(!set_ev){
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