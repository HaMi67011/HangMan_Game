#include<iostream>
#include<fstream>

using namespace std;

class Hangman
{
private:
    
    int tries;
    static int score ;
    string name_player;
    string word;
    char arr_player_input;

public:
    Hangman();
    void Print_hangman(int tries);
    int length(string);
    int random_num(int );
    char missing_letter(int , int ,string);
    void checking (int , string , char);
    void tries_left_Score();
    void run(Hangman);
    void storing(string, int);
};

int Hangman::score = 0;

Hangman::Hangman(){
    
    tries = 7;
    score = 0;
    cout << "ENTER THE NAME OF PLAYER ";
    cin >> name_player;
};


void Hangman::run(Hangman hangman){

    int num; 
    ifstream fin ; 
    fin.open("23.txt");
    while (true){
       

    fin >> hangman.word;

    if (fin.eof())
       break;
        
    string copy_letter = hangman.word;

    int length_word = hangman.length(hangman.word);
    int random_number = hangman.random_num(length_word);
    
        while(true){

            if (random_number<= length_word){
                char letter_missing = hangman.missing_letter(random_number,length_word,hangman.word);
                hangman.checking(random_number,copy_letter,letter_missing);
                hangman.tries_left_Score();
                hangman.storing(name_player,score);
                break;
            }
            else
                continue;                               
            

    }
    
    }
    fin.close();


}

int Hangman::length(string word){
    int length = word.length();

    return length;
}

int Hangman::random_num(int length_of_word){
    srand(time(0));
    int num = rand() % length_of_word;

    return num;
}

char Hangman::missing_letter(int num, int length ,string r){
    
    char missing;
    if(num <= length){
        r[num] = '_';
        cout << r << endl;
        cout << "ENTER THE MISSING LETTER ";
        cin >> missing;
    }
return missing;
}

void Hangman::checking(int num,string copy_letter,char missing){

     if (copy_letter[num] == missing){
        cout << "YOUR ANSWER IS CORRECT " << endl;
        score++;
        }
    else if (copy_letter[num] != missing){
        cout << "YOUR ANSWERS IS NOT CORRECT " << endl;
        if (tries > 0){
            tries--;
            Print_hangman(tries);
            }
        else{
            cout << endl <<"GAME OVER";
            }
        }
    }



void Hangman:: Print_hangman(int tries){

    if (tries == 7){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |            " << endl;
        cout << " |            " << endl;
        cout << " |            " << endl;
        cout << "_|_____________" << endl;
    }

    else if (tries == 6){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |         \\  " << endl;
        cout << " |            " << endl;
        cout << " |            " << endl;
        cout << "_|_____________" << endl;
    }

    else if (tries == 5){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |         \\O " << endl;
        cout << " |            " << endl;
        cout << " |            " << endl;
        cout << "_|_____________" << endl;
    }
    else if (tries == 4){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |         \\O/ " << endl;
        cout << " |            " << endl;
        cout << " |            " << endl;
        cout << "_|_____________" << endl;
    }

    else if (tries == 3){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |         \\O/ " << endl;
        cout << " |          |   " << endl;
        cout << " |            " << endl;
        cout << "_|_____________" << endl;
    }
     else if (tries == 2){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |         \\O/ " << endl;
        cout << " |          |   " << endl;
        cout << " |         /   " << endl;
        cout << "_|_____________" << endl;
    }
    else if (tries == 1){
        cout << " _____________" << endl;
        cout << " |          | " << endl;
        cout << " |         \\O/ " << endl;
        cout << " |          |   " << endl;
        cout << " |         / \\  " << endl;
        cout << "_|_____________" << endl;
    }
};

void Hangman::tries_left_Score(){

    cout << "TRIES ARE LEFT " << tries << endl;
    cout << "SCORE OF " << name_player << " IS " << score << endl;

};

void Hangman::storing(string name , int scores){

    ofstream out;
    out.open("score.txt",ios_base::app);

    out << name << " " << scores << endl;
    out.close();


}



int main(){

    Hangman hangman;

    char play_choice;

    do{
    
    hangman.run(hangman);
    cout << "DO YOU WANT TO PLAY AGAIN ?";
    cin >> play_choice;
    
    }
    while(play_choice == 'Y' || play_choice == 'y');


    return 0;
}