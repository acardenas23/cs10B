#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &jerseyNum, const vector<int> &playerRating){
    cout << "ROSTER" << endl;

    int s = 0;
    s = jerseyNum.size();
    for (int i = 0; i < s; ++i){
        cout << "Player " << i+1 << " -- Jersey number: " <<jerseyNum.at(i) << ", Rating: " << playerRating.at(i) << endl;
    }

    
}

void addPlayer(vector<int> &jerseyNum, vector<int> &playerRating){
    int jn;
    int pr;
    cout << "Enter another player's jersey number:" << endl;
    cin >> jn;
    cout << "Enter another player's rating:" << endl ;
    cin >> pr;

    jerseyNum.push_back(jn);
    playerRating.push_back(pr);

}

void removePlayer(vector<int> &jerseyNum, vector<int> &playerRating){
    int jn;
    cout << "Enter a jersey number:" << endl;
    cin >> jn;

    int s = 0;
    s = jerseyNum.size();
    for (int i = 0; i < s; ++i){
        if (jerseyNum.at(i) == jn){
            jerseyNum.erase(jerseyNum.begin()+i);
            playerRating.erase(playerRating.begin()+i);
            s = jerseyNum.size();
        }
    }
}
void updatePlayerRating(const vector<int> &jerseyNum, vector<int> &playerRating){
    int jn;
    int pr;
    cout << "Enter a jersey number:" << endl;
    cin >> jn;
    cout << "Enter a new rating for player" << endl;
    cin >> pr;

    int s = 0;
    s = jerseyNum.size();
    for (int i = 0; i < s; ++i){
        if (jerseyNum.at(i)==jn){
            playerRating.at(i) = pr;
        }
    }


}
void outputPlayersAboveRating(const vector<int> &jerseyNum, const vector<int> &playerRating){
    int r;
    cout << "Enter a rating" << endl;
    cin >> r;
    cout << endl << "ABOVE " << r << endl;

    int s = 0;
    s = jerseyNum.size();
    for (int i = 0; i < s; ++i){
        if (playerRating.at(i) > r){
            cout << "Player " << i+1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << playerRating.at(i) << endl;
        }
    }
}

void menu(vector<int> &jerseyNum,vector<int> &playerRating){
    char in;
    cout << endl << "MENU" << endl;
    cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl << "o - Output roster" << endl <<  "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;   
    cin >> in;

    if (in == 'a'){
        addPlayer(jerseyNum,playerRating);
        menu(jerseyNum, playerRating);
    }
    else if (in == 'd'){
        removePlayer(jerseyNum,playerRating);
        menu (jerseyNum, playerRating);
    }
    else if (in == 'u'){
        updatePlayerRating(jerseyNum, playerRating);
        menu (jerseyNum, playerRating);
    }
    else if (in == 'r'){
        outputPlayersAboveRating(jerseyNum, playerRating);
        menu(jerseyNum, playerRating);
    }
    else if (in == 'o'){
        outputRoster(jerseyNum, playerRating);
        menu(jerseyNum, playerRating);
        }
}


int main() {

   vector<int> jerseyNum(5);
   vector<int> playerRating(5);

   int jn;
   int pr;

   for (int i = 0; i < 5; ++i){
       cout << "Enter player " << i+1 << "'s jersey number:" << endl;
       cin >> jn;
       jerseyNum.at(i) = jn;
       cout << "Enter player " << i+1 << "'s rating:" << endl;
       cin >> pr;
       cout << endl;
       playerRating.at(i) = pr;
   }

    outputRoster(jerseyNum, playerRating);
    menu(jerseyNum, playerRating);


   return 0;
}