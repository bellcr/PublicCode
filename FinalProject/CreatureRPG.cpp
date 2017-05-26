#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;

class Creature {//Definition of the base human class
	private:
		int strength;
		int hitpoints;
	public:
		Creature();
		Creature (int, int);
		int getStrength();//accessors for creatures health and strength
		void setStrength(int);
		int getHitpoints();
		void setHitpoints(int);
		virtual int getDamage();//set up all virtual methods for child classes so polymorphism will call the correct one
		virtual string getSpecies();
};

//base constructors to set the health and strength of a creature
Creature::Creature() {
	strength=10;
	hitpoints=10;
}

Creature::Creature(int s, int h) {
	strength=s;
	hitpoints=h;
}


//accessor methods for private data
int Creature::getStrength() {
	return strength;
}

void Creature::setStrength(int s) {
	strength=s;
}

int Creature::getHitpoints() {
	return hitpoints;
}

void Creature::setHitpoints(int h) {
	hitpoints=h;
}

//default creature damage, rolls a random damage within the strength range
int Creature::getDamage() {
	int damage;
	damage=(rand()%strength)+1;
	cout<<getSpecies()<<" attacks for "<<damage<<" points!"<<endl;
	return damage;
}


string Creature::getSpecies() {
	return "Unknown";
}

//the human class is a child of creature
class Human:public Creature {
	private:
	public:
		Human();
		Human(int, int);
		string getSpecies();
};

//human constructor calls the creature constructor
Human::Human():Creature() {

}

Human::Human(int s, int h):Creature(s, h) {

}

//sets species name as that is the only difference between the human and creature object
string Human::getSpecies() {
	return "Human";
}
//Humans have the default creature damage so there is no getDamage()

//the demon class is a child of creature
class Demon:public Creature {
	private:
	public:
		Demon();
		Demon(int, int);
		string getSpecies();
		int getDamage();
};

//demon constructors call creature constructor
Demon::Demon():Creature() {

}

Demon::Demon(int s, int h):Creature(s, h) {
}

//set demon species name
string Demon::getSpecies() {
	return "Demon";
}

//call creature get damage
int Demon::getDamage() {
	int damage=Creature::getDamage();
	if((rand()%100)<5) {//there is a 5% chance of a 50 damage hit from a demon
		damage=damage+50;
		cout<<"Demonic attack inflicts 50 additional damage points!"<<endl;
	}
	return damage;
}

//the elf class is a child of creature
class Elf: public Creature {
	private:
	public:
		Elf();
		Elf(int, int);
		string getSpecies();
		int getDamage();
};

//constructors call creature constructors
Elf::Elf():Creature() {

}

Elf::Elf(int s, int h):Creature(s, h) {

}

//set species
string Elf::getSpecies() {
	return "Elf";
}

//call creature damage
int Elf::getDamage() {
	int damage=Creature::getDamage();
	if((rand()%10)==0) {//elves have a 10% chance of double damage
		cout<<"Magical attack inflicts "<<damage<<" additional damage points!"<<endl;
		damage=damage*2;
	}
	return damage;
}


//cyberdemon is a child of demon
class Cyberdemon: public Demon {
	private:
	public:
		Cyberdemon();
		Cyberdemon(int, int);
		string getSpecies();
};

//cyberdemon calls the demon constructors
Cyberdemon::Cyberdemon():Demon() {

}

Cyberdemon::Cyberdemon(int s, int h):Demon(s, h) {

}

//set species
string Cyberdemon::getSpecies() {
	return "Cyberdemon";
}
//there is no getDamage() because the cyber demon has no additional effects over a demon

//balrogs are also children of demons
class Balrog: public Demon {
	private:
	public:
		Balrog();
		Balrog(int, int);
		string getSpecies();
		int getDamage();
};

//balrog constructors call demon constructors
Balrog::Balrog():Demon() {

}

Balrog::Balrog(int s, int h):Demon(s, h) {

}

//set species
string Balrog::getSpecies() {
	return "Balrog";
}

//balrog calls demon damage, allowing balrogs the 5% 50 damage boost
int Balrog::getDamage() {
	int damage=Demon::getDamage();
	cout<<"Balrog speed attack!"<<endl;
	int damage2=Demon::getDamage();//balrogs always attack twice, with a different damage roll
	return damage+damage2;
}

//CUSTOM CLASS
//dark elf is a child of elf
class DarkElf:public Elf {
	private:
	public:
		DarkElf();
		DarkElf(int, int);
		string getSpecies();
		int getDamage();
};

//dark elf calls elf constructors
DarkElf::DarkElf():Elf() {

}

DarkElf::DarkElf(int s, int h):Elf(s, h) {

}

//set species
string DarkElf::getSpecies() {
	return "Dark Elf";
}


int DarkElf::getDamage() {
	int damage;
	if(((rand()%100)<20)&&getHitpoints()>10) {//the dark elf has a 20% at over 10 health to perform a dark magic attack instead of a normal attack
		damage=getHitpoints()/4;//the damage of dark magic is a quarter of the dark elfs current health
		setHitpoints(getHitpoints()-10);//but the dark magic attack costs the dark elf 10 health
		cout<<"Dark Elf uses a dark magic attack!"<<endl;
		cout<<"The attack deals "<<damage<<" damage, and the Elf deals 10 to itself."<<endl;
	} else {//the dark elf normal attack is the elf attack with 10% chance of double damage
		damage=Elf::getDamage();
	}
	return damage;
}

//prototypes for non object related methods
void battleArena(Creature*, Creature*);
void approachPhrase(int);

int main() {
	//setting up the random seed, done once in the program run
	unsigned int seed=time(NULL);
	srand(seed);
	
	
	int classChoice;
	//intro display allowing class selection, each class has a description about the differences of the classes
	cout<<"Welcome to Charles' text RPG"<<endl;
	cout<<"Choose a class:"<<endl;
	cout<<"\t(1)Human: High base stats in exchange for no special attacks."<<endl;
	cout<<"\t(2)Cyberdemon: Low health, average power, with a 5% chance for a huge demonic attack."<<endl;
	cout<<"\t(3)Balrog: High health, low power, with a guaranteed double attack, and a 5% chance for a huge demonic attack."<<endl;
	cout<<"\t(4)Elf: Low health, high power, with a 10% chance for a double damage magic attack"<<endl;
	cout<<"\t(5)Dark Elf: Average health, average power, with a 20% chance for a huge dark magic attack, and a 10% chance for a double magic attack"<<endl;
	cin>>classChoice;
	
	//hero is created as a pointer so that it can access all needed methods from creature as well as any specific methods
	Creature* Hero;
	
	//based on user class choice the hero is created with different base stats to balance out special attacks
	if(classChoice==1) {
		cout<<"A human, how quaint, do you think a human can face the trials?"<<endl;
		Hero=new Human(15, 150);
	} else if(classChoice==2) {
		cout<<"Cyberdemon, created for battle, and to be discarded, can a cyberdemon outlast the trials?"<<endl;
		Hero=new Cyberdemon(10, 50);
	} else if(classChoice==3) {
		cout<<"A Balrog, a brute, do you think you can force your way through the trials?"<<endl;
		Hero=new Balrog(5, 150);
	} else if(classChoice==4) {
		cout<<"A noble Elf, the race that prefers peace, can elegance prevail in the trials?"<<endl;
		Hero=new Elf(15, 50);
	} else if(classChoice==5) {
		cout<<"An outcast dark elf, dark magic comes with a price, can this price beat the trials?"<<endl;
		Hero=new DarkElf(10, 100);
	}

	//scale and level are integers that are vital to the progress of the rpg
	int scale=50;//scale will affect how tough enemy creatures are
	int levels=1;//levels is a measure of progress and at checkpoints the scale will change
	int door1, door2, door3;
	int chosenDoor;
	
	while(Hero->getHitpoints()>0) {//until the hero dies, the loop will continue

		if(scale<=0)//because of the scale math the scale can go negative so we always set it one
			scale=1;
			
		//level intro
		cout<<"Level "<<levels<<endl;
		
		//set up the values of each door
		//in each level one door will have an item, one will have an enemy and one nothing
		//the doors are determined before user selection to guarantee there is one of each
		int value=rand()%3;
		door1=value;
		while(value==door1) {
			value=rand()%3;
		}
		door2=value;
		while(value==door1||value==door3) {
			value=rand()%3;
		}
		door3=value;
		
		//the user then is asked to choose a door
		cout<<"You approach 3 doors, the trials say you must enter one of them, choose carefully(enter '1', '2', or '3'):";
		cin>>chosenDoor;
		
		//the value of the door is passed back to the re-used variable value
		if(chosenDoor==1)
			value=door1;
		if(chosenDoor==2)
			value=door2;
		if(chosenDoor==3)
			value=door3;
			
		//call a random approach phrase
		approachPhrase(rand()%5);
		
		//if the value of the door is 0 we find a creature
		if(value==0) {
			cout<<"A creature readies for battle behind the door!"<<endl;
			Creature * creatures[5];//an array of 5 creatures, one of each species is created 
			creatures[0]=new Human(150/scale, 1500/scale);//then a pointer for each species is created, the initial strength and hitpoint valuess
			creatures[1]=new Cyberdemon(100/scale, 500/scale);//are determined based off the user defaults and then scaled to the current level
			creatures[2]=new Balrog(50/scale, 1500/scale);
			creatures[3]=new Elf(150/scale, 500/scale);
			creatures[4]=new DarkElf(100/scale, 1000/scale);
			int creature=rand()%5;//a random creature is then chosen from the array
			cout<<"A "<<creatures[creature]->getSpecies()<<" attacks you"<<endl
			;
			battleArena(Hero, creatures[creature]);//battleArena() runs a battle simulation until a combatant is defeated
		}
		//if the door value is 1 then the user gets an item
		if(value==1) {
			cout<<"You find an item! Your luck may be turning"<<endl;
			if(rand()%2==0) {//there is a 50% chance of a strength increase and a 50% chance of health increase
				cout<<"A weapon upgrade, you fear the increasing power of the creatures ahead, and hope this will help."<<endl;
				Hero->setStrength(Hero->getStrength()+(rand()%(100/scale)+1));//the strength increase is also scaled with level, this is to prevent an early spike in power
			} else {
				cout<<"Armor, you hope you don't have to take another hit, but if you do this will help."<<endl;
				Hero->setHitpoints(Hero->getHitpoints()+(rand()%(750/scale)+1));//the health increase is scaled with level, again to prevent an early spike in power
			}
		}
		//a value of 2 means nothing happens
		if(value==2) {
			cout<<"The door held nothing, another level passed"<<endl;
		}
		
		//a check to see if the hero has survived the level
		if(Hero->getHitpoints()>0) {
			//the level counter is increased
			levels++;
			//every 5 levels the power levels of enemies scales
			if(levels%5==0) {
				scale-=3;
				//in case the user has avoided all the item doors they are given an extra power boost, once again it scales with the game
				cout<<"The creatures are getting tougher!"<<endl;
				cout<<"The Gods look kindly on someone who has made it this far in the trials and bestow you a new found strength."<<endl;
				cout<<"Your hitpoints and strength both increase"<<endl;
				Hero->setHitpoints(Hero->getHitpoints()+100/scale+1);
				Hero->setStrength(Hero->getStrength()+15/scale+1);
			}
			//level conclusion output to display hero current health and power
			cout<<"You survived the level. Current health: "<<Hero->getHitpoints()<<" Current Strength: "<<Hero->getStrength()<<endl;

		}
		cout<<"***********************************************************************************"<<endl;
	}
	
	//This is reached once the hero runs out of hitpoits, Displays total number of levels passed
	cout<<"The trials have ended. You survived "<<levels<<" levels";
}

//approachPhrase adds a little line after door selection
void approachPhrase(int x) {
	if(x==1)//the int passed in is between 1-5 and will generate one of these phrases, they are unrelated to what is actually behind the door
		cout<<"You think you hear a noise on the other side of the door"<<endl<<endl;
	if(x==2)
		cout<<"A definite cry is heard up ahead"<<endl<<endl;
	if(x==3)
		cout<<"A glow of light appears around the door as you approach"<<endl<<endl;
	if(x==4)
		cout<<"You feel a dark presence come over you as you make your choice"<<endl<<endl;
	if(x==5)
		cout<<"Silence, too silent for the trials"<<endl<<endl;
}


//battleArena() determines fights between creatures
void battleArena(Creature* A, Creature* B) {//pointers must be used because any type of creature could be passed
	while(A->getHitpoints()>0&&B->getHitpoints()>0) {//the loop continues until one or both creatures dies
	
		//round health display for the user to keep track of the current status of the fight
		cout<<A->getSpecies()<<" Health: "<<A->getHitpoints()<<endl;
		cout<<B->getSpecies()<<" Health: "<<B->getHitpoints()<<endl;
		
		//Creature A attacks B first, both creatures will attack even if B would die on the first hit
		B->setHitpoints(B->getHitpoints()-A->getDamage());
		A->setHitpoints(A->getHitpoints()-B->getDamage());

		cout<<"-----------------------------------------------------------"<<endl;
	}
}
