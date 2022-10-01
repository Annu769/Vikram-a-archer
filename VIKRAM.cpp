#include <iostream>
using namespace std;




class player
{



  private:

  int health = 100;
  int minDamage = 20;
  int maxDamage = 30;
  int minHealing = 13;
  int maxHealing= 18;



  public:
  player()
{
  cout<<"\nHi my name is vikram! we need to save owr citizen from the king"<<endl;
  cout<<"Here are some stats that might be usefu for you going ahead "<<endl;
  cout<<"\nVikram's Health:"<<health;\
  cout<<"\n_____________________________________\n";
  cout<<"\n vikram's Attack Rage between: "<<minDamage<<"-"<<maxDamage<<".";
  cout<<"\n_____________________________________\n";
  cout<<"\n vikram's Heal Rage between: "<<minHealing<<"-"<<maxHealing<<"."<<endl;
  cout<<"\n_____________________________________\n";
}

int getHealth()
{
 return health;
}
void takeDamage(int damage)
{
  
  
     cout<<"Oh NO , A critical Arrow hit to Vikram"<< endl;
  cout<<"\n";
    cout<<"Aurangzeb dealing damage of "<<damage<<" To the vikram! "<<endl;
      health = health - damage;
    if(health > 0){
      cout<<"\n";
    cout<<"Vikram current Health after reciving damage "<<health<<endl;
      }
    
  else
  {
    cout<<"\n";
     cout<<" Our Vikram is Died.....:) You Lost " <<endl;
  }
}
int giveDamage()
{
  
srand(time(0));
  int randomDamage = (rand() % (maxDamage - minDamage + 1 ) + minDamage);
 return randomDamage;
}
void Heal()
{
  srand(time(0));
  int randomHeal = (rand() % (maxHealing - minHealing + 1 ) + minHealing);
  
  health = health + randomHeal;
  cout<<"\n";
  cout<<" Vikram Healed with HP of "<<randomHeal<<endl;
  cout<<"\n";
  cout<<" Vikram's Health after Healing "<<health<<endl;
  
}



};
class Enemy
{
private:



int health = 100;
  int minDamage = 15;
  int maxDamage = 25;


public:
  Enemy()
  {
    cout<<"Aurangzeb"<<endl;
    cout<<" HA HA HA... I am the King of This Kingdom You Can't Kill Me Vikram "<<endl;
    cout<<"__________________________________"<<endl;
    
  }
  int getHealth()
  {
   return health;
  }
  void takeDamage(int damage)
  {
   
   
       cout<<"A Heavy Arrow hit to Aurangzeb "<< endl;
    cout<<"\n";
    cout<<"Vikram dealing damage of "<<damage<<"To the Aurangzeb! "<<endl;
  health = health - damage;
    cout<<"\n";
    
      
   if(health > 0)
     {
       
     cout<<" Aurangzeb current Health after reciving damage "<<health<<endl;
       cout<<"\n";
     }
   
    else
    {
     
        cout<<"Aurangzeb is Died.. You Won " <<endl;
      cout<<"\n";
    }
  }
    int giveDamage()
    {
  
    srand(time(0));
      int randomDamage = (rand() % (maxDamage - minDamage + 1 ) + minDamage);
       
      return randomDamage;
    }
};




void gameStory()
{ 
  system("clear");
  cout<<"________________________"<<endl;
  cout<<" Vikram : A Archer  "<<endl;
  cout<<"_______________________"<<endl;
  cout<<"Once upon a time there was a village named Prithvipur, there was a king of that village, whose name was Aurangzeb, who used to keep his subjects in a very sad and cruel way, "<<endl;
  cout<<"_______________________"<<endl;
  cout<<" In the same village there lived a 19 year old boy named Vikram. Vikram was a very good archer, wanted to punish the king for his crimes, so let's see how Vikram punishes him."<<endl;
  cout<<"_______________________"<<endl;
}


void battleLoop(player player,Enemy enemy)
{
  char playerChoice;
  do
    {
      cout<<"\n";
      cout<<"Press 'A' TO Attack And Press 'H' TO Heal"<<endl;
      cin>>playerChoice;
      if(playerChoice == 'a' || playerChoice == 'A')
      {
        system("clear");
         enemy.takeDamage(player.giveDamage());

        if(enemy.getHealth() > 0)
        {cout<<"\n";
          cout<<"HA HAHA HA HA, Vikram You Are To Weak Its My Turn Now "<<endl;
          player.takeDamage(enemy.giveDamage());
          
        }
      }
      else if (playerChoice == 'h' || playerChoice == 'H')
      {
        system("clear");
       player.Heal();

         if(enemy.getHealth() > 0)
        {cout<<"\n";
          cout<<"HA HAHA HA HA, Vikram You Are To Weak Its My Turn Now "<<endl;
          player.takeDamage(enemy.giveDamage());
          }
      
      }
      else
        {
          system("clear");
        cout<<"Invalid Input"<<endl;
        }
    }while(player.getHealth() > 0 && enemy.getHealth() > 0);
}


int main() 
{
  gameStory();
  char userInput;
  do
    {
      cout<<"Press S to start game press any key to exit "<<endl;
      cin>>userInput;
     if(userInput =='S' || userInput == 's')
     {
       player playerObj;
       Enemy enemyObj;
       battleLoop(playerObj, enemyObj);
      
       
       
     }
      else
     {
       cout<< "Thanks for playing 'VIKRAM A ARCHER'"<<endl; 
      }
    }while(userInput =='S' || userInput == 's');
   
  
  
  return 0;
}