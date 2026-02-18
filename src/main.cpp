    #define RESET   "\033[0m"
    #define BLACK   "\033[30m"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BLUE    "\033[34m"
    #define MAGENTA "\033[35m"
    #define CYAN    "\033[36m"
    #define WHITE   "\033[37m"
    #define ORANGE "\033[38;5;208m"
    #define LIGHT_BLUE "\033[38;5;117m"




//stuff for WINDOWS

// #include <iostream>
// // #include <windows.h>
// #include <cstdlib>
// #include <ctime>
// // #include <conio.h>
// #include <string>
//colour define
// Color constants
// for windows
// const int BLACK = 0;
// const int BLUE = 1;
// const int GREEN = 2;
// const int CYAN = 3;
// const int RED = 4;
// const int MAGENTA = 5;
// const int YELLOW = 6;
// const int WHITE = 7;


// libraries main
#include <SFML/Audio.hpp>

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

//FUNCTION PROROTYPES
void clearScreen();

void initializeBoard(char board[10][10]);

void instructions();

void checkcount(char board[10][10]);

int shipcolor();

void setColor(int textColor, int bgColor); 

void clearBoard (char board[10][10]);

void printBoard(char board[10][10], bool hideShips);

void shipplacement(char placer[10][10]);

void playerAttack(char opponentBoard[10][10], int &playerScore);

void vsPlayer(char board1[10][10], char board2[10][10]);

void setRandomShips (char board[10][10]);

void computerAttack(char opponentBoard[10][10], int &playerScore);

 void vsComputer(char board1[10][10], char board2[10][10]);

 void displayResult();

 void ABOUT();



//global scoped variables and arrays+flags

    //no of turns
       int player1count=6;
       int player2count=6;
       //score
        int   player1Score=0;
        int   player2Score=0;

        //flags for calc turns
        bool flag11=1;
         bool flag12=0;
         bool flag13=0;
         bool flag14=0;
         bool flag15=0;
         bool flag21=0;
         bool flag22=0;
         bool flag23=0;
         bool flag24=0;
         bool flag25=0;
         
         //index noter arrays
        int arr1[10][2];//player 1 ships indexes
        int arr2[10][2];//player 2sgips  indexes

        //main player arrays
            char player1grid[10][10]; //from placement to attack for player 1
            char player2grid[10][10];//from placement to attack for player 2

        // some variables for critical functions
             bool h=0;// sttack bool
             bool termte=1;//attack terminator

        //global flags for ship placement
             int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0; //flags for 5 ships in each case
        
        //variables of globak scope  for managing turns and score of each player
             int playercount=1;//players turn 1,2
    
         //variable for managign the colour of the ships
            int shipcolour; //valid for bath i.e overwrite

        //variable for managing the type of game mode
            int choice_player;//int either 2 or 1 for pvp or pvc

             
             

int main()
{
    clearScreen(); 
    
             sf::SoundBuffer buffer5;
             if(!(buffer5.loadFromFile("../assets/in.wav")))
             cout<<"EROOR loading in.wav\n";
             sf::Sound enter(buffer5);
   
   

    //sound buffering

    sf::SoundBuffer soundBuffer1;
    // 
    if (!soundBuffer1.loadFromFile("../assets/start.wav"))
    cout << "Error loading start.wav\n";
      sf::Sound start(soundBuffer1);

      
      sf::SoundBuffer soundBuffer2;

    if (!soundBuffer2.loadFromFile("../assets/middle.wav"))
    cout << "Error loading middle.wav\n";
 
    sf::Sound middle(soundBuffer2);

    { 
        string battleship =
        "       HHHHH   HHHHH    OOOOOOO    YY     YY  LL          EEEEEEEEE            BBBBBBBB      AAAAAA    TTTTTTTTT  TTTTTTTTT  LL          EEEEEEEEE    SSSSSSS    HHHHH   HHHHH  IIIIIII  PPPPPPPP   \n"
        "       HHHHH   HHHHH   OOOOOOOOO   YY     YY  LL          EEEEEEEEE            BBBBBBBBB    AAAAAAAA   TTTTTTTTT  TTTTTTTTT  LL          EEEEEEEEE   SSSSSSSSS   HHHHH   HHHHH  IIIIIII  PPPPPPPPP  \n"
        "       HHH       HHH  OOO     OOO   YY   YY   LL          EEE                  BBB    BBB  AAA    AAA     TTT        TTT     LL          EEE         SSS         HHH       HHH    III    PPP    PPP \n"
        "       HHH       HHH  OOO     OOO    YYYYY    LL          EEEEEEE              BBBBBBBB    AAAAAAAAAA     TTT        TTT     LL          EEEEEE       SSSSSSS    HHH       HHH    III    PPPPPPPPP  \n"
        "       HHHHHHHHHHHHH  OOO     OOO     YYY     LL          EEEEEEE              BBBBBBBB    AAAAAAAAAA     TTT        TTT     LL          EEEEEE        SSSSSSS   HHHHHHHHHHHHH    III    PPPPPPPP   \n"
        "       HHHHHHHHHHHHH  OOO     OOO     YYY     LL          EEE                  BBB    BBB  AAA    AAA     TTT        TTT     LL          EEE               SSS   HHHHHHHHHHHHH    III    PPP        \n"
        "       HHH       HHH  OOO     OOO     YYY     LL          EEE                  BBB    BBB  AAA    AAA     TTT        TTT     LL          EEE               SSS   HHH       HHH    III    PPP        \n"
        "       HHH       HHH   OOOOOOOOO      YYY     LLLLLLLLL   EEEEEEEEE            BBBBBBBBB   AAA    AAA     TTT        TTT     LLLLLLLLL   EEEEEEEEE   SSSSSSSSS   HHH       HHH  IIIIIII  PPP        \n"
        "       HHH       HHH    OOOOOOO       YYY     LLLLLLLLL   EEEEEEEEE            BBBBBBBB    AAA    AAA     TTT        TTT     LLLLLLLLL   EEEEEEEEE    SSSSSSS    HHH       HHH  IIIIIII  PPP        \n";
   
        start.play();

        int colour=0;

        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        for(int i=0;i<battleship.length();i++)

        {           
            if(colour%2==0)
            
            {
            
                cout<<RED<<battleship[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7));           
            }
            
            else
            {
            
                cout<<WHITE<<battleship[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7));
            
            }
   
            colour++;
        
        }
       
        this_thread::sleep_for(chrono::seconds(4));

    }

    clearScreen();

    srand(time(0));
    

    int choice_menu,choice_color;

    char main_grid[10][10];   //for the attack portion

    middle.setLooping(true);
    middle.play();
    string welcome =

    "                                                     W       W  EEEEEEEEE  L          CCCCCCC    OOOOOOO    M       M  EEEEEEEEE   \n"
    "                                                     W       W  EEEEEEEEE  L         C       C  OOOOOOOOO   MM     MM  EEEEEEEEE   \n"
    "                                                     W   W   W  E          L         C          OOO   OOO   M M   M M  E           \n"
    "                                                     W  W W  W  EEEEEEE    L         C          OOO   OOO   M  M M  M  EEEEEEE     \n"
    "                                                     W W   W W  EEEEEEE    L         C          OOO   OOO   M   M   M  EEEEEEE     \n"
    "                                                     W W   W W  E          L         C          OOO   OOO   M       M  E           \n"
    "                                                     W       W  EEEEEEEEE  LLLLLLL    CCCCCCC    OOOOOOO    M       M  EEEEEEEEE   \n";

    cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";

    int colour=0;

    
    cout<<"\n\n";

    for(int i=0;i<welcome.length();i++)

    {
       
        if(colour%2==0)
        
        {
        
            cout<<RED<<welcome[i]<<flush;
        
            this_thread::sleep_for(chrono::milliseconds(6));
            
        }
        
        else        
        {
        
            cout<<YELLOW<<welcome[i]<<flush;
        
            this_thread::sleep_for(chrono::milliseconds(6));
        
        }
        
        colour++;        
    }

    cout<<"\n\n";

    cout<<RESET<<"      ==============================================================================================================================================================================================\n\n";
 
    do

    {

        cout<<"\n\n";
        cout<<YELLOW<< 
        "                                  MMMM    MMM    AAAAAAA   IIIIIII  NNN   NNN               MMMM   MMMM    EEEEEEEEE   NNN   NNN    UUU   UUU\n"
        "                                  MMMM    MMM    AAA AAA     III    NNNN  NNN               MMMM   MMMM    EEEEEEEEE   NNNN  NNN    UUU   UUU\n"
        "                                  MMM M M MMM    AA   AA     III    NNNNN NNN               MMM M M MMM    EEE         NNNNN NNN    UUU   UUU\n"
        "                                  MMM  M  MMM    AAAAAAA     III    NNN NNNNN               MMM  M  MMM    EEEEEEE     NNN NNNNN    UUU   UUU\n"
        "                                  MMM     MMM    AA   AA     III    NNN   NNN               MMM     MMM    EEE.        NNN   NNN    UUUUUUUUU\n"
        "                                  MMM     MMM    AA   AA   IIIIIII  NNN   NNN               MMM     MMM    EEEEEEEEE   NNN   NNN     UUUUUUU \n"<<RESET;
        cout<<"\n\n";

        cout<<"      ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";

        cout<<"\n\n";

        cout<<YELLOW<<"         1. Start New Game\n";

        cout<<"         2. Instructions\n";

        cout<<"         3. About The Game\n";

        cout<<RED<<"         4. Exit\n"<<RESET;

        cout<<"\n\n";

        cout<<"      ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
   
        cin>>choice_menu;
        
          enter.play();

        while(choice_menu>4||choice_menu<1)  //validation ahndling for the coice from mwenu 

        {
           cout<<RED<< "Invalid Input................Choose AGAIN:\n\n"<<RESET;

            cout<<"      ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";

            cout<<"\n\n";

            cout<<YELLOW<<"         1. Start New Game\n";

            cout<<"         2. Instructions\n";

            cout<<"         3. About The Game\n";

            cout<<RED<<"         4. Exit\n"<<RESET;

            cout<<"         4. Exit\n";


            cout<<"\n\n";

            cout<<"      ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";  

            cin>>choice_menu;
           enter.play();


  
        }   
        //menu driven switch MAIN
 
        
 
        switch(choice_menu) 
        {
 
            case 1:

            clearScreen();
 
            cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
 
            cout<<"\n\n";
 
            cout <<RED<< 

            "                            SSSSSSS  TTTTTTT   AAAAA   RRRRRR   TTTTTTT      NN   NN  EEEEEEE  WW      WW       GGGGGG    AAAAA   MM   MM  EEEEEEE \n"
            "                           SS          TTT    AA   AA  RR   RR    TTT        NNN  NN  EE       WW      WW      GG        AA   AA  MMM MMM  EE      \n"
            "                            SSSSS      TTT    AAAAAAA  RRRRRR     TTT        NN N NN  EEEEE    WW  WW  WW      GG   GGG  AAAAAAA  MM M MM  EEEEE   \n"
            "                                SS     TTT    AA   AA  RR  RR     TTT        NN  NNN  EE        WWWWWWWW       GG    GG  AA   AA  MM   MM  EE      \n"
            "                           SSSSSSS     TTT    AA   AA  RR   RR    TTT        NN   NN  EEEEEEE    WW  WW         GGGGGG   AA   AA  MM   MM  EEEEEEE \n"<<RESET;

            cout<<"\n\n";

            cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";

            cout<<"1. PLAY Against PLAYER\n";
        
            cout<<"2. PLAY Agaisnt COMPUTER\n";
        
            cin>>choice_player;
            
         enter.play();
            while(choice_player>2||choice_player<1) //Validation handling for the choice os student 1 and 2
        
            {
       
                cout<< "Invalid Input................Choose AGAIN:\n\n";
                cout<<"1. PLAY Against PLAYER\n";
                cout<<"2. PLAY Agaisnt COMPUTER\n";
                cin>>choice_player ;
                enter.play();
            }


            switch(choice_player) //switch. from where the roles of students begin
            {
                case 1:  //pvp
                clearScreen();
            
                
    
               middle.setVolume(40);


                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << 
"                                   LL         OOOOOO      AAAA     DDDDDD    IIIIIII  NN    NN   GGGGGG  \n"
"                                   LL        OO    OO    AA  AA    DD   DD     III    NNN   NN  GG    GG  "<<BLUE<<"    OOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NNNN  NN  GG         "<<BLUE<<"  OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AAAAAAAA   DD    DD    III    NN NN NN  GG   GGGG  "<<BLUE<<"  OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NN  NNNN  GG    GG   "<<BLUE<<"  OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD   DD     III    NN   NNN  GG    GG   "<<BLUE<<"   OOOOO  \n"<<RESET<<
"                                   LLLLLLL    OOOOOO    AA    AA   DDDDDD    IIIIIII  NN    NN   GGGGGG  \n";   
this_thread::sleep_for(chrono::seconds(1));

                clearScreen();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

cout << 
"                                   LL         OOOOOO      AAAA     DDDDDD    IIIIIII  NN    NN   GGGGGG  \n"
"                                   LL        OO    OO    AA  AA    DD   DD     III    NNN   NN  GG    GG   "<< BLUE << "   OOOOO   "<< CYAN << "    OOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NNNN  NN  GG         "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AAAAAAAA   DD    DD    III    NN NN NN  GG   GGGG  "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NN  NNNN  GG    GG   "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD   DD     III    NN   NNN  GG    GG    "<< BLUE << "  OOOOO   "<< CYAN << "    OOOOO   \n"<<RESET<<
"                                   LLLLLLL    OOOOOO    AA    AA   DDDDDD    IIIIIII  NN    NN   GGGGGG  \n";
this_thread::sleep_for(chrono::seconds(1));
                  clearScreen();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << 
"                                   LL         OOOOOO      AAAA     DDDDDD    IIIIIII  NN    NN   GGGGGG  \n"
"                                   LL        OO    OO    AA  AA    DD   DD     III    NNN   NN  GG    GG   "<< BLUE << "   OOOOO   "<< CYAN << "    OOOOO   "<< WHITE << "    OOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NNNN  NN  GG         "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  "<< WHITE << "   OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AAAAAAAA   DD    DD    III    NN NN NN  GG   GGGG  "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  "<< WHITE << "   OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NN  NNNN  GG    GG   "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  "<< WHITE << "   OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD   DD     III    NN   NNN  GG    GG    "<< BLUE << "  OOOOO   "<< CYAN << "    OOOOO   "<< WHITE << "    OOOOO  \n"<<RESET<<
"                                   LLLLLLL    OOOOOO    AA    AA   DDDDDD    IIIIIII  NN    NN   GGGGGG  \n";                                
this_thread::sleep_for(chrono::seconds(1));
         clearScreen();         
                middle.setVolume(100);
                 
                 vsPlayer(player1grid, player2grid);
                 middle.stop();
                 displayResult();

                break;
                case 2: 
                clearScreen();
                 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << 
"                                   LL         OOOOOO      AAAA     DDDDDD    IIIIIII  NN    NN   GGGGGG  \n"
"                                   LL        OO    OO    AA  AA    DD   DD     III    NNN   NN  GG    GG  "<<BLUE<<"    OOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NNNN  NN  GG         "<<BLUE<<"  OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AAAAAAAA   DD    DD    III    NN NN NN  GG   GGGG  "<<BLUE<<"  OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NN  NNNN  GG    GG   "<<BLUE<<"  OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD   DD     III    NN   NNN  GG    GG   "<<BLUE<<"   OOOOO  \n"<<RESET<<
"                                   LLLLLLL    OOOOOO    AA    AA   DDDDDD    IIIIIII  NN    NN   GGGGGG  \n";   
this_thread::sleep_for(chrono::seconds(1));

                clearScreen();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

cout << 
"                                   LL         OOOOOO      AAAA     DDDDDD    IIIIIII  NN    NN   GGGGGG  \n"
"                                   LL        OO    OO    AA  AA    DD   DD     III    NNN   NN  GG    GG   "<< BLUE << "   OOOOO   "<< CYAN << "    OOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NNNN  NN  GG         "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AAAAAAAA   DD    DD    III    NN NN NN  GG   GGGG  "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NN  NNNN  GG    GG   "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD   DD     III    NN   NNN  GG    GG    "<< BLUE << "  OOOOO   "<< CYAN << "    OOOOO   \n"<<RESET<<
"                                   LLLLLLL    OOOOOO    AA    AA   DDDDDD    IIIIIII  NN    NN   GGGGGG  \n";
this_thread::sleep_for(chrono::seconds(1));
                  clearScreen();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << 
"                                   LL         OOOOOO      AAAA     DDDDDD    IIIIIII  NN    NN   GGGGGG  \n"
"                                   LL        OO    OO    AA  AA    DD   DD     III    NNN   NN  GG    GG   "<< BLUE << "   OOOOO   "<< CYAN << "    OOOOO   "<< WHITE << "    OOOOO  \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NNNN  NN  GG         "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  "<< WHITE << "   OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AAAAAAAA   DD    DD    III    NN NN NN  GG   GGGG  "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  "<< WHITE << "   OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD    DD    III    NN  NNNN  GG    GG   "<< BLUE << "  OOOOOOO  "<< CYAN << "   OOOOOOO  "<< WHITE << "   OOOOOOO \n"<<RESET<<
"                                   LL        OO    OO   AA    AA   DD   DD     III    NN   NNN  GG    GG    "<< BLUE << "  OOOOO   "<< CYAN << "    OOOOO   "<< WHITE << "    OOOOO  \n"<<RESET<<
"                                   LLLLLLL    OOOOOO    AA    AA   DDDDDD    IIIIIII  NN    NN   GGGGGG  \n";                                
this_thread::sleep_for(chrono::seconds(1));
         clearScreen();         
                middle.setVolume(100);
                 
                
                clearScreen(); //pvc
                
                      vsComputer(player1grid,player2grid);
                      middle.stop();
                      displayResult();
                break;
                
            }
       
            break;
      
            case 2:
            clearScreen();

            instructions(); //instruction menu
            

            break;

            case 3:
           

            clearScreen();
            ABOUT();
            
       
            break;

            case 4: // exiting the game
       
            choice_menu=1;
       
            break;

        }

    }while(choice_menu!=1);//this menu will run untill the game doesen't starts

    return 0;

}
      
        void clearScreen()//function 01 clearing the screen  
        {
    
            system("clear");
        }

        void initializeBoard(char board[10][10])        //Grids  initializer+resetter by the tidle(~)

{
    for (int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            board[i][j]='~';
            
            
        }
    }
}

        void instructions()    //The instructions mabual
        {
        
            cout<<RESET<<"      ==============================================================================================================================================================================================\n\n";

            cout <<YELLOW<< 
"                                IIIIIII NN   NN   SSSSS    TTTTTTT RRRRRRR  UU   UU   CCCCCC   TTTTTTT  IIIIIII  OOOOOOO  NN   NN   SSSSS \n"
"                                  III   NNN  NN  SS          TTT   RR   RR  UU   UU  CC          TTT      III   OO     OO NNN  NN  SS     \n"
"                                  III   NN N NN   SSSSS      TTT   RRRRRRR  UU   UU  CC          TTT      III   OO     OO NN N NN   SSSSS \n"
"                                  III   NN  NNN       SS     TTT   RR  RR   UU   UU  CC          TTT      III   OO     OO NN  NNN       SS\n"
"                                IIIIIII NN   NN   SSSSS      TTT   RR   RR   UUUUU    CCCCCC     TTT    IIIIIII  OOOOOOO  NN   NN   SSSSS \n"<<RESET;
        char x;

            cout<<"\n\n\n";
            string a="Place Your Ships On The Board\n\n";
            string b="In Player vs Player mode you and the player will take turns firing shots.\n\n";
            string c="In Player vs Compute mode you and the computer will take turns firing shots.\n\n";
            string d="'O' means miss 'X' means Hit\n\n";
            string e="Sink all the enemy ships to win\n\n";

            cout<<RED<<"1. "<<RESET;
            for(int i=0;i<a.length();i++)
            {
                cout<<WHITE<<a[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7)); 

            }
            
                          
            
            cout<<RED<<"2. "<<RESET;
            for(int i=0;i<b.length();i++)
            {
                cout<<WHITE<<b[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7)); 

            }
            
            cout<<RED<<"3. "<<RESET;
            for(int i=0;i<c.length();i++)
            {
                cout<<WHITE<<c[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7)); 

            }
            
            cout<<RED<<"4. "<<RESET;
            for(int i=0;i<d.length();i++)
            {
                cout<<WHITE<<d[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7)); 

            }
            
            cout<<RED<<"5. "<<RESET;
            for(int i=0;i<e.length();i++)
            {
                cout<<WHITE<<e[i]<<flush;
            
                this_thread::sleep_for(chrono::milliseconds(7)); 

            }
            cout<<endl;
            
            cin.ignore();
             cout<<RESET<<"ENTER ANY KEY"<<RED<<" TO EXIT"<<RESET;
           x= getchar();
   
            clearScreen();

        }

        void checkcount(char board[10][10])  //checking and decreasing turn counts
{
    int l11=flag11;
	int l12=flag12;
	int l13=flag13;
	int l14=flag14;
	int	 l15=flag15;
    int l21=flag21;
	int l22=flag22;
	int l23=flag23;
	int l24=flag24;
	int l25=flag25;

	if( arr2[0][0]-arr2[1][0]==0)//horizental. //player 2
       
    {
        flag21=1;
        for(int x=arr2[0][1];x<=arr2[1][1];x++)        
        {
            if(board[arr2[0][0]][x]!='X')
            {
                flag21=0;
                break;
            }

        }      
    }
    
    else   
    {
          flag21=1;
        for(int x=arr2[0][0];x<=arr2[1][0];x++)//vertical
        {
            if(board[x][arr2[1][1]]!='X')
            {
                flag21=0;
                break;

            }
        }      
    }///checking for ship 2
    
    if ( arr2[2][0]-arr2[3][0]==0)//horizental   
    {       
        flag22=1;
        for(int x=arr2[2][1];x<=arr2[3][1];x++)
        {
            if(board[arr2[2][0]][x]!='X')
            {
                flag22=0;
                break;
            }
        }   
    }   
    else   
    {   
        flag22=1;
    
        for(int x=arr2[2][0];x<=arr2[3][0];x++)//vertical
        {
            if(board[x][arr2[2][1]]!='X')
            {
                flag22=0;
                break;
            }
        }   
    }
       ///ship 3
    
       if( arr2[4][0]-arr2[5][0]==0)//horizental
    
       {
        flag23=1;
        for(int x=arr2[4][1];x<=arr2[5][1];x++)
        {
            if(board[arr2[4][0]][x]!='X')
            {
                flag23=0;
                break;

            }
        }   
    }
       else
       {
        flag23=1;
        for(int x=arr2[4][0];x<=arr2[5][0];x++)//vertical
        {            
            if(board[x][arr2[4][1]]!='X')
            {
                flag23=0;
                break;
            }
        }    
    }
       //checkin for ship 4
   
       if( arr2[6][0]-arr2[7][0]==0)//horizental
    
       {
        flag24=1;
        for(int x=arr2[6][1];x<=arr2[7][1];x++)
        {
            if(board[arr2[6][0]][x]!='X')
            {
  
                flag24=0;
                break;
            }
        }
       }   
       else
       {
                flag24=1;
        for(int x=arr2[6][0];x<=arr2[7][0];x++)//vertical
        {
            if(board[x][arr2[6][1]]!='X')
            {

                flag24=0;
                break;
            }
        }
       }
       //cheking for ship 5
       if( arr2[8][0]-arr2[9][0]==0)//horizental
       {
        flag25=1;
        for(int x=arr2[8][1];x<=arr2[9][1];x++)
        {
            if(board[arr2[8][0]][x]!='X')
            {

                flag25=0;
                break;
            }
        }
       }
       else
       {
        flag25=1;
        for(int x=arr2[8][0];x<=arr2[9][0];x++)//vertical
        {           
            if(board[x][arr2[8][1]]!='X')
            {
               flag25=0; 
               break;
            }
        }
       }
   ////////////////////player1
      //checking for ship 1 
       if( arr1[0][0]-arr1[1][0]==0)//horizental. //player 1
       {
        flag11=1;
        for(int x=arr1[0][1];x<=arr1[1][1];x++)
        {
            if(board[arr1[0][0]][x]!='X')
            {
               flag11=0; 
               break;
            }
        }
       }
       else
       {
        flag11=1;
        for(int x=arr1[0][0];x<=arr1[1][0];x++)//vertical
        {
            if(board[x][arr1[0][1]]!='X')
            {
                flag11=0;
                break;
            }
        }

       }///checking for ship 2
       
        if ( arr1[2][0]-arr1[3][0]==0)//horizental
       {
        flag12=1;
        for(int x=arr1[2][1];x<=arr1[3][1];x++)
        {
            if(board[arr1[2][0]][x]!='X')
            {

                flag12=0;
                break;
            }
        }
       }
       else
       {
        flag12=1;
        for(int x=arr1[2][0];x<=arr1[3][0];x++)//vertical
        {
            if(board[x][arr1[2][1]]!='X')
            {

                flag12=0;
                break;
            }
        }
       }
       ///ship 3
       if( arr1[4][0]-arr1[5][0]==0)//horizental
       {
        flag13=1;
        for(int x=arr1[4][1];x<=arr1[5][1];x++)
        {
            if(board[arr1[4][0]][x]!='X')
            {

               flag13=0; 
               break;
            }
        }
       }
       else
       {
        flag13=1;
        for(int x=arr1[4][0];x<=arr1[5][0];x++)//vertical
        {           
            if(board[x][arr1[4][1]]!='X')
            {
               flag13=0;
               break; 
            }
        }
       }
       //checkin for ship 4
       if( arr1[6][0]-arr1[7][0]==0)//horizental
       {
        flag14=1;
        for(int x=arr1[6][1];x<=arr1[7][1];x++)
        {
            if(board[arr1[6][0]][x]!='X')
            {
   
                flag14=0;
                break;
            }
        }
       }
       else
       {
        flag14=1;
        for(int x=arr1[6][0];x<=arr1[7][0];x++)//vertical
        {
                        if(board[x][arr1[6][1]]!='X')
            {
                flag14=0;
                break;
            }
        }
       }
//        //cheking for ship 5
       if( arr1[8][0]-arr1[9][0]==0)//horizental
       {
        flag15=1;
        for(int x=arr1[8][1];x<=arr1[9][1];x++)
        {
            if(board[arr1[8][0]][x]!='X')
            {
                flag15=0;
                break;
            }
        }
       }
      else
       {
        flag15=1;
        for(int x=arr1[8][0];x<=arr1[9][0];x++)//vertical
        {
            if(board[x][arr1[8][1]]!='X')
            {
                flag15=0;
                break;
            }
        }

       }
	    if(!l11 && flag11) player1count--;

	    else if(!l12 && flag12) player1count--;
        
		else if(!l13 && flag13) player1count--;
	
        else if(!l14 && flag14) player1count--;
	
        else if(!l15 && flag15) player1count--; 
	
        else if(!l21 && flag21) player2count--; 
	
        else if(!l22 && flag22) player2count--;
	
        else if(!l23 && flag23) player2count--; 

        else if(!l24 && flag24) player2count--;   
        
        else if(!l25 && flag25) player2count--;
	
    }

        int shipcolor()   //ship colour as per user
    {
        
             sf::SoundBuffer buffer5;
             if(!(buffer5.loadFromFile("../assets/in.wav")))
             cout<<"EROOR loading in.wav\n";
             sf::Sound enter(buffer5);
         cout<<RESET<<"      ==============================================================================================================================================================================================\n\n";


        cout <<
    "                                         SSSSSSS  HH   HH  IIIIIII  PPPPPP        CCCCCCC  OOOOOOO  LL       OOOOOOO  UU   UU  RRRRRRR \n"
    "                                        SS        HH   HH    III    PP   PP      CC        OO   OO  LL       OO   OO  UU   UU  RR    RR\n"
    "                                         SSSSS    HHHHHHH    III    PPPPPP       CC        OO   OO  LL       OO   OO  UU   UU  RRRRRRR \n"
    "                                             SS   HH   HH    III    PP           CC        OO   OO  LL       OO   OO  UU   UU  RR  RR  \n"
    "                                        SSSSSSS   HH   HH  IIIIIII  PP            CCCCCCC  OOOOOOO  LLLLLLL  OOOOOOO   UUUUU   RR   RR \n";
        

        //////////////////////////BEFORE CALLING THIS

        cout << "\n\n";
        int choicecolor;
        // int count=1;
        // cout<<WHITE<<" Enter player" <<count<<RED<< "Name:\n"<<RESET;
        // string name;
        

        
        
        //////////////////call this part
        cout<<"Choose your battleships colour:\n";
        
        cout<<"1."<<RED<<"RED"<<RESET<<endl;
        
        cout<<"2."<<GREEN<<"GREEN"<<RESET<<endl;
        
        cout<<"3."<<YELLOW<<"YELLOW"<<RESET<<endl;
        
        cout<<"4."<<MAGENTA<<"MAGENTA"<<RESET<<endl;
        
        cout<<"5."<<CYAN<<"CYAN"<<RESET<<endl;
        
       

        cin>>choicecolor;

        enter.play();
        this_thread::sleep_for(chrono::seconds(1));

        while(choicecolor<1||choicecolor>5) // validation
        
        ///non terminating check
        {
        
            cout<<"INVALID INPUT......Choose again\n";
        
            cout<<"Choose your battleships colour:\n";
        
            cout<<"1."<<RED<<"RED"<<RESET<<endl;
            
            cout<<"2."<<GREEN<<"GREEN"<<RESET<<endl;
        
            cout<<"3."<<YELLOW<<"YELLOW"<<RESET<<endl;
        
            cout<<"4."<<MAGENTA<<"MAGENTA"<<RESET<<endl;
        
            cout<<"5."<<CYAN<<"CYAN"<<RESET<<endl;
        
            cin>>choicecolor;
            
            enter.play();
            this_thread::sleep_for(chrono::seconds(1));
        }
        
        
        return choicecolor;
    }

        void setColor(int textColor, int bgColor)    //color setter for mac i.e accronyms
        {
            cout << "\033[38;5;" << textColor << ";48;5;" << bgColor << "m";
        }

        void clearBoard (char board[10][10])           // clearing board by intializing                              
        {                                                                            
            initializeBoard(board) ;                                                
        }

        void printBoard(char board[10][10], bool hideShips)  //board printing+ colour or ship placer fuction

        {
            bool turn=0; 
            for (int i=0;i<10;i++)  
            {
                for(int j=0;j<10;j++)   
                {
                    if(board[i][j]==player1grid[i][j])
                    {
                        turn=1;
                    }
                    else
                    {
                        turn=0;
                        break;

                    }
                }
                if(!turn)   
                break;   
            }
            
            if(hideShips)
            { 
        
                cout <<"\t                    ENEMY BOARD\t\t                                            OPPONENT                                                    PLAYER BOARD " << endl;
        
                cout << "                    0  1  2  3  4  5  6  7  8  9             0        1       2       3       4       5       6       7       8       9             0  1  2  3  4  5  6  7  8  9" << endl;
        
                cout <<"\t\t\t\t                          +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;       
        
                for (int i=0;i<10;i++)
        
                {
                    cout<<"               ";
                    cout<<i<<"   ";

                    for(int j=0;j<10;j++)
                    {
                        if (board[i][j] == '~'||board[i][j] == 'S')

                        cout<<" . ";

                        else if(board[i][j] == 'X')

                        cout<<" "<<board[i][j]<<" " ;

                        else if(board[i][j] == 'O')

                        cout<<" "<<board[i][j]<<" ";
                    }
                    cout<<"     "<<i<<"   ";

                    for(int j=0;j<10;j++)
                    {

                        cout<<"|";
                    
                        if(board[i][j]=='X')
                        {
                            setColor(7,4);
                    
                            cout<<"   "<<board[i][j]<<"   ";
                

                            cout<<RESET;

                        }
                            
                    else if(board[i][j]=='O')
                        {
                            
                            setColor(0, 7);
                    
                            cout<<"   "<<board[i][j]<<"   ";
                
                            cout<<RESET;
            
                        }
                            
                        else
            
                        {
            
                            setColor(7, 1);
            
                            cout<<"   ~"<<"   ";
            
                            cout<<RESET;
            
                        }         

                    }
                if(turn)
                    {
                    cout<<"     "<<i<<"   ";

                        for(int j=0;j<10;j++)           
                        {
                
                            if(player2grid[i][j]=='~')
                
                            cout<<" . ";
                
                            else if(player2grid[i][j]=='S')
                
                            cout<<" "<<player2grid[i][j]<<" ";
                
                            else if(player2grid[i][j]=='X')
                
                            cout<<" "<<player2grid[i][j]<<" ";
                
                            else if(player2grid[i][j]=='O')
                
                            cout<<" "<<player2grid[i][j]<<" ";
                    
                }

                }
                else
                {
                    cout<<"     "<<i<<"   ";
                    for(int j=0;j<10;j++)

                {
                    if(player1grid[i][j]=='~')
                    cout<<" . ";
                    else if(player1grid[i][j]=='S')
                    cout<<" "<<player1grid[i][j]<<" ";
                    else if(player1grid[i][j]=='X')
                    cout<<" "<<player1grid[i][j]<<" ";
                    else if(player1grid[i][j]=='O')
                    cout<<" "<<player1grid[i][j]<<" ";
                    
                }

                }  cout<<RESET; 
                
                cout<<endl;

                cout << "\t\t\t\t                         +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
            }
            
        } 
        else 
        {
             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout <<"                                                    0        1       2       3       4       5       6       7       8       9  " << endl;

            cout <<"                                                +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
            
            for (int i=0;i<10;i++)
            {
                cout<<"                                            ";
                cout<<i<<"   ";


                for(int j=0;j<10;j++)

                {
                    cout<<"|";
                    
                        if((shipcolour==1&&board[i][j]=='S'))
                        {
                        
                        setColor(15, 196);
                    
                            cout<<"   "<<board[i][j]<<"   ";
                
                            cout<<RESET;
                        }
            
                    else if(shipcolour==2&&board[i][j]=='S')
                        {
                            
                         setColor(0, 46);
                    
                            cout<<"   "<<board[i][j]<<"   ";
                
                        cout<<RESET;
            
                        }
            
                    else if((shipcolour==3&&board[i][j]=='S'))
            
                        {
                
                        setColor(0, 226);
                        
                        cout<<"   "<<board[i][j]<<"   ";
                
                        cout<<RESET;
            
                    }

                    else if((shipcolour==4&&board[i][j]=='S'))
            
                        {
                
                        setColor(0, 201);
                
                            cout<<"   "<<board[i][j]<<"   ";
            
                            cout<<RESET;
                        }
            
                    else if((shipcolour==5&&board[i][j]=='S'))
            
                        {
            
                           setColor(0, 51);
            
                            cout<<"   "<<board[i][j]<<"   ";
                
                            cout<<RESET;        
            
                        }
            
                        else
            
                        {
            
                            setColor(15, 19);
            
                            cout<<"   "<<board[i][j]<<"   ";
            
                            cout<<RESET;
            
                        }     
                }         
                cout<<endl;
                cout << "                                                +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
                }
                
                cout<<"Press Any Key To Continue"<<endl;
                getchar();
           
        
            }
        
    }       

        void shipplacement(char placer[10][10]) //according to player choices ship placement 
    {
        
        sf::SoundBuffer buffer5;
             if(!(buffer5.loadFromFile("../assets/in.wav")))
             cout<<"EROOR loading in.wav\n";
             sf::Sound enter(buffer5);
        
           printBoard(placer,h);
        int ship_choice;
        
        cout<<"SHIPS AVAILABLE:\nTo choose enter its tag number\n";
        
            if(!flag1)
        
            cout<<"1.Aircraft Carrier - 5 blocks"<<endl;
        
            if(!flag2)
        
            cout<<"2.Battleship - 4 blocks"<<endl;
        
            if(!flag3)
        
            cout<<"3.Destroyer - 3 blocks"<<endl;
        
            if(!flag4)
        
            cout<<"4.Destroyer - 3 blocks"<<endl;
        
            if(!flag5)
        
            cout<<"5.Patrol Boat - 2 blocks"<<endl;
        

        
        cin>>ship_choice;
        enter.play();
        
        while(ship_choice>5||ship_choice<0||ship_choice==flag1||ship_choice==flag2||ship_choice==flag3||ship_choice==flag4||ship_choice==flag5)// ship displat
        
        {
        
            cout<<"INVALID INPUT....Choose Again\n\n";
        
            if(ship_choice==flag1||ship_choice==flag2||ship_choice==flag3||ship_choice==flag4||ship_choice==flag5)
        
            {
        
                cout<<"Ship Not Available\n";
        
            }
        
            if(!flag1)
        
            cout<<"1.Aircraft Carrier - 5 blocks"<<endl;
        
            if(!flag2)
        
            cout<<"2.Battleship - 4 blocks"<<endl;
        
            if(!flag3)
        
            cout<<"3.Destroyer - 3 blocks"<<endl;
        
            if(!flag4)
        
            cout<<"4.Destroyer - 3 blocks"<<endl;
        
            if(!flag5)
        
            cout<<"5.Patrol Boat - 2 blocks"<<endl;
        

        
            cin>>ship_choice; 
            enter.play();
            
        
        }
        
        
        if (ship_choice==1)
        
        {
            flag1=ship_choice;
        
        }
        
        if (ship_choice==2)
        
        {
            flag2=ship_choice;
        }
        
        if (ship_choice==3)
        
        {
        
            flag3=ship_choice;
        
        }
        
        if (ship_choice==4)
        
        {
        
            flag4=ship_choice;
        
        }
        
        if (ship_choice==5)
        
        {
        
            flag5=ship_choice;
        
        }
        
        int ship_place;
        
        cout<<"DO You Want The Ship To Be Placed 1.Random OR 2.Manual?\n";
        
        cin>>ship_place;
        enter.play();
        
        while(ship_place>2||ship_place<1) //validation handling
        
        {
        
            cout<<"INVALID INPUT....CHOOSE AGAIN\n";
        
            cout<<"DO You Want The Ship To Be Placed 1.Random OR 2.Manual?\n";
        
            cin>>ship_place; 
            enter.play();
        
        }
        
        int col,row; // variables for placement either random or  manually

        int hOv;
    
        switch(ship_place)
    
        {
    
            case 1:
    
        
            clearScreen();
            if (ship_choice==1) //ship 1
    
            {
    
                


                int hOv;

                hOv=rand()%2+1;

                if(hOv==1)
                {
                ship1_H:
                row=rand()%10;
                col=rand()%5;

                for(int i=col;i<5+col;i++)
    
                {
                    if(placer[row][i]=='S')
                    {
                        goto ship1_H;
                    }
                }
                if(playercount==1)
                {
                    arr1[0][0]=row;
                arr1[0][1]=col;

                }
                else
                {
                    arr2[0][0]=row;
                arr2[0][1]=col;
                    
                }
                

                for(int i=col;i<5+col;i++)
    
                {
                    

    
                    placer[row][i]='S';
    
                }
                if(playercount==1)
                {
                    arr1[1][0]=row;
                arr1[1][1]=col;

                }
                else
                {
                    arr2[1][0]=row;
                arr2[1][1]=col;
                }
                
            
                }
                else if (hOv==2)
                {

                    ship1_V:
                row=rand()%5;
                col=rand()%10;
                for(int i=row;i<5+row;i++)
    
                {
                    if(placer[i][col]=='S')
                    {
                        goto ship1_V;
                    }
                }
                if(playercount==1)
                {
                    arr1[0][0]=row;
                arr1[0][1]=col;

                }
                else
                {
                    arr2[0][0]=row;
                arr2[0][1]=col;
                }
                

                for(int i=row;i<5+row;i++)
    
                {


    
                    placer[i][col]='S';

    
                }
                if(playercount==1)
                {
                        arr1[1][0]=row;
                arr1[1][1]=col;


                }
                else
                {
                        arr2[1][0]=row;
                arr2[1][1]=col;

                }
            
                }
    

            

            }

            if (ship_choice==2) ///ship 2 

            {
                int hOv;

                hOv=rand()%2+1;




                if(hOv==1)
                {
                            
                                ship2_V:
                    
                    row=rand()%10;

                col=rand()%6;

                for(int i=col;i<col+4;i++)

                {
                    if(placer[row][i]=='S')
                    {
                        goto ship2_V;
                    }
                }
                if(playercount==1)
                {
                        arr1[2][0]=row;
                arr1[2][1]=col;

                }
                else
                {
                    arr2[2][0]=row;
                arr2[2][1]=col;

                }
            

                    for(int i=col;i<col+4;i++)

                {

                    

                    placer[row][i]='S';
        
                }
                if(playercount==1)
                {
                    arr1[3][0]=row;
                arr1[3][1]=col;

                }
                else
                {
                    arr2[3][0]=row;
                arr2[3][1]=col;
                }
                
                }
                else if(hOv==2)
                {
                                            
                                ship2_H:
                    
                    row=rand()%6;

                col=rand()%10;

                for(int i=row;i<row+4;i++)

                {
                    if(placer[i][col]=='S')
                    {

                        goto ship2_H;
                    }
                }
                if(playercount==1)
                {
                    arr1[2][0]=row;
                arr1[2][1]=col;

                }
                else
                {
                    arr2[2][0]=row;
                arr2[2][1]=col;
                }
                

                    for(int i=row;i<row+4;i++)

                {
                    

                    placer[i][col]='S';
        
                } 
                if(playercount==1)
                {
                    arr1[3][0]=row;
                arr1[3][1]=col;

                }
                else
                {
                    arr2[3][0]=row;
                arr2[3][1]=col;
                    
                }
                
                }

                
                
            
        
            }
        
            if (ship_choice==3) //ship 3 
        
            {
                int hOv;

                hOv=rand()%2+1;

                if(hOv==1)
                {

                    ship3_H:

                row=rand()%10;
                col=rand()%7;

                for(int i=col;i<col+3;i++)
        
                {
        
                    if(placer[row][i]=='S')
                    {

                        goto ship3_H;
                    }
                }
                if(playercount==1)
                {
                    arr1[4][0]=row;
                arr1[4][1]=col;

                }
                else
                {
                    arr2[4][0]=row;
                arr2[4][1]=col;
                }
                
        
                for(int i=col;i<col+3;i++)
        
                {
        
                    

                    placer[row][i]='S';
        
                }
                if(playercount==1)
                {
                    arr1[5][0]=row;
                arr1[5][1]=col;

                }
                else
                {
                    arr2[5][0]=row;
                arr2[5][1]=col;
                }
                
                }
                else if(hOv==2)
                {


                    ship3_V:

                row=rand()%7;
                col=rand()%10;

                for(int i=row;i<row+3;i++)
        
                {
        
                    if(placer[i][col]=='S')
                    {
                        goto ship3_V;
                    }
                }
                if(playercount==1)
                {
                    arr1[4][0]=row;
                arr1[4][1]=col;

                }
                else
                {
                    arr2[4][0]=row;
                arr2[4][1]=col;
                }
                
        
                for(int i=row;i<row+3;i++)
        
                {


                    placer[i][col]='S';
        
                }
                if(playercount==1)
                {
                    arr1[5][0]=row;
                arr1[5][1]=col;

                }
                else
                {
                    arr2[5][0]=row;
                arr2[5][1]=col;
                }
                
                }
        
            }  

                if (ship_choice==4) //ship 4 
        
            {
                int hOv;

                hOv=rand()%2+1;

                if(hOv==1)
                {

                    ship4_H:

                row=rand()%10;
                col=rand()%7;
                for(int i=col;i<col+3;i++)
        
                {
        
                    if(placer[row][i]=='S')
                    {
                        goto ship4_H;
                    }
                }
                if(playercount==1)
                {
                    arr1[6][0]=row;
                arr1[6][1]=col;

                }
                else
                {
                    arr2[6][0]=row;
                arr2[6][1]=col;
                }
                
        
                for(int i=col;i<col+3;i++)
        
                {
                    placer[row][i]='S';
        
                }
                if(playercount==1)
                {
                    arr1[7][0]=row;
                arr1[7][1]=col;

                }
                else
                {
                    arr2[7][0]=row;
                arr2[7][1]=col;
                }
                
                }
                else if(hOv==2)
                {


                    ship4_V:

                row=rand()%7;
                col=rand()%10;

                for(int i=row;i<row+3;i++)
        
                {
        
                    if(placer[i][col]=='S')
                    {
                        goto ship4_V;
                    }
                }
                if(playercount==1)
                {
                    arr1[6][0]=row;
                arr1[6][1]=col;

                }
                else
                {
                    arr2[6][0]=row;
                arr2[6][1]=col;
                }
                
        
                for(int i=row;i<row+3;i++)
        
                {
                    placer[i][col]='S';
        
                }
                if(playercount==1)
                {
                    arr1[7][0]=row;
                arr1[7][1]=col;

                }
                else
                {
                    arr2[7][0]=row;
                arr2[7][1]=col;
                }
                }
            
        
            }
        
            if (ship_choice==5) //ship 5
        
            {
            
                    int hOv;

                hOv=rand()%2+1;

                if(hOv==1)
                {
                    ship5_V:

                row=rand()%10;
                col=rand()%8;

                for(int i=col;i<col+2;i++)
        
            {
        
                if(placer[row][i]=='S')
                {
                    goto ship5_V;
                }
            }
            if(playercount==1)
            {
                arr1[8][0]=row;
            arr1[8][1]=col;

            }
            else
            {
                arr2[8][0]=row;
            arr2[8][1]=col;
            }
            
        
            for(int i=col;i<col+2;i++)
        
            {
                placer[row][i]='S';            
            }
            if(playercount==1)
            {
                arr1[9][0]=row;
                arr1[9][1]=col;

            }
            else
            {
                arr2[9][0]=row;
                arr2[9][1]=col;
            }
            
                }
                else if(hOv==2)
                {
                    ship5_H:

                row=rand()%8;
                col=rand()%10;

                for(int i=row;i<row+2;i++)
        
            {
        
                if(placer[i][col]=='S')
                {
                    goto ship5_H;
                }
            }
            if(playercount==1)
            {
                arr1[8][0]=row;
                arr1[8][1]=col;

            }
            else
            {
                arr2[8][0]=row;
                arr2[8][1]=col;
            }
        
            for(int i=row;i<row+2;i++)
        
            {
        
                placer[i][col]='S';
        
                
            }
            if(playercount==1)
            {
                arr1[9][0]=row;
                arr1[9][1]=col;

            }
            else
            {
                arr2[9][0]=row;
                arr2[9][1]=col;
            }
            
                }
            }
            printBoard(placer,h);
        

            
        
            break;
            case 2:
            
        
                if (ship_choice==1) //ship 1
    
            {
                int hOv;

                cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                while(hOv>2||hOv<1)
                {
                    cout<<"INVALID INPUT"<<endl;

                    cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                }

                if(hOv==1)
                {
                ship1H:
                cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                while(row<0||row>9)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-4): ";
                cin>>col;
                enter.play();
                
                while(col<0||col>4)
                {
                cout<<"\n\nEnter the colum number(0-4): ";
                cin>>col; 
                enter.play();
                }
                for(int i=col;i<5+col;i++)
    
                {
                    if(placer[row][i]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                        goto ship1H;
                    }
                }
                if(playercount==1)
                {
                    arr1[0][0]=row;
                arr1[0][1]=col;

                }
                else
                {
                    arr2[0][0]=row;
                arr2[0][1]=col;
                    
                }

                for(int i=col;i<5+col;i++)
    
                {
    
                    placer[row][i]='S';
        
                }
                if(playercount==1)
                {
                    arr1[1][0]=row;
                arr1[1][1]=col;

                }
                else
                {
                    arr2[1][0]=row;
                arr2[1][1]=col;
                    
                }
                }
                else if (hOv==2)
                {

                    ship1V:
                cout<<"\n\nEnter the row number (0-4): ";
                cin>>row;
                enter.play();
                while(row<0||row>4)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-4): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col;
                enter.play();
                while(col<0||col>9)
                {
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col; 
                enter.play();
                }
                for(int i=row;i<5+row;i++)
    
                {
                    if(placer[i][col]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                        goto ship1V; 

                    }
                }
                if(playercount==1)
                {
                    arr1[0][0]=row;
                arr1[0][1]=col;

                }
                else
                {
                    arr2[0][0]=row;
                arr2[0][1]=col;
                    
                }
                for(int i=row;i<5+row;i++)
    
                {  
                    placer[i][col]='S';

                }
                if(playercount==1)
                {
                    arr1[0][0]=row;
                arr1[0][1]=col;

                }
                else
                {
                    arr2[0][0]=row;
                arr2[0][1]=col;
                    
                }
            

                }
    

            

            }

            if (ship_choice==2) ///ship 2 

            {
                int hOv;

                cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                while(hOv>2||hOv<1)
                {
                    cout<<"INVALID INPUT"<<endl;

                    cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                }




                if(hOv==1)
                {
                            
                                ship2V:
                    
                    cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                while(row<0||row>9)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-5): ";
                cin>>col;
                enter.play();
                while(col<0||col>5)
                {
                cout<<"\n\nEnter the colum number(0-5): ";
                cin>>col; 
                enter.play();
                }
                for(int i=col;i<col+4;i++)

                {
                    if(placer[row][i]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                        goto ship2V;
                    }
                }
                if(playercount==1)
                {
                    arr1[2][0]=row;
                arr1[2][1]=col;

                }
                else
                {
                    arr2[2][0]=row;
                arr2[2][1]=col;
                    
                }
                

                    for(int i=col;i<col+4;i++)

                {

                    placer[row][i]='S';

                }
                if(playercount==1)
                {
                    arr1[3][0]=row;
                arr1[3][1]=col;

                }
                else
                {
                    arr2[3][0]=row;
                arr2[3][1]=col;
                    
                }
                }
                else if(hOv==2)
                {
                                            
                                ship2H:
                    
                    cout<<"\n\nEnter the row number (0-5): ";
                cin>>row;
                enter.play();
                while(row<0||row>5)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-5): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col;
                enter.play();
                while(col<0||col>9)
                {
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col; 
                enter.play();
                }
                for(int i=row;i<row+4;i++)

                {
                    if(placer[i][col]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                    goto ship2H; 
                    }
                }
                if(playercount==1)
                {
                    arr1[2][0]=row;
                arr1[2][1]=col;

                }
                else
                {
                    arr2[2][0]=row;
                arr2[2][1]=col;
                    
                }

                    for(int i=row;i<row+4;i++)

                {

                    placer[i][col]='S';    
                } 
                if(playercount==1)
                {
                    arr1[3][0]=row;
                arr1[3][1]=col;

                }
                else
                {
                    arr2[3][0]=row;
                arr2[3][1]=col;
                    
                }

                }

                
                
            
        
            }
        
            if (ship_choice==3) //ship 3 
        
            {
                int hOv;
        
                cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                while(hOv>2||hOv<1)
                {
                    cout<<"INVALID INPUT"<<endl;

                    cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                }

                if(hOv==1)
                {

                    ship3H:

                cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                while(row<0||row>9)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-6): ";
                cin>>col;
                enter.play();
                while(col<0||col>6)
                {
                cout<<"\n\nEnter the colum number(0-6): ";
                cin>>col; 
                enter.play();
                }
                
                for(int i=col;i<col+3;i++)
        
                {
        
                    if(placer[row][i]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                    goto ship3H; 
                    }
                }
                if(playercount==1)
                {
                    arr1[4][0]=row;
                arr1[4][1]=col;

                }
                else
                {
                    arr2[4][0]=row;
                arr2[4][1]=col;
                    
                }
        
                for(int i=col;i<col+3;i++)
        
                {
        
                    placer[row][i]='S';
        
                }
                if(playercount==1)
                {
                    arr1[5][0]=row;
                arr1[5][1]=col;

                }
                else
                {
                    arr2[5][0]=row;
                arr2[5][1]=col;
                    
                }
                }
                else if(hOv==2)
                {


                    ship3V:

                cout<<"\n\nEnter the row number (0-6): ";
                cin>>row;
                enter.play();
                while(row<0||row>6)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-6): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col;
                enter.play();
                while(col<0||col>9)
                {
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col; 
                enter.play();
                }
                for(int i=row;i<row+3;i++)
        
                {
        
                    if(placer[i][col]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                        goto ship3V;
                    }
                }
                if(playercount==1)
                {
                    arr1[4][0]=row;
                arr1[4][1]=col;

                }
                else
                {
                    arr2[4][0]=row;
                arr2[4][1]=col;
                    
                }
        
                for(int i=row;i<row+3;i++)
        
                {            

                    placer[i][col]='S';
        
        
                }
                if(playercount==1)
                {
                    arr1[5][0]=row;
                arr1[5][1]=col;

                }
                else
                {
                    arr2[5][0]=row;
                arr2[5][1]=col;
                    
                }
                }
        
            }  

                if (ship_choice==4) //ship 4 
        
            {
                int hOv;

                cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                while(hOv>2||hOv<1)
                {
                    cout<<"INVALID INPUT"<<endl;

                    cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                }

                if(hOv==1)
                {

                    ship4H:

                cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                while(row<0||row>9)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-6): ";
                cin>>col;
                enter.play();
                while(col<0||col>6)
                {
                cout<<"\n\nEnter the colum number(0-6): ";
                cin>>col; 
                enter.play();
                }
                for(int i=col;i<col+3;i++)
        
                {
        
                    if(placer[row][i]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                    goto ship4H; 
                    }
                }
                if(playercount==1)
                {
                    arr1[6][0]=row;
                arr1[6][1]=col;

                }
                else
                {
                    arr2[6][0]=row;
                arr2[6][1]=col;
                    
                }
        
                for(int i=col;i<col+3;i++)
        
                {
                    placer[row][i]='S';
                }
                if(playercount==1)
                {
                    arr1[7][0]=row;
                arr1[7][1]=col;

                }
                else
                {
                    arr2[7][0]=row;
                arr2[7][1]=col;
                    
                }
                }
                else if(hOv==2)
                {


                    ship4V:

                cout<<"\n\nEnter the row number (0-6): ";
                cin>>row;
                enter.play();
                while(row<0||row>6)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-6): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col;
                enter.play();
                while(col<0||col>9)
                {
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col; 
                enter.play();
                }
                for(int i=row;i<row+3;i++)
        
                {
        
                    if(placer[i][col]=='S')
                    {
                        cout<<"Ship Already Placed at the Place\n";
                        goto ship4V;
                    }
                }
                if(playercount==1)
                {
                    arr1[6][0]=row;
                arr1[6][1]=col;

                }
                else
                {
                    arr2[6][0]=row;
                arr2[6][1]=col;
                    
                }
        
                for(int i=row;i<row+3;i++)
        
                {
                    placer[i][col]='S';
                }
                if(playercount==1)
                {
                    arr1[7][0]=row;
                arr1[7][1]=col;

                }
                else
                {
                    arr2[7][0]=row;
                arr2[7][1]=col;
                    
                }
                }
            
        
            }
        
            if (ship_choice==5) //ship 5
        
            {
            
                    int hOv;

                cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                while(hOv>2|hOv<1)
                {
                    cout<<"INVALID INPUT"<<endl;

                    cout<<"\nDo you want to place the ship Horizentaly or vertically?\n\n1.Horizental\n2.Vertical\n";

                cin>>hOv;
                enter.play();

                }

                if(hOv==1)
                {
                    ship5V:

                cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                while(row<0||row>9)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-9): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-7): ";
                cin>>col;
                enter.play();
                while(col<0||col>7)
                {

                cout<<"\n\nEnter the colum number(0-7): ";
                cin>>col; 
                enter.play();
                }
                for(int i=col;i<col+2;i++)
        
            {
        
                if(placer[row][i]=='S')
                {
                    cout<<"Ship Already Placed at the Place\n";
                    goto ship5V;
                }
            }
            if(playercount==1)
                {
                    arr1[8][0]=row;
                arr1[8][1]=col;

                }
                else
                {
                    arr2[9][0]=row;
                arr2[9][1]=col;
                    
                }
        
            for(int i=col;i<col+2;i++)
        
            {
                placer[row][i]='S';        
                
            }
            if(playercount==1)
                {
                    arr1[9][0]=row;
                arr1[9][1]=col;

                }
                else
                {
                    arr2[9][0]=row;
                arr2[9][1]=col;
                    
                }
                }
                else if(hOv==2)
                {
                    ship5H:

                cout<<"\n\nEnter the row number (0-7): ";
                cin>>row;
                enter.play();
                while(row<0||row>7)
                {
                    cout<<"INVALID INPUT\n";
                    cout<<"\n\nEnter the row number (0-7): ";
                cin>>row;
                enter.play();
                }
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col;
                enter.play();
                while(col<0||col>9)
                {
                cout<<"\n\nEnter the colum number(0-9): ";
                cin>>col; 
                enter.play();
                }
                for(int i=row;i<row+2;i++)
        
            {
        
                if(placer[i][col]=='S')
                {
                    cout<<"Ship Already Placed at the Place\n";
                    goto ship5H;
                }
            }
            if(playercount==1)
                {
                    arr1[8][0]=row;
                arr1[8][1]=col;

                }
                else
                {
                    arr2[8][0]=row;
                arr2[8][1]=col;
                    
                }
            for(int i=row;i<row+2;i++)
        
            {
                placer[i][col]='S';          
                
            }
            if(playercount==1)
                {
                    arr1[9][0]=row;
                arr1[9][1]=col;

                }
                else
                {
                    arr2[9][0]=row;
                arr2[9][1]=col;
                    
                }
            
            }    
        
        }
        this_thread::sleep_for(chrono::seconds(1));
        clearScreen();
                printBoard(placer,h);


                   
        
            break;
    } 
    
    
    }

        void playerAttack(char opponentBoard[10][10], int &playerScore)//player attacking startegy 

    {
        sf::SoundBuffer buffer5;
             if(!(buffer5.loadFromFile("../assets/in.wav")))
             cout<<"EROOR loading in.wav\n";
             sf::Sound enter(buffer5);
        sf::SoundBuffer soundBuffer2;

    if (!soundBuffer2.loadFromFile("../assets/middle.wav"))
    cout << "Error loading middle.wav\n";
 
    sf::Sound middle(soundBuffer2);

        clearScreen();
        int count=0;


        cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
        cout << 
    "\n                                                                           AAAAA    TTTTTTT  TTTTTTT   AAAAA     CCCCCCC  KK  KK \n"
    "                                                                          AA   AA     TTT      TTT    AA   AA   CC        KK KK  \n"
    "                                                                          AAAAAAA     TTT      TTT    AAAAAAA   CC        KKKK   \n"
    "                                                                          AA   AA     TTT      TTT    AA   AA   CC        KK KK  \n"
    "                                                                          AA   AA     TTT      TTT    AA   AA    CCCCCCC  KK  KK \n\n";
        cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
        h=1;
        printBoard(opponentBoard,h);
        cout<<"Enter The INDEXES Where You Want To Fire: ";
        cout<<endl;
        if(count%2==0)
        {
            checkcount(player1grid);
            
            for(int i=0;i<player1count;i++)
            {
                int row;
        int col;
        again:
        cout<<"The Row Number: ";
        cin>>row;
        enter.play();
        while(row<0||row>9)
        {
            cout<<"INVALID POINT OF ATTACK!!!\n";
            cout<<"The Row Number: ";
            cin>>row;
            enter.play();

        }
        cout<< "The Colum Number: ";
        cin>>col;
        enter.play();
        while(col<0||col>9||opponentBoard[row][col]=='X'||opponentBoard[row][col]=='O')
        {
            if(opponentBoard[row][col]=='X'||opponentBoard[row][col]=='O')
            {
                cout<<"Point Already Attacked\n";
                goto again;
            }
            else{
                cout<<"INVALID POINT OF ATTACK!!!\n";
            cout<<"The Colum Number: ";
            cin>>col;
            enter.play();
            }
            

        }
        if(opponentBoard[row][col]=='S')
    {
    opponentBoard[row][col]='X';
    player1Score+=10;
        }
        else
    {
            opponentBoard[row][col]='O';
            player1Score--;

        }

            }
            

        }
        else
        {
        checkcount(player2grid);
            for(int i=0;i<player2count;i++)
            {
                int row;
        int col;
        cout<<"The Row Number: ";
        cin>>row;
        enter.play();
        cout<< "The Colum Number: ";
        cin>>col;
        enter.play();
        if(opponentBoard[row][col]=='S')
        {
         opponentBoard[row][col]='X';
         player2Score+=10;
        }
        else
        {
            opponentBoard[row][col]='O';
            player2Score--;

        }
        

            }


        }
        getchar();
        clearScreen();
        sf::SoundBuffer soundBuffer3;
                if (!soundBuffer3.loadFromFile("../assets/firing.wav"))
                cout << "Error loading firing.wav\n";
                sf::Sound fire(soundBuffer3);

                 sf::SoundBuffer soundBuffer4;
                if (!soundBuffer4.loadFromFile("../assets/firing2.wav"))
                cout << "Error loading firing2.wav\n";
                sf::Sound fire2(soundBuffer4);

              middle.setVolume(20);
                fire.play();
                

     
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";   
    cout << 
"                                       FFFFFFF IIIIIII RRRRRRR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO  TTTTTTT  SSSSSS " << YELLOW << "   OOOOO \n"<<RESET;

cout<<
"                                       FF        III   RR   RR    III   NNN  NN GG          SS      HH   HH OO     OO   TTT   SS     " << YELLOW << "   OOOOOOO \n"<<RESET;

fire.play();
cout<<"                                       FFFFF     III   RRRRRRR    III   NN N NN GG  GGGG     SSSSS  HHHHHHH OO     OO   TTT    SSSSS " << YELLOW << "   OOOOOOO \n"<<RESET<<
"                                       FF        III   RR  RR     III   NN  NNN GG    GG         SS HH   HH OO     OO   TTT        SS" << YELLOW << "   OOOOOOO \n"<<RESET;

cout<<
"                                       FF      IIIIIII RR   RR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO    TTT   SSSSSSS" << YELLOW << "    OOOOO  \n"<<RESET;
    
        this_thread::sleep_for(chrono::seconds(1));
    clearScreen();

fire.play();

        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << 
"                                       FFFFFFF IIIIIII RRRRRRR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO  TTTTTTT  SSSSSS " << YELLOW << "  OOOOO   " << ORANGE << "    OOOOO  \n"<<RESET<<
"                                       FF        III   RR   RR    III   NNN  NN GG          SS      HH   HH OO     OO   TTT   SS     " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO \n"<<RESET;

cout<<
"                                       FFFFF     III   RRRRRRR    III   NN N NN GG  GGGG     SSSSS  HHHHHHH OO     OO   TTT    SSSSS " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO \n"<<RESET;

fire.play();
cout<<"                                       FF        III   RR  RR     III   NN  NNN GG    GG         SS HH   HH OO     OO   TTT        SS" << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO \n"<<RESET<<
"                                       FF      IIIIIII RR   RR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO    TTT   SSSSSSS" << YELLOW << "   OOOOO   " << ORANGE << "    OOOOO  \n"<<RESET;
    
        this_thread::sleep_for(chrono::seconds(1));
    clearScreen();

    fire.play();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << 
"                                       FFFFFFF IIIIIII RRRRRRR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO  TTTTTTT  SSSSSS " << YELLOW << "  OOOOO   " << ORANGE << "    OOOOO   " << RED << "    OOOOO  \n"<<RESET;

cout<<
"                                       FF        III   RR   RR    III   NNN  NN GG          SS      HH   HH OO     OO   TTT   SS     " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO  " << RED << "   OOOOOOO \n"<<RESET<<
"                                       FFFFF     III   RRRRRRR    III   NN N NN GG  GGGG     SSSSS  HHHHHHH OO     OO   TTT    SSSSS " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO  " << RED<< "   OOOOOOO \n"<<RESET;

fire.play();
cout<<
"                                       FF        III   RR  RR     III   NN  NNN GG    GG         SS HH   HH OO     OO   TTT        SS" << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO  " << RED << "   OOOOOOO \n"<<RESET<<
"                                       FF      IIIIIII RR   RR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO    TTT   SSSSSSS" << YELLOW << "   OOOOO   " << ORANGE << "    OOOOO   " << RED << "    OOOOO  \n"<<RESET;
    
    sf::SoundBuffer soundbuffer4;
    if(!(soundbuffer4.loadFromFile("../assets/miss.wav")))
    cout<<"Unable to load miss.wav\n";
    sf::Sound miss(soundbuffer4);

    miss.play();

        this_thread::sleep_for(chrono::seconds(1));
        miss.play();
        this_thread::sleep_for(chrono::seconds(1));
        miss.play();

        this_thread::sleep_for(chrono::seconds(1));
        middle.setVolume(100);
    clearScreen();
    cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
        cout << 
"                                                                          RRRRRRR  EEEEEEE   SSSSS   UU   UU  LL       TTTTTTT\n"
"                                                                          RR   RR  EE       SS       UU   UU  LL         TTT  \n"
"                                                                          RRRRRRR  EEEEE     SSSSS   UU   UU  LL         TTT  \n"
"                                                                          RR  RR   EE            SS  UU   UU  LL         TTT  \n"
"                                                                          RR   RR  EEEEEEE   SSSSS    UUUUU   LLLLLLL    TTT  \n";
        cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
        printBoard(opponentBoard,h);// calling again to display
        
        getchar();
        clearScreen();
        
    }

        void vsPlayer(char board1[10][10], char board2[10][10]) // MAIN PVP function
{
    sf::SoundBuffer buffer5;
             if(!(buffer5.loadFromFile("../assets/in.wav")))
             cout<<"EROOR loading in.wav\n";
             sf::Sound enter(buffer5);
          sf::SoundBuffer soundBuffer2;

    if (!soundBuffer2.loadFromFile("../assets/middle.wav"))
    cout << "Error loading middle.wav\n";
 
    sf::Sound middle(soundBuffer2);
    int y;

    do
    {
        clearScreen();

        int flagredo1 = 0, flagredo2 = 0;

        if (playercount == 1)
        {

            shipcolour = shipcolor();
            clearScreen();

            int x;

          start1:

            if (flagredo1)
            {
                flag1 = 0;
                flag2 = 0;
                flag3 = 0;
                flag4 = 0;
                flag5 = 0;

                flagredo1 = 0;
            }


            initializeBoard(board1);
            printBoard(board1, h);

            cout << "Do You Want to place all the ships Randomly or manually?\n1.Randomly\n2.Manually\n";

            int r;
            cin >> r;
            enter.play();

            while (r < 1 || r > 2)
            {
                cout << "Invalid Input\n";
                cout << "Do You Want to place all the ships Randomly or manually?\n1.Randomly\n2.Manually\n";
                int r;
                cin >> r;
                enter.play();
            }
            

            clearScreen();
            if (r == 2)
            {
                shipplacement(board1);   // ship 1
                
                clearScreen();

                shipplacement(board1);   // ship 2
                
                clearScreen();

                shipplacement(board1);   // ship 3
                
                clearScreen();

                shipplacement(board1);   // ship 4
                
                clearScreen();

                shipplacement(board1);   // ship 5

                cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2.\n";
                cin >> x;
                enter.play();

                while (x > 2 || x < 1)
                {
                    cout << "INVALID INPUT!\n";
                    cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2\n";
                    cin >> x;
                    enter.play();
                }

                if (x == 1)
                {
                    initializeBoard(board1);
                    flagredo1 = 1;
                    goto start1;
                }
            }
            else
            {
                clearScreen();
                start11:
                setRandomShips(board1);
                printBoard(board1, h);

                cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2.\n";
                cin >> y;
                enter.play();

                while (y > 2 || y < 1)
                {
                    cout << "INVALID INPUT!\n";
                    cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2\n";
                    cin >> y;
                    enter.play();
                }

                if (y == 1)
                {
                    clearBoard(board1);
                    clearScreen();
                    goto start11;
                }


            }
            
        }
        else
            {

                shipcolour = shipcolor();
                clearScreen();
                initializeBoard(board2);
                printBoard(board2, h);

                cout << "Do You Want to place all the ships Randomly or manually?\n1.Randomly\n2.Manually\n";

                int r;
                cin >> r;
                enter.play();

             while (r < 1 || r > 2)
            {
                cout << "Invalid Input\n";
                cout << "Do You Want to place all the ships Randomly or manually?\n1.Randomly\n2.Manually\n";
                int r;
                cin >> r;
                enter.play();
            }
               
               

            clearScreen();
               if(r==1)
               {
                start21:

                clearScreen();
                
                setRandomShips(board2);
                printBoard(board2, h);

                cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2.\n";
                cin >> y;
                enter.play();

                while (y > 2 || y < 1)
                {
                    cout << "INVALID INPUT!\n";
                    cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2\n";
                    cin >> y;
                    enter.play();
                }

                if (y == 1)
                {
                    clearBoard(board2);
                    
                    goto start21;
                }

               }
               else
               {

                 start2:

                if (flagredo2)
                {
                    flag1 = 0;
                    flag2 = 0;
                    flag3 = 0;
                    flag4 = 0;
                    flag5 = 0;
                    flagredo2 = 0;
                }

                clearScreen();
                initializeBoard(board2);
                // printBoard(board2, h);

                flag1 = 0;
                flag2 = 0;
                flag3 = 0;
                flag4 = 0;
                flag5 = 0;

                shipplacement(board2);   // ship 1
                
                clearScreen();
                shipplacement(board2);   // ship 2
                
                clearScreen();
                shipplacement(board2);   // ship 3
                
                clearScreen();
                shipplacement(board2);   // ship 4
                
                clearScreen();
                shipplacement(board2);   // ship 5
                
                

                cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2.\n";
                cin >> y;
                enter.play();

                while (y > 2 || y < 1)
                {
                    cout << "INVALID INPUT!\n";
                    cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2\n";
                    cin >> y;
                    enter.play();
                }

                if (y == 1)
                {
                    initializeBoard(board2);
                    flagredo2 = 1;
                    goto start2;
                }


               }

               
            }
    

        

        playercount++;

    } while (playercount != 3);

    int ext=0;
        int count = 0;
        int score1 = 0;
        int score2 = 0;
        middle.pause();
        while(true)
        {

            if (count % 2 == 0)
            {
                playerAttack(board2, score1);
            }
                
            else
                playerAttack(board1, score1);

            count++;

            for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(board1[i][j]=='X')
                        ext++;

                    }
                }
                if(ext>=17)
                termte=0;
                else
                ext=0;

            for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(board2[i][j]=='X')
                        ext++;

                    }
                }
                if(ext>=17)
                break;
                else
                ext=0;
            
        }
}
 
        void setRandomShips (char board[10][10])//seetting randomized ships 
        {
            

            int row,col;
                {

                    int hOv;

                    hOv=rand()%2+1;
                    

                    if(hOv==1)
                    {
                    ship1_H:
                    row=rand()%10;
                    col=rand()%5;

                    for(int i=col;i<5+col;i++) 
                    {
                        if(board[row][i]=='S')
                        {
                            goto ship1_H;
                        }
                    }

                    for(int i=col;i<5+col;i++)
                    {  
                        board[row][i]='S'; 
                    }
                
                    }
                    else if (hOv==2)
                    {

                        ship1_V:
                    
                    row=rand()%5;
                    
                    col=rand()%10;
                
                    for(int i=row;i<5+row;i++)
        
                    {
                        if(board[i][col]=='S')
                        {
                            goto ship1_V;
                        }
                    }

                    for(int i=row;i<5+row;i++)
        
                    {
                        board[i][col]='S';   
                    }

                    }

                }

                {
                    int hOv;

                    hOv=rand()%2+1;

                    if(hOv==1)
                    {
                                
                    ship2_V:
                        
                    row=rand()%10;

                    col=rand()%6;

                    for(int i=col;i<col+4;i++)

                    {
                        if(board[row][i]=='S')
                        {
                            goto ship2_V;
                        }
                    }

                    for(int i=col;i<col+4;i++)

                    {
                        board[row][i]='S';  
                    }           
                    }
                    else if(hOv==2)
                    {
                                                
                    ship2_H:
                        
                    row=rand()%6;

                    col=rand()%10;

                    for(int i=row;i<row+4;i++)

                    {
                        if(board[i][col]=='S')
                        {

                            goto ship2_H;
                        }
                    }
                        for(int i=row;i<row+4;i++)

                    {
                        board[i][col]='S'; 
                    } 
                
                    }
                }
                {
                    int hOv;

                    hOv=rand()%2+1;

                    if(hOv==1)
                    {

                        ship3_H:

                    row=rand()%10;
                    col=rand()%7;

                    for(int i=col;i<col+3;i++)
            
                    {  
                        if(board[row][i]=='S')
                        {

                            goto ship3_H;
                        }
                    }
            
                    for(int i=col;i<col+3;i++)
            
                    {
                        board[row][i]='S';
            
                    }

                    }
                    else if(hOv==2)
                    {
                        ship3_V:

                    row=rand()%7;
                    col=rand()%10;

                    for(int i=row;i<row+3;i++)
                    {
                        if(board[i][col]=='S')
                        {
                            goto ship3_V;
                        }
                    }
        
                    for(int i=row;i<row+3;i++)  
                    {
                        board[i][col]='S';
            
                    }           
                    }
            
                }  
        
                {
                    int hOv;

                    hOv=rand()%2+1;

                    if(hOv==1)
                    {

                        ship4_H:

                    row=rand()%10;
                    col=rand()%7;
                    for(int i=col;i<col+3;i++)
            
                    {
            
                        if(board[row][i]=='S')
                        {
                            goto ship4_H;
                        }
                    }

                    for(int i=col;i<col+3;i++)
            
                    {
                        board[row][i]='S';
            
                    }

                    
                    }
                    else if(hOv==2)
                    {
                        ship4_V:

                    row=rand()%7;
                    col=rand()%10;

                    for(int i=row;i<row+3;i++)
            
                    {
            
                        if(board[i][col]=='S')
                        {
                            goto ship4_V;
                        }
                    }

            
                    for(int i=row;i<row+3;i++)
            
                    {
                        board[i][col]='S';
            
                    }
                }        
            
                }  
                {
                
                        int hOv;

                    hOv=rand()%2+1;

                    if(hOv==1)
                    {
                        ship5_V:

                    row=rand()%10;
                    col=rand()%8;

                    for(int i=col;i<col+2;i++)
            
                {
            
                    if(board[row][i]=='S')
                    {
                        goto ship5_V;
                    }
                }

                for(int i=col;i<col+2;i++)
            
                {
                    board[row][i]='S';            
                }

                
                }
                    else if(hOv==2)
                    {
                        ship5_H:

                    row=rand()%8;
                    col=rand()%10;

                    for(int i=row;i<row+2;i++)
            
                {
            
                    if(board[i][col]=='S')
                    {
                        goto ship5_H;
                    }
                }

                for(int i=row;i<row+2;i++)
                {
                    board[i][col]='S';         
                }

                
            }
                }   

            
        }

        void computerAttack(char opponentBoard[10][10], int &playerScore)//computer attacking startegy 

    {

         int count=0;
         sf::SoundBuffer soundBuffer3;
                if (!soundBuffer3.loadFromFile("../assets/firing.wav"))
                cout << "Error loading firing.wav\n";
                sf::Sound fire(soundBuffer3);
       
        sf::SoundBuffer buffer5;
       
        if(!(buffer5.loadFromFile("../assets/in.wav")))
        cout<<"EROOR loading in.wav\n";
       
        sf::Sound enter(buffer5);       
        sf::SoundBuffer soundBuffer2;
   
        if (!soundBuffer2.loadFromFile("../assets/middle.wav"))
    
        cout << "Error loading middle.wav\n";
    
        sf::Sound middle(soundBuffer2);
        clearScreen();
       
        if(count%2==0)
        {
            checkcount(player1grid);
            
            for(int i=0;i<player1count;i++)
            { 
                int row;
                int col;
    
                again:
    
                row=rand()%10; 
                enter.play();          
                col=rand()%10; 
                enter.play();
                while(opponentBoard[row][col]=='X'||opponentBoard[row][col]=='O')
                {
                    goto again;
                }
                if(opponentBoard[row][col]=='S')
                {
                    opponentBoard[row][col]='X';
                    player1Score+=10;
                }
                else
                {
                    opponentBoard[row][col]='O';
                    player1Score--;
                }
            }
        
        } 
        else 
        {
            checkcount(player2grid);

            for(int i=0;i<player2count;i++)
            {
               int row;
                int col;
       
                row=rand()%10; 
                enter.play();
                col=rand()%10;
                enter.play();

                if(opponentBoard[row][col]=='S')
                {
                    opponentBoard[row][col]='X';
                    player2Score+=10;
                }
       
                else
                {
                    opponentBoard[row][col]='O';    
                    player2Score--;     
                }
       
            }   
        }
       
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
       
        cout << 
"             CCCCC  HH   HH  OOOOOOO   OOOOOOO    SSSSS  IIIIIII  NN   NN  GGGGGGG      IIIIIII  NN   NN DDDDDD   EEEEEEE  XX   XX  EEEEEEE   SSSSS " << LIGHT_BLUE << "   OOOOO  \n"
"            CC      HH   HH OO     OO OO     OO  SS        III    NNN  NN GG              III    NNN  NN DD   DD  EE        XX XX   EE       SS     " << LIGHT_BLUE << "  OOOOOOO \n"
"            CC      HHHHHHH OO     OO OO     OO  SSSSS     III    NN N NN GG  GGGG        III    NN N NN DD    DD EEEEE      XXX    EEEEE     SSSSS " << LIGHT_BLUE << "  OOOOOOO \n"
"            CC      HH   HH OO     OO OO     OO      SS    III    NN  NNN GG    GG        III    NN  NNN DD    DD EE        XX XX   EE            SS" << LIGHT_BLUE << "  OOOOOOO \n"
"             CCCCC  HH   HH  OOOOOOO   OOOOOOO    SSSSS  IIIIIII  NN   NN  GGGGGGG      IIIIIII  NN   NN DDDDDD   EEEEEEE  XX   XX  EEEEEEE   SSSSS " << LIGHT_BLUE << "   OOOOO  \n";



                this_thread::sleep_for(chrono::seconds(1));

                clearScreen();

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 

cout << 
"             CCCCC  HH   HH  OOOOOOO   OOOOOOO    SSSSS  IIIIIII  NN   NN  GGGGGGG     IIIIIII  NN   NN DDDDDD   EEEEEEE  XX   XX  EEEEEEE   SSSSS " << LIGHT_BLUE << "   OOOOO   " << CYAN << "    OOOOO  \n"
"            CC      HH   HH OO     OO OO     OO  SS        III    NNN  NN GG             III    NNN  NN DD   DD  EE        XX XX   EE       SS     " << LIGHT_BLUE << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"
"            CC      HHHHHHH OO     OO OO     OO   SSSSS    III    NN N NN GG  GGGG       III    NN N NN DD    DD EEEEE      XXX    EEEEE     SSSSS " << LIGHT_BLUE << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"
"            CC      HH   HH OO     OO OO     OO      SS    III    NN  NNN GG    GG       III    NN  NNN DD    DD EE        XX XX   EE            SS" << LIGHT_BLUE << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"
"             CCCCC  HH   HH  OOOOOOO   OOOOOOO    SSSSS  IIIIIII  NN   NN  GGGGGGG     IIIIIII  NN   NN DDDDDD   EEEEEEE  XX   XX  EEEEEEE   SSSSS " << LIGHT_BLUE << "   OOOOO   " << CYAN << "    OOOOO  \n";

                this_thread::sleep_for(chrono::seconds(1));

                clearScreen();


                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 


    cout << 
"             CCCCC  HH   HH  OOOOOOO   OOOOOOO    SSSSS  IIIIIII  NN   NN  GGGGGGG     IIIIIII  NN   NN DDDDDD   EEEEEEE  XX   XX  EEEEEEE   SSSSS " << LIGHT_BLUE << "   OOOOO   " << CYAN << "    OOOOO   " << WHITE << "    OOOOO  \n"
"            CC      HH   HH OO     OO OO     OO  SS        III    NNN  NN GG             III    NNN  NN DD   DD  EE        XX XX   EE       SS     " << LIGHT_BLUE << "  OOOOOOO  " << CYAN << "   OOOOOOO  " << WHITE << "   OOOOOOO \n"
"            CC      HHHHHHH OO     OO OO     OO   SSSSS    III    NN N NN GG  GGGG       III    NN N NN DD    DD EEEEE      XXX    EEEEE     SSSSS " << LIGHT_BLUE << "  OOOOOOO  " << CYAN << "   OOOOOOO  " << WHITE << "   OOOOOOO \n"
"            CC      HH   HH OO     OO OO     OO      SS    III    NN  NNN GG    GG       III    NN  NNN DD    DD EE        XX XX   EE            SS" << LIGHT_BLUE << "  OOOOOOO  " << CYAN << "   OOOOOOO  " << WHITE << "   OOOOOOO \n"
"             CCCCC  HH   HH  OOOOOOO   OOOOOOO    SSSSS  IIIIIII  NN   NN  GGGGGGG     IIIIIII  NN   NN DDDDDD   EEEEEEE  XX   XX  EEEEEEE   SSSSS " << LIGHT_BLUE << "   OOOOO   " << CYAN << "    OOOOO   " << WHITE << "    OOOOO  \n";

                this_thread::sleep_for(chrono::seconds(1));

                clearScreen();
middle.setVolume(20);
     

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";   
    cout << 
"                                       FFFFFFF IIIIIII RRRRRRR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO  TTTTTTT  SSSSSS" << YELLOW << "    OOOOO \n"<<RESET;
cout<<
"                                       FF        III   RR   RR    III   NNN  NN GG          SS      HH   HH OO     OO   TTT   SS     " << YELLOW << "   OOOOOOO \n"<<RESET;
fire.play();
cout<<"                                       FFFFF     III   RRRRRRR    III   NN N NN GG  GGGG     SSSSS  HHHHHHH OO     OO   TTT    SSSSS " << YELLOW << "   OOOOOOO \n"<<RESET<<
"                                       FF        III   RR  RR     III   NN  NNN GG    GG         SS HH   HH OO     OO   TTT        SS" << YELLOW << "   OOOOOOO \n"<<RESET;
cout<<
"                                       FF      IIIIIII RR   RR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO    TTT   SSSSSSS" << YELLOW << "    OOOOO  \n"<<RESET;   

                this_thread::sleep_for(chrono::seconds(1));
    
                clearScreen();

                

                fire.play();

        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << 
"                                       FFFFFFF IIIIIII RRRRRRR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO  TTTTTTT  SSSSSS" << YELLOW << "   OOOOO   " << ORANGE << "    OOOOO  \n"<<RESET<<
"                                       FF        III   RR   RR    III   NNN  NN GG          SS      HH   HH OO     OO   TTT   SS     " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO \n"<<RESET;
cout<<
"                                       FFFFF     III   RRRRRRR    III   NN N NN GG  GGGG     SSSSS  HHHHHHH OO     OO   TTT    SSSSS " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO \n"<<RESET;
fire.play();
cout<<"                                       FF        III   RR  RR     III   NN  NNN GG    GG         SS HH   HH OO     OO   TTT        SS" << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO \n"<<RESET<<
"                                       FF      IIIIIII RR   RR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO    TTT   SSSSSSS" << YELLOW << "   OOOOO   " << ORANGE << "    OOOOO  \n"<<RESET;
    
                this_thread::sleep_for(chrono::seconds(1));
                clearScreen();
                fire.play();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout << 
"                                       FFFFFFF IIIIIII RRRRRRR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO  TTTTTTT  SSSSSS" << YELLOW << "   OOOOO   " << ORANGE << "    OOOOO   " << RED << "    OOOOO  \n"<<RESET;

cout<<
"                                       FF        III   RR   RR    III   NNN  NN GG          SS      HH   HH OO     OO   TTT   SS     " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO  " << RED << "   OOOOOOO \n"<<RESET<<
"                                       FFFFF     III   RRRRRRR    III   NN N NN GG  GGGG     SSSSS  HHHHHHH OO     OO   TTT    SSSSS " << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO  " << RED<< "   OOOOOOO \n"<<RESET;

fire.play();
cout<<
"                                       FF        III   RR  RR     III   NN  NNN GG    GG         SS HH   HH OO     OO   TTT        SS" << YELLOW << "  OOOOOOO  " << ORANGE << "   OOOOOOO  " << RED << "   OOOOOOO \n"<<RESET<<
"                                       FF      IIIIIII RR   RR  IIIIIII NN   NN  GGGGGGG    SSSSSSS HH   HH  OOOOOOO    TTT   SSSSSSS" << YELLOW << "   OOOOO   " << ORANGE << "    OOOOO   " << RED << "    OOOOO  \n"<<RESET;
    
            sf::SoundBuffer soundbuffer4;
   
            if(!(soundbuffer4.loadFromFile("../assets/miss.wav")))
            cout<<"Unable to load miss.wav\n";
   
            sf::Sound miss(soundbuffer4);
            miss.play();

   
            this_thread::sleep_for(chrono::seconds(1));
            miss.play();
   
            this_thread::sleep_for(chrono::seconds(1));
            miss.play();

   
            this_thread::sleep_for(chrono::seconds(1));
            middle.setVolume(100);
   
            clearScreen();
    cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
        cout << 
"                                                                          RRRRRRR  EEEEEEE   SSSSS   UU   UU  LL       TTTTTTT\n"
"                                                                          RR   RR  EE       SS       UU   UU  LL         TTT  \n"
"                                                                          RRRRRRR  EEEEE     SSSSS   UU   UU  LL         TTT  \n"
"                                                                          RR  RR   EE            SS  UU   UU  LL         TTT  \n"
"                                                                          RR   RR  EEEEEEE   SSSSS    UUUUU   LLLLLLL    TTT  \n";
        cout<<WHITE<<"      ==============================================================================================================================================================================================\n\n";
   
        printBoard(opponentBoard,h);// calling again to display
        
   
        getchar();
   
        clearScreen();
        
    }

        void vsComputer(char board1[10][10], char board2[10][10]) // MAIN PVC function
{
   
    sf::SoundBuffer buffer5;
   
    if(!(buffer5.loadFromFile("../assets/in.wav")))  
    cout<<"EROOR loading in.wav\n";
   
    sf::Sound enter(buffer5); 
    sf::SoundBuffer soundBuffer2;

    if (!soundBuffer2.loadFromFile("../assets/middle.wav")) 
    cout << "Error loading middle.wav\n";
 
    sf::Sound middle(soundBuffer2);
    
    int y;
    do  
    {
        clearScreen();
        int flagredo1 = 0, flagredo2 = 0;
        if (playercount == 1)
        {
            shipcolour = shipcolor();
            clearScreen();
            int x;

            start1:

            if (flagredo1)
            {
                flag1 = 0;
                flag2 = 0;
                flag3 = 0;
                flag4 = 0;
                flag5 = 0;

                flagredo1 = 0;
            }


            initializeBoard(board1);
            printBoard(board1, h);

            cout << "Do You Want to place all the ships Randomly or manually?\n1.Randomly\n2.Manually\n";

            int r;
            cin >> r;
            enter.play();

            while (r < 1 || r > 2)
            {
                cout << "Invalid Input\n";
                cout << "Do You Want to place all the ships Randomly or manually?\n1.Randomly\n2.Manually\n";
                int r;
                cin >> r;
                enter.play();
            }
            
            clearScreen();
            if (r == 2)
            {
                shipplacement(board1);   // ship 1
                
                clearScreen();

                shipplacement(board1);   // ship 2
                
                clearScreen();

                shipplacement(board1);   // ship 3
                
                clearScreen();

                shipplacement(board1);   // ship 4
                
                clearScreen();

                shipplacement(board1);   // ship 5

                cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2.\n";
                cin >> x;
                enter.play();

                while (x > 2 || x < 1)
                {
                    cout << "INVALID INPUT!\n";
                    cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2\n";
                    cin >> x;
                    enter.play();
                }

                if (x == 1)
                {
                    initializeBoard(board1);
                    flagredo1 = 1;
                    goto start1;
                }
            }
            else
            {
                clearScreen();
                start11:
                setRandomShips(board1);
                printBoard(board1, h);

                cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2.\n";
                cin >> y;
                enter.play();

                while (y > 2 || y < 1)
                {
                    cout << "INVALID INPUT!\n";
                    cout << "Are These Ships OK or You want to Place AGAIN!! If YES then press 1 ELSE press 2\n";
                    cin >> y;
                    enter.play();
                }

                if (y == 1)
                {
                    clearBoard(board1);
                    clearScreen();
                    goto start11;
                }

            }
            
        }
        else
            {              
                initializeBoard(board2);
                setRandomShips(board2);
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << 
"                                            CCCCC   OOOOOOO  MM    MM  PPPPPP   UU   UU  TTTTTTT  EEEEEEE  RRRRRRR      IIIIIII    SSSSS \n"
"                                           CC      OO     OO MMM  MMM  PP   PP  UU   UU    TTT    EE       RR   RR        III     SS     \n"
"                                           CC      OO     OO MM MM MM  PPPPPP   UU   UU    TTT    EEEEE    RRRRRRR        III      SSSSS \n"
"                                           CC      OO     OO MM    MM  PP       UU   UU    TTT    EE       RR  RR         III          SS\n"
"                                            CCCCC   OOOOOOO  MM    MM  PP        UUUUU     TTT    EEEEEEE  RR   RR      IIIIIII    SSSSS \n";
                cout<<"\n\n";
                cout << 
"                                      PPPPPP   LL       AAAA     CCCCC  IIIIIII NN   NN  GGGGGGG       SSSSS  HH   HH  IIIIIII  PPPPPP    SSSSS " << YELLOW << "   OOOOO  \n"<<RESET<<
"                                      PP   PP  LL      AA  AA   CC        III   NNN  NN GG            SS      HH   HH    III    PP   PP  SS     " << YELLOW << "  OOOOOOO \n"<<RESET<<
"                                      PPPPPP   LL      AAAAAA   CC        III   NN N NN GG  GGGG       SSSSS  HHHHHHH    III    PPPPPP    SSSSS " << YELLOW << "  OOOOOOO \n"<<RESET<<
"                                      PP       LL      AA  AA   CC        III   NN  NNN GG    GG           SS HH   HH    III    PP            SS" << YELLOW << "  OOOOOOO \n"<<RESET<<
"                                      PP       LLLLLLL AA  AA    CCCCC  IIIIIII NN   NN  GGGGGGG       SSSSS  HH   HH  IIIIIII  PP        SSSSS " << YELLOW << "   OOOOO  \n"<<RESET;


                this_thread::sleep_for(chrono::seconds(1));

                clearScreen();

                                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << 
"                                            CCCCC   OOOOOOO  MM    MM  PPPPPP   UU   UU  TTTTTTT  EEEEEEE  RRRRRRR      IIIIIII    SSSSS \n"
"                                           CC      OO     OO MMM  MMM  PP   PP  UU   UU    TTT    EE       RR   RR        III     SS     \n"
"                                           CC      OO     OO MM MM MM  PPPPPP   UU   UU    TTT    EEEEE    RRRRRRR        III      SSSSS \n"
"                                           CC      OO     OO MM    MM  PP       UU   UU    TTT    EE       RR  RR         III          SS\n"
"                                            CCCCC   OOOOOOO  MM    MM  PP        UUUUU     TTT    EEEEEEE  RR   RR      IIIIIII    SSSSS \n";
                cout<<"\n\n";

cout << 
"                                      PPPPPP   LL       AAAA     CCCCC  IIIIIII NN   NN  GGGGGGG       SSSSS  HH   HH  IIIIIII  PPPPPP    SSSSS " << YELLOW << "   OOOOO   " << CYAN << "    OOOOO  \n"<<RESET<<
"                                      PP   PP  LL      AA  AA   CC        III   NNN  NN GG            SS      HH   HH    III    PP   PP  SS     " << YELLOW << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"<<RESET<<
"                                      PPPPPP   LL      AAAAAA   CC        III   NN N NN GG  GGGG       SSSSS  HHHHHHH    III    PPPPPP    SSSSS " << YELLOW << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"<<RESET<<
"                                      PP       LL      AA  AA   CC        III   NN  NNN GG    GG           SS HH   HH    III    PP            SS" << YELLOW << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"<<RESET<<
"                                      PP       LLLLLLL AA  AA    CCCCC  IIIIIII NN   NN  GGGGGGG       SSSSS  HH   HH  IIIIIII  PP        SSSSS " << YELLOW << "   OOOOO   " << CYAN << "    OOOOO  \n"<<RESET;


                this_thread::sleep_for(chrono::seconds(1));

                clearScreen();

             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << 
"                                            CCCCC   OOOOOOO  MM    MM  PPPPPP   UU   UU  TTTTTTT  EEEEEEE  RRRRRRR      IIIIIII    SSSSS \n"
"                                           CC      OO     OO MMM  MMM  PP   PP  UU   UU    TTT    EE       RR   RR        III     SS     \n"
"                                           CC      OO     OO MM MM MM  PPPPPP   UU   UU    TTT    EEEEE    RRRRRRR        III      SSSSS \n"
"                                           CC      OO     OO MM    MM  PP       UU   UU    TTT    EE       RR  RR         III          SS\n"
"                                            CCCCC   OOOOOOO  MM    MM  PP        UUUUU     TTT    EEEEEEE  RR   RR      IIIIIII    SSSSS \n";
                cout<<"\n\n";                                         
cout << 
"                                      PPPPPP   LL       AAAA     CCCCC  IIIIIII NN   NN  GGGGGGG       SSSSS  HH   HH  IIIIIII  PPPPPP    SSSSS " << YELLOW << "   OOOOO   " << CYAN << "    OOOOO  \n"<<RESET<<
"                                      PP   PP  LL      AA  AA   CC        III   NNN  NN GG            SS      HH   HH    III    PP   PP  SS     " << YELLOW << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"<<RESET<<
"                                      PPPPPP   LL      AAAAAA   CC        III   NN N NN GG  GGGG       SSSSS  HHHHHHH    III    PPPPPP    SSSSS " << YELLOW << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"<<RESET<<
"                                      PP       LL      AA  AA   CC        III   NN  NNN GG    GG           SS HH   HH    III    PP            SS" << YELLOW << "  OOOOOOO  " << CYAN << "   OOOOOOO \n"<<RESET<<
"                                      PP       LLLLLLL AA  AA    CCCCC  IIIIIII NN   NN  GGGGGGG       SSSSS  HH   HH  IIIIIII  PP        SSSSS " << YELLOW << "   OOOOO   " << CYAN << "    OOOOO  \n"<<RESET;


                this_thread::sleep_for(chrono::seconds(1));

                clearScreen();

                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
               
            }

        playercount++;

    } while (playercount != 3);

    int ext=0;
        int count = 0;
        int score1 = 0;
        int score2 = 0;
        middle.pause();
        while(true)
        {

            if (count % 2 == 0)
            {
                playerAttack(board2, score1);
            }
                
            else
                computerAttack(board1, score1);

            count++;

            for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(board1[i][j]=='X')
                        ext++;
                    }
                }
                if(ext>=17)
                break;
                else
                ext=0;

            for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        if(board2[i][j]=='X')
                        ext++;
                    }
                }
                if(ext>=17)
                break;
                else
                ext=0;
            
        }
}
 
        void displayResult() //the final function
        {

         
            sf::SoundBuffer soundBuffer7;

            if (!soundBuffer7.loadFromFile("../assets/last.wav"))
            cout << "Error loading middle.wav\n";

            sf::Sound last(soundBuffer7);


            last.play();
           

            string gameOver =
            "                                            GGGGGGGG      AAAAAAAA    MMMMM   MMMMM  EEEEEEEEE             OOOOOOO    VVV     VVV  EEEEEEEEE  RRRRRRRRR   \n"
            "                                           GGGGGGGGGG    AAAAAAAAAA   MMMMMM MMMMMM  EEEEEEEEE            OOOOOOOOO   VVV     VVV  EEEEEEEEE  RRRRRRRRRR  \n"
            "                                          GGG           AAA      AAA  MMMMMMMMMMMMM  EEE                 OOO     OOO  VVV     VVV  EEE        RRR     RRR \n"
            "                                          GGG           AAA      AAA  MMM MMMMM MMM  EEEEEEE             OOO     OOO   VVV   VVV   EEEEEE     RRR     RRR \n"
            "                                          GGG    GGGGG  AAAAAAAAAAAA  MMM  MMM  MMM  EEEEEEE             OOO     OOO   VVV   VVV   EEEEEE     RRRRRRRRRR  \n"
            "                                          GGG    GGGGG  AAAAAAAAAAAA  MMM       MMM  EEE                 OOO     OOO    VVV VVV    EEE        RRRRRRRRR   \n"
            "                                          GGG      GGG  AAA      AAA  MMM       MMM  EEE                 OOO     OOO    VVV VVV    EEE        RRR   RRR   \n"
            "                                           GGGGGGGGGG   AAA      AAA  MMM       MMM  EEEEEEEEE            OOOOOOOOO      VVVVV     EEEEEEEEE  RRR    RRR  \n";
            cout<<"\n\n\n";

            int count=0;
            clearScreen();
                for(int i=0;i<gameOver.length();i++)

                {
                    if(count%2==0)    
                    {
                        cout<<RED<<gameOver[i]<<flush;
                        this_thread::sleep_for(chrono::milliseconds(3));

                    }    
                    else
                    {
                        cout<<WHITE<<gameOver[i]<<flush;
                        this_thread::sleep_for(chrono::milliseconds(7));
                    }   
                    count++;      
                        
                } 
                        // this_thread::sleep_for(chrono::milliseconds(3));           
                



           
                if(choice_player==1&&player1Score>player2Score)
                {
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout <<GREEN<< 
        "                PPPPPP   LL       AAAA     YY   YY  EEEEEEE  RRRRRRR  "<<WHITE<<"    11   "<<GREEN<<"  IIIIIII   SSSSS      VV     VV  IIIIIII   CCCCC  TTTTTTT   OOOOOOO  RRRRRRR  IIIIIII   OOOOOOO  UU   UU   SSSSS \n"
        "                PP   PP  LL      AA  AA     YY YY   EE       RR   RR  "<<WHITE<<"  1111  "<<GREEN<<"     III    SS          VV     VV    III    CC        TTT    OO     OO RR   RR    III    OO     OO UU   UU  SS     \n"
        "                PPPPPP   LL      AAAAAA      YYY    EEEEE    RRRRRRR  "<<WHITE<<"    11   "<<GREEN<<"    III     SSSSS       VV   VV     III    CC        TTT    OO     OO RRRRRR     III    OO     OO UU   UU   SSSSS \n"
        "                PP       LL      AA  AA      YY     EE       RR  RR    "<<WHITE<<"   11   "<<GREEN<<"    III         SS       VV VV      III    CC        TTT    OO     OO RR   R     III    OO     OO UU   UU       SS\n"
        "                PP       LLLLLLL AA  AA      YY     EEEEEEE  RR   RR   "<<WHITE<<" 111111 "<<GREEN<<"   IIIII    SSSSS         VVV     IIIIIII   CCCCC    TTT     OOOOOOO  RR   RR  IIIIIII   OOOOOOO   UUUUU    SSSSS \n"<<RESET;
                   cout<<endl<<endl<<endl<<endl<<"                     YOUR "<<"SCORE WAS:"<<GREEN<<player1Score<<RESET;
                    cout<<"                     PLAYER 2"<<" SCORE WAS:"<<RED<<player2Score;

                    this_thread::sleep_for(chrono::seconds(2));


                    
                    
                }
                else if(choice_player==2&&!(player1Score>player2Score))
                {
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        cout << 
        "                                                 CCCCC   OOOOOOO  MM    MM  PPPPPP   UU   UU  TTTTTTT  EEEEEEE  RRRRRRR     WW     WW   OOOOOOO  NN   NN \n"
        "                                                CC      OO     OO MMM  MMM  PP   PP  UU   UU    TTT    EE       RR   RR     WW     WW  OO     OO NNN  NN \n"
        "                                                CC      OO     OO MM MM MM  PPPPPP   UU   UU    TTT    EEEEE    RRRRRRR     WW  W  WW  OO     OO NN N NN \n"
        "                                                CC      OO     OO MM    MM  PP       UU   UU    TTT    EE       RR  RR       WWWWWWW   OO     OO NN  NNN \n"
        "                                                 CCCCC   OOOOOOO  MM    MM  PP        UUUUU     TTT    EEEEEEE  RR   RR       W   W     OOOOOOO  NN   NN \n"<<RESET;

                     cout<<endl<<endl<<endl<<endl<<"                     YOUR "<<"SCORE RESET WAS:"<<RED<<player1Score<<RESET;
                    cout<<"                     COMPUTER"<<" SCORE WAS:"<<GREEN<<player2Score;

                    this_thread::sleep_for(chrono::seconds(2));


                }
                else 
                {
                    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout <<GREEN 
        "                PPPPPP   LL       AAAA      YY   YY  EEEEEEE  RRRRRRR   "<<WHITE<<"    222222  "<<GREEN<<" IIIIIII   SSSSS      VV     VV  IIIIIII   CCCCC  TTTTTTT   OOOOOOO  RRRRRRR  IIIIIII   OOOOOOO  UU   UU   SSSSS \n"
        "                PP   PP  LL      AA  AA      YY YY   EE       RR   RR   "<<WHITE<<"  22    22  "<<GREEN<<"   III    SS          VV     VV    III    CC        TTT    OO     OO RR   RR    III    OO     OO UU   UU  SS     \n"
        "                PPPPPP   LL      AAAAAA       YYY    EEEEE    RRRRRRR    "<<WHITE<<"      22   "<<GREEN<<"   III     SSSSS       VV   VV     III    CC        TTT    OO     OO RRRRRRR    III    OO     OO UU   UU   SSSSS \n"
        "                PP       LL      AA  AA       YY     EE       RR  RR     "<<WHITE<<"   22      "<<GREEN<<"   III         SS       VV VV      III    CC        TTT    OO     OO RR  RR     III    OO     OO UU   UU       SS\n"
        "                PP       LLLLLLL AA  AA       YY     EEEEEEE  RR   RR    "<<WHITE<<" 22222222  "<<GREEN<<"IIIIIII    SSSSS         VVV     IIIIIII   CCCCC    TTT     OOOOOOO  RR   RR  IIIIIII   OOOOOOO   UUUUU    SSSSS \n"<<RESET;

                     cout<<endl<<endl<<endl<<endl<<"                     YOUR "<<"SCORE WAS:"<<GREEN<<player1Score<<RESET;
                    cout<<"                     PLAYER 1"<<" SCORE WAS:"<<RED<<player2Score;
            
            this_thread::sleep_for(chrono::seconds(2));

                }
                
            
           
            
                

          cout<<endl<<endl<<endl<<endl<<RESET;
          cout<<"                     Enter any Key to "<<RED"Exit"<<RESET" the game";
            char c;
           c= getchar();
            }

        void ABOUT() 
{

     cout<<RESET<<"      ==============================================================================================================================================================================================\n\n";

    cout <<GREEN<< 
"                                 AAAA     BBBBBB    OOOOOOO   UU   UU  TTTTTTT      TTTTTTT  HH   HH  EEEEEEE      GGGGGGG     AAAA     MM    MM  EEEEEEE \n"
"                                AA  AA    BB   BB  OO     OO  UU   UU    TTT          TTT    HH   HH  EE          GG          AA  AA    MMM  MMM  EE      \n"
"                                AAAAAA    BBBBBB   OO     OO  UU   UU    TTT          TTT    HHHHHHH  EEEEE       GG  GGGG    AAAAAA    MM MM MM  EEEEE   \n"
"                                AA  AA    BB   BB  OO     OO  UU   UU    TTT          TTT    HH   HH  EE          GG    GG    AA  AA    MM    MM  EE      \n"
"                                AA  AA    BBBBBB    OOOOOOO    UUUUU     TTT          TTT    HH   HH  EEEEEEE      GGGGGGG    AA  AA    MM    MM  EEEEEEE \n\n\n\n\n"<<RED;
    char b;

            string ABOUT = "                               This game simulation demonstrates practical experience in C++ programming, including\n"
          "                               the use of arrays, functions, control structures, and basic modular design.\n\n" 
          "                               It shows skill in game logic design, such as implementing turn-based gameplay,\n" 
          "                               enforcing rules, detecting win conditions, and handling collision checks.\n\n" 
          "                               The project also highlights the development of a terminal-based user interface\n "
          "                               using ANSI color codes and ASCII art, along with effective input validation.\n\n"
          "                               Additionally, it integrates audio using SFML Audio for event-driven sound\n"
          "                               effects, enhancing the overall gameplay experience.\n\n"
          "                               Finally, it reflects strong problem-solving abilities, including managing\n"
          "                               multiple game states and addressing edge cases in gameplay flow.\n\n"
         "                               Overall, this project represents a solid foundation in software development\n\n" 
          "                               principles and provides a stepping stone toward advanced programming.\n\n\n\n\n\n";


          for(int i=0;i<ABOUT.length();i++)

        {           
            cout<<WHITE<<ABOUT[i]<<flush;
            
            this_thread::sleep_for(chrono::milliseconds(7));           
        }


          cout<<RESET<<"ENTER ANY KEY"<<RED<<" TO EXIT"<<RESET;
          char a;

          cin.ignore();
           a= getchar();

          clearScreen();
}     