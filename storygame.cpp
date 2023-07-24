#include <iostream>
using namespace std;
#include <vector>
#include <string>


class Player{
    string name;
    int gold;
    int health = 100;
    vector<string>inventory;
    
    public:
    Player(){
        inventory = {"backpack","knife"};
        health = 100;

    }

    void player_name(){
        cout<<"Enter your name"<<endl;
        cin>>name;
        cout<<"Are you ready"<<name<<"?. Let's start"<<endl;    
        }

    void show_inventory(){
        cout<<"Here are the things you have"<<endl;
        for(string inventories: inventory){
            cout<<inventories<<endl;
        }
    }

    void player_details(){
        cout<<name<<endl;
        cout<<gold<<endl;
        cout<<health<<endl;
    
    }

    void lose_gold(int n){
        gold -=n;
        
    }

    void lose_playerhealth(int n){
        health -=n;
    }

    void add_inventory(string item){
        inventory.push_back(item);
    }



};


class Location:{

    string location_name;
    string description;
    vector<string>options;

    public:
    Location(string na,string des,vector<string> opt){
        location_name = na;
        description = des;
        options = opt;

    }

    string show_location(){
        cout<<"You are currently at"<<endl;
        return location_name;
    }


    void give_description(){
        cout<<description<<endl;
    }

    void show_options(){
        cout<<"which option will you take"<<endl;
      for(string option:options){
        cout<<option<<endl;
      }
    }

    
};


//ANOTHER PART OF THE GAME WHICH I WILL PROBABLY INVCLUDE IN ANOTHER FILE

Player player;

Location Market_place("Market place","You are hungry so you go to the market place to buy food",{"1)You give your money out to some beggers on the street","2)You steal the food and run away","3)You some nice looking apples and buy some","4)Nothin looks appetizing so you leave"});
Location merchant("Cloaks and Daggers","The merchant here sells simple weapons and tools.\nNothing too fancy but the quality is good.\n",{ "1) Buy Thieves Tools (1gp)", "2) Buy Sword (4gp)", "3) Visit the Tavern", "4) Go on adventure!\n" });
Location tavern("The Thirsty Ferret","A very basic hostelry with straw on the floors.\nSeveral of the patrons are either highly inebriated, unconcious or fighting.\nThe ale seems reasonable and fairly priced.....\n",{ "1) Drink ale!", "2) Ask around for rumours", "3) Visit the Merchant", "4) Go on adventure!\n" });
Location crossroads("Crossroads","Leaving town by the footpath, the well worn trail splits into three lesser travelled paths.\n" ,{ "1) Visit the Undercrypt", "2) Enter the Maw of the Beast", "3) Investigate the Needletoe Caverns", "4) Return to safety\n" });
Location undercrypt("Undercrypt","As you descend into the darkness of the crypt, you see a ghastly spectral visage floating towards you. As it nears, it emits a terrifying wail.\n",{ "1) Fight the banshee", "2) Run away\n" });
Location needletoe_caverns("Needletoe Caverns", "Picking your way through the tumbledown rockfalls of the cavern, you are set upon by a pack of snarling goblins, with vicious, long razor sharp finger and toe nails.\n", { "1) Fight the goblins", "2) Run away\n" });
Location maw_unknown("Maw", "You step through a cavern of tooth like stalactites into a short tunnel, at the end of which are two shimmering portals.\n", { "1) Step through the left portal", "2) Step through the right portal", "3) Search the area", "4) Return to safety\n" });
Location maw_trapped("Maw Tunnel",  "You notice a small device embedded in the cavern wall, projecting a magical field across the tunnel between you and the two portals. There are piles of ash on the floor.\n",{ "1) Ignore the device and step through the left portal", "2) Ignore the device and step through the right portal", "3) Attempt to deactivate the device", "4) Return to safety\n"});
Location maw_clear("Maw Tunnel - Disintegration device deactivated!","The device has been deactivated. Two shimmering portals stand before you.\n",{ "1) Step through the left portal", "2) Step through the right portal", "3) Return to safety\n" });
Location dragon_lair("Dragons' Lair","A huge winged beast sits atop a pile of treasure. As you step through the portal, it opens its fanged mouth. Molten lava drips from its' jaw.\nIt booms, 'You dare interrupt my slumber?'\n\n",{ "1) Fight the dragon", "2) Flee in terror\n" });
//set starting location


Location current_location = tavern;

bool greeting(){
    cout<<"***************************WELCOME TO THIRSTY FERRET*******************************8"<<endl;
    cout<<"&&&&&&&&&&&&&&&&&&THIS IS WHERE ADVENTURE IS JUST A PINT AWAY&&&&&&&&&&&&&&&&"<<endl;
    cout<<endl;
    cout<<"Drawn by tales of riches awaiting the bold, you have travelled to the village of Donbury"<<endl;
    cout<<"Tired from your journey, you make your way to the village hub: The Thirsty Ferret Inn"<<endl;
    cout<<"From any location, several choices will be available to you."<<endl;
    cout<<"You need simply select your choice with the corresponding number"<<endl;
    cout<<"You may also view your inventory at any time"<<endl;
    cout<<"Quit the game at any time by ______."<<endl;
    cout<<"Enter 'y' or 'Y' to start"<<endl;
    string user_option;
    cin>>user_option;
    if(user_option == "Y"|| "y"){
        return true;
    }else return false;


}

void main_game(){

    bool player_status = greeting();
    

    while(player_status == true){
        player.show_inventory();
        current_location.show_location();
        current_location.give_description();
        current_location.show_options();
        player_status= choices();




    }
    
}


bool choices(){

int decision;
cin>>decision;


if (current_location.show_location() =="The Thirsty Ferret"){
    switch(decision){

     case 1:
     cout<<"You have drunk the ale"<<endl;

    }
}


}