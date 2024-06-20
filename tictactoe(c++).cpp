#include<bits/stdc++.h>
using namespace std;

int cgame(int k[3][3]){
    int row = 0;
    int col = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            row += k[i][j];
            col += k[j][i];
        }
            if(row == 3 || col == 3){
                return 1;
            }else if(row == -3 || col == -3){
                return -1;
            }
        row = 0;
        col = 0;
    }
    for(int i=0; i<3; i++){
        row += k[i][i];
        col += k[i][2-i]; 
    }
    if(row == 3 || col == 3){
                return 1;
            }else if(row == -3 || col == -3){
                return -1;
            }

            return 0;
}

void input1(int k[3][3]){
    int i, j;
    cin >> i >> j;
    if(k[i][j] == 0){
        k[i][j] = 1;
    }else{
        cout << "Invalid! try again : ";
        input1(k);
    }
}
void input2(int k[3][3]){
    int i, j;
    cin >> i >> j;
    if(k[i][j] == 0){
        k[i][j] = -1;
    }else{
        cout << "Invalid! try again : ";
        input2(k);
    }
}

void printBoard(int k[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (k[i][j] == 1) {
                cout << " X ";
            } else if (k[i][j] == -1) {
                cout << " O ";
            } else {
                cout << " . ";
            }
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
}

int main(){
    int pos[3][3] = {0};
    int val;
    int counter=0;
    while(counter != 9){
        printBoard(pos);
        val = cgame(pos);
        
        if(val==1){cout<<"player1 wins" <<endl; break;}
        else if(val==-1){cout<<"player2 wins" <<endl; break;}
        
        if(counter%2 == 0){
            cout << "ENTER PLAYER1 : ";
            input1(pos);
            counter++;
        }else{
            cout << "ENTER PLAYER2 : ";
            input2(pos);
            counter++;
        }
    }
    if(val == 0){
        cout << " ========= " << endl;
        cout << "i[ DRAW! ]i" << endl;
        cout << " ========= " << endl;
        
    }
    
}
