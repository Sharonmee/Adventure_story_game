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

    void show_gold(){

        cout<<"You currently have 20 gold pieces in your purse"<<endl;
    }

    void lose_playerhealth(int n){
        health -=n;
    }

    void add_inventory(string item){
        inventory.push_back(item);
    }



};


class Location{

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
Location tavern("The Thirsty Ferret","A very basic hostelry with straw on the floors.\nSeveral of the patrons are either highly inebriated, unconcious or fighting.\nThe ale seems reasonable and fairly priced.....\n",{ "1) Drink ale!",  "2) Go on adventure!\n" });
Location crossroads("Crossroads","Leaving town by the footpath, the well worn trail splits into three lesser travelled paths.\n" ,{ "1) Visit the Undercrypt", "2) Enter the Maw of the Beast", "3) Investigate the Needletoe Caverns", "4) Return to safety\n" });
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

bool player_status;

void main_game(){

    player_status = greeting();
    

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
     cout<<"A tough looking guy comes to sit on your table and you become friends,he tells you about a certain merchant where you could buy swords,charms and gold pieces from.Since you on a quest to steal the dragon's tooth you consider his suggestion."<<endl;
     cout<<"You decide to head to the outskirts of the town to see this merchant"<<endl;
     current_location = merchant;
     current_location.show_location();
     current_location.give_description();
     current_location.show_options();
     player_status= choices();
     return true;

     case 2:
     cout<<"You've been really bored of late so you don't have appetite for ale. You decide to immediately begin an adventure to the lost land of Bale where you plan on retrieving the dragon's tooth worth 2000 could coins"<<endl;
     player.show_gold();
     player.show_inventory();
     cout<<"1)Will you immediately head towards the dragon's lair or 2)you would buy more stuff"


    }

    

}


}