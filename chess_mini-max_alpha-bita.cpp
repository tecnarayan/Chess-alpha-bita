#include<iostream>
#include<cmath>
#include<algorithm>
#define DEPTH 8
using namespace std;

int move_count = 2;


void copy(char c[10][10] , char dum[10][10]){
    for(int i = 0 ; i <= 8 ; i++){
        for(int j = 1 ; j <= 8 ; j++){
            dum[i][j] = c[i][j];
        }
    }
}

int wb(char c[10][10],int row , int column ){
    if(c[row][column] == 'p')return 1;
    if(c[row][column] == 'r')return 1;
    if(c[row][column] == 'b')return 1;
    if(c[row][column] == 'k')return 1;
    if(c[row][column] == 'q')return 1;
    if(c[row][column] == 'n')return 1;

    if(c[row][column] == 'P')return 0;
    if(c[row][column] == 'B')return 0;
    if(c[row][column] == 'N')return 0;
    if(c[row][column] == 'K')return 0;
    if(c[row][column] == 'Q')return 0;
    if(c[row][column] == 'R')return 0;

    else return 2;
}

void initialize_chess(char c[10][10]){

    for(int i = 0 ; i< 10 ; i++){
        for( int j = 0 ; j < 10 ; j ++){
            c[i][j]='-';
        }
    }

    c[1][1]='r';c[1][2]='n';c[1][3]='b';c[1][4]='k';c[1][5]='q';c[1][6]='b';c[1][7]='n';c[1][8]='r';
    c[8][1]='R';c[8][2]='N';c[8][3]='B';c[8][4]='K';c[8][5]='Q';c[8][6]='B';c[8][7]='N';c[8][8]='R';

    for(int i = 1 ; i < 9 ; i ++){
        c[2][i]='p';c[7][i]='P';
    }
    c[2][5] = '-';
    c[4][5] = 'p';
    c[0][1] = '1';c[0][2] = '1';c[0][3] = '1';c[0][4] = '1';c[0][5] = '0';c[0][6] = '0';c[0][7] = '0';c[0][8] = '0';
}

void printc(char c[10][10]){
cout<<"  ";
    for(int i = 0;i<47;i++)cout<<char(220);cout<<endl;

    cout<<"  "<<char(219)<<"     ";
        for (int j = 1 ; j < 9 ; j ++){
            cout<<" "<<"    ";
        }cout<<char(219)<<endl;

    for(int i = 1 ; i< 9 ; i++){
        cout<<i<<" "<<char(219)<<"     ";
        for (int j = 1 ; j < 9 ; j ++){
            cout<<c[i][j]<<"    ";
        }cout<<char(219)<<endl;

        cout<<"  "<<char(219)<<"     ";
        for (int j = 1 ; j < 9 ; j ++){
            cout<<" "<<"    ";
        }cout<<char(219)<<endl;


    }cout<<"  ";for(int i = 0;i<47;i++)cout<<char(223);cout<<endl;
    cout<<"  "<<" "<<"     "<<"h"<<"    "<<"g"<<"    "<<"f"<<"    "<<"e"<<"    "<<"d"<<"    "<<"c"<<"    "<<"b"<<"    "<<"a"<<endl<<endl<<endl<<endl;
}




int legal(char c[10][10], int ri, int ci, int rf, int cf, int future){ // ri = row intial , rf = row final 
    
    
    if( c[ri][ci] == '-')return 0;

    if( c[1][1] != 'r')c[0][1] = '0';
    if( c[1][8] != 'r')c[0][1] = '0';
    if( c[8][1] != 'R')c[0][1] = '0';
    if( c[8][8] != 'R')c[0][1] = '0';


    if((move_count % 2 == 1 || future == 1) && wb(c,ri,ci) == 1 && wb(c,rf,cf)!= 1){ // move of white
        if( c[ri][ci] == 'p'){
            if( ci == cf && c[rf][cf] == '-' && c[ri +1][ci] == '-' ){
                if( ri == 2){
                    if(rf - ri == 1)return 1;
                    if(rf - ri == 2)return 1;
                }
                else{
                    if(rf - ri == 1) return 1;
                }
            }

            if( int(abs(ci - cf)) == 1  && (rf - ri) == 1  && (wb(c,rf,cf) == 0 )){
                return 1;
            }
        }

        if( c[ri][ci] == 'r'){

            if( ri == 1 && ci == 1 ){
                if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][1]='0'; return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][1]='0'; return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][1]='0'; return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][1]='0'; return 1;
                }
            } 
            }

            if( ri == 1 && ci == 8 ){
                if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][2]='0'; return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][2]='0'; return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][2]='0'; return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][2]='0'; return 1;
                }
            } 
            }
            
            if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }
            } 
        }

        if( c[ri][ci] == 'n'){

            if( int(abs(rf-ri)) == 2 && int(abs(ci - cf)) == 1 )return 1;
            if( int(abs(rf-ri)) == 1 && int(abs(ci - cf)) == 2 )return 1;
            
        }

        if( c[ri][ci] == 'b'){

            if( int(abs(rf-ri)) == int(abs(ci - cf)) ){

                if( ri < rf && ci < cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci + i] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci < cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci + i] != '-')return 0;
                    }return 1;
                }

                if( ri < rf && ci > cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci - i] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci > cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci - i] != '-')return 0;
                    }return 1;
                }
            }
            
        }

        if( c[ri][ci] == 'k'){

            if( ri == 1 && ci == 4){
                if(int(abs(rf-ri)) <= 1 && int(abs(ci - cf)) <= 1 ){
                    c[0][1]='0';
                    c[0][2]='0';
                    return 1;
                }
            }

            if(int(abs(rf-ri)) <= 1 && int(abs(ci - cf)) <= 1 )return 1;

            if( ri == 1 && rf == 1 && ci == 4 && cf == 2 && c[0][1] == '1' && c[1][2] == '-' && c[1][3] == '-' && c[1][1] == 'r'){

                c[0][1]='0';
                c[0][2]='0';

                return 1;
                
            }

            if( ri == 1 && rf == 1 && ci == 4 && cf == 6 && c[0][2] == '1' && c[1][5] == '-' && c[1][6] == '-' && c[1][7] == '-' && c[1][8] == 'r'){

                c[0][1]='0';
                c[0][2]='0';

                return 1;
                
            }
            
        }

        if( c[ri][ci] == 'q'){

            if( int(abs(rf-ri)) == int(abs(ci - cf)) ){

                if( ri < rf && ci < cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci + i] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci < cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci + i] != '-')return 0;
                    }return 1;
                }

                if( ri < rf && ci > cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci - i] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci > cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci - i] != '-')return 0;
                    }return 1;
                }
            }

            if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }
            } 
            
        }
    }

    if((move_count % 2 == 0 || future == 1 )&& wb(c,ri,ci) == 0 && wb(c,rf,cf)!= 0){ // move of black
        if( c[ri][ci] == 'P'){
            if( ci == cf && c[rf][cf] == '-' && c[ri -1][ci] == '-'){
                if( ri == 7){
                    if(rf - ri == -1)return 1;
                    if(rf - ri == -2)return 1;
                }
                else{
                    if(rf - ri == -1) return 1;
                }
            }

            if( int(abs(ci - cf)) == 1  && (rf - ri) == -1  && (wb(c,rf,cf) == 1)){
                return 1;
            }
        }

        if( c[ri][ci] == 'R'){

            if( ri == 8 && ci == 1 ){
                if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][3]='0'; return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][3]='0'; return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][3]='0'; return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][3]='0'; return 1;
                }
            } 
            }

            if( ri == 8 && ci == 8 ){
                if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][4]='0'; return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }c[0][4]='0';return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][4]='0'; return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }c[0][4]='0'; return 1;
                }
            } 
            }
            
            if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }
            } 
        }

        if( c[ri][ci] == 'N'){

            if( int(abs(rf-ri)) == 2 && int(abs(ci - cf)) == 1 )return 1;
            if( int(abs(rf-ri)) == 1 && int(abs(ci - cf)) == 2 )return 1;
            
        }

        if( c[ri][ci] == 'B'){

            if( int(abs(rf-ri)) == int(abs(ci - cf)) ){

                if( ri < rf && ci < cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci + 1] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci < cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci + 1] != '-')return 0;
                    }return 1;
                }

                if( ri < rf && ci > cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci - 1] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci > cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci - 1] != '-')return 0;
                    }return 1;
                }
            }
            
        }

        if( c[ri][ci] == 'K'){

            if( ri == 8 && ci == 4){
                if(int(abs(rf-ri)) <= 1 && int(abs(ci - cf)) <= 1 ){
                    c[0][3] = '0';
                    c[0][4] = '0';
                    return 1;
                }
            }

            if(int(abs(rf-ri)) <= 1 && int(abs(ci - cf)) <= 1 )return 1;

            if( ri == 8 && rf == 8 && ci == 4 && cf == 2 && c[0][3] == '1' && c[8][2] == '-' && c[8][3] == '-'&& c[8][1] == 'R'){

                c[0][3] = '0';
                c[0][4] = '0';

                return 1;
                
            }

            if( ri == 8 && rf == 8 && ci == 4 && cf == 6 && c[0][4] == '1' && c[8][5] == '-' && c[8][6] == '-' && c[8][7] == '-' && c[8][8] == 'R'){

                c[0][3] = '0';
                c[0][4] = '0';

                return 1;
                
            }
            
        }

        if( c[ri][ci] == 'Q'){

            if( int(abs(rf-ri)) == int(abs(ci - cf)) ){

                if( ri < rf && ci < cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci + 1] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci < cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci + 1] != '-')return 0;
                    }return 1;
                }

                if( ri < rf && ci > cf ){
                    for(int i = 1 ; i <= rf - ri - 1 ; i++ ){
                        if( c[ri + i][ci - 1] != '-')return 0;
                    }return 1;
                }

                if( ri > rf && ci > cf ){
                    for(int i = 1 ; i <= ri - rf - 1 ; i++ ){
                        if( c[ri - i][ci - 1] != '-')return 0;
                    }return 1;
                }
            }

            if( int(abs(rf-ri)) == 0 || int(abs(ci - cf)) == 0  ) {
                if(rf > ri ){
                    for (int i = ri +1 ; i <= rf - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(rf < ri ){
                    for (int i = rf +1 ; i <= ri - 1 ; i ++){
                        if( c[i][ci] != '-') return 0;
                    }return 1;
                }

                if(cf < ci ){
                    for (int i = cf +1 ; i <= ci - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }

                if(cf > ci ){
                    for (int i = ci +1 ; i <= cf - 1 ; i ++){
                        if( c[ri][i] != '-') return 0;
                    }return 1;
                }
            } 
            
        }
    }



    else return 0;

return 0;
}

void deploy(char c[10][10] , int ri , int ci , int rf , int cf ){
    if(ri == 1 && ci == 4 && rf == 1 && cf == 2 && c[ri][ci] == 'k' && c[1][1]== 'r'){
        c[ri][ci]='-';
        c[rf][cf]='k';
        c[1][1]= '-';
        c[1][3] = 'r';
        c[0][5] = '1';
    }
    if(ri == 1 && ci == 4 && rf == 1 && cf == 6 && c[ri][ci] == 'k'&& c[1][8]== 'r'){
        c[ri][ci]='-';
        c[rf][cf]='k';
        c[1][8]= '-';
        c[1][7]= '-';
        c[1][5] = 'r';
        c[0][6] = '1';
    }
    if(ri == 8 && ci == 4 && rf == 8 && cf == 2 && c[ri][ci] == 'K' && c[8][1]== 'R'){
        c[ri][ci]='-';
        c[rf][cf]='K';
        c[8][1]= '-';
        c[8][3] = 'R';
        c[0][7] = '1';
    }
    if(ri == 8 && ci == 4 && rf == 8 && cf == 6 && c[ri][ci] == 'K'&& c[8][8]== 'R'){
        c[ri][ci]='-';
        c[rf][cf]='K';
        c[8][8]= '-';
        c[8][7]= '-';
        c[9][5] = 'R';
        c[0][8] = '1';
    }
    
    c[rf][cf] = c[ri][ci];
    c[ri][ci] = '-';

    for(int i = 1 ; i <= 8 ; i++ ){
        if( c[1][i] == 'P')c[1][i] = 'Q';
    }
    for(int i = 1 ; i <= 8 ; i++ ){
        if( c[8][i] == 'p')c[8][i] = 'q';
    }

}


int evaluation(char c[10][10]){

double score = 0;

int bishop_w = 0;
int bishop_b = 0;

for(int row = 1 ; row <= 8 ; row ++){
    for(int column = 1 ; column <= 8 ; column++){
        if(c[row][column] != '-'){
            if(c[row][column] == 'p'){
                score += 1;
                
            }
            if(c[row][column] == 'r'){
                score += 5;
            }
            if(c[row][column] == 'b'){
                score += 3;
                bishop_w ++;
                if(bishop_w == 2)score += 0.5;
                if(move_count <= 30){
                    score += (1.0*row/8.0);
                }

                
            }
            if(c[row][column] == 'k'){
                score += 500;
                if(move_count <= 60){
                    if(row == 8 && column == 2)score+=0.99;
                    if(row == 8 && column == 7)score+=0.60;
                }    

            }
            if(c[row][column] == 'q'){
                score += 9;
                if(move_count <= 30){
                    score += (0.5*row/8.0);
                }
            }
            if(c[row][column] == 'n'){
                score += 3;
                if(move_count <= 30){
                    score += (1.0*row/8.0);
                }
            }

            if(c[row][column] == 'P'){
                score -= 1;
            }
            if(c[row][column] == 'B'){
                score -= 3;
                bishop_b ++;
                if(bishop_b == 2)score -= 0.5;
                if(move_count <= 30){
                    score -= (1.0*row/8.0);
                }
            }
            if(c[row][column] == 'N'){
                score -= 3;
                if(move_count <= 30){
                    score -= (1.0*row/8.0);
                }
            }
            if(c[row][column] == 'K'){
                score -= 500;
                if(move_count <= 60){
                    if(row == 1 && column == 2)score-=0.99;
                    if(row == 1 && column == 7)score-=0.60;
                }    
            }
            if(c[row][column] == 'Q'){
                score -= 9;
                if(move_count <= 30){
                    score -= (0.5*row/8.0);
                }
            }
            if(c[row][column] == 'R'){
                score -= 5;
            }
        }
    }

    

}
return score;

}





double minimax (char c[10][10] , int depth , double alpha , double bita ,bool maximizing_player , int &p){
int z;
if(depth == 0 || abs(evaluation(c))>300 ){
    return evaluation(c);
}

if(maximizing_player){
    double maxEval = -5000;
    for(int i = 8 ; i >= 1 ; i--){
        for(int j = 8 ; j >=1 ; j--){
            if(wb(c,i,j)==1){
                for(int r = 8 ; r >= 1 ; r-- ){
                    for(int cc = 8 ; cc >=1 ; cc--){
                        if(legal(c,i,j,r,cc,1)){
                            char dum[10][10];
                            copy(c,dum);
                            deploy(dum,i,j,r,cc);
                            double eval = minimax(dum,depth-1,alpha,bita,0,z);
                            double x = maxEval;
                            maxEval = max(maxEval , eval);
                            double y = maxEval;
                            if(y > x){ p = 1000*i + 100*j + 10*r + cc;}
                            alpha = max(alpha , eval);
                            if(bita <= alpha)return maxEval;


                        }
                    }
                }
            }
        }
    }return maxEval;

}


else{
    double minEval = +5000;
    for(int i = 1 ; i <= 8 ; i++){
        for(int j = 8 ; j >=1 ; j--){
            if(wb(c,i,j)==0){
                for(int r = 1 ; r <= 8 ; r++ ){
                    for(int cc = 8 ; cc >=1 ; cc--){
                        if(legal(c,i,j,r,cc,1)){
                            char dum[10][10];
                            copy(c,dum);
                            deploy(dum,i,j,r,cc);
                            double eval = minimax(dum,depth-1,alpha,bita,1,z);
                            minEval = min(minEval , eval);
                            bita = min(bita , eval);
                            if(bita <= alpha)return minEval;


                        }
                    }
                }
            }
        }
    }return minEval;

}

}


int main(){

/*
1) move_count : its an integer which is representing current move number will be what 
2) initialise : will keep chess pieces at starting position ( start of game )
3) printc : will print the chess board
4) legal : will tell if the move is legal ... 1 for yes ; 0 for no
5) wb : tell if its black or white ... 1 for white , 0 for black
6) castle_w_a , casrle_w_h , castle_b_a , castle_b_h ... these are = 1 till the time not castled and eligible
7) deploy
8) check_w , check_b ( TO BE DONE )
9) minimax
10) evaluation
11) copy
12)
13)
*/

char c[10][10];


initialize_chess(c);

printc(c);
int ri,rf,ci,cf;
int a,b;
char cc,d;

while(true){

while(true){
    cout<<endl<<"black:";
    cin>>cc>>a>>d>>b;
    ri = a;
    rf = b;
    if( cc == 'a')ci = 8;if( cc == 'b')ci = 7;if( cc == 'c')ci = 6;if( cc == 'd')ci = 5;if( cc == 'e')ci = 4;if( cc == 'f')ci = 3;if( cc == 'g')ci = 2;if( cc == 'h')ci = 1;
    if( d == 'a')cf = 8;if( d == 'b')cf = 7;if( d == 'c')cf = 6;if( d == 'd')cf = 5;if( d == 'e')cf = 4;if( d == 'f')cf = 3;if( d == 'g')cf = 2;if( d == 'h')cf = 1;

    if(legal(c,ri,ci,rf,cf,0)){
        deploy(c,ri,ci,rf,cf);
        move_count ++;
        cout<<endl;
        printc(c);
        cout<<endl<<endl<<endl;break;
    }

    else{
        cout<<endl;
        cout<<"illegal move . plz try again"<<endl;continue;
    }
}
int p;
double alpha = -5000;
double bita = 5000;
int k = minimax(c,DEPTH,alpha,bita,1,p);

deploy(c,p/1000,(p - (p/1000)*1000)/100, (p - (p/100)*100)/10 , p%10  );
move_count ++;
printc(c);
}
/*
while(true){

    while(true){
    cout<<endl<<"white:";
    cin>>cc>>a>>d>>b;
    ri = a;
    rf = b;
    if( cc == 'a')ci = 8;if( cc == 'b')ci = 7;if( cc == 'c')ci = 6;if( cc == 'd')ci = 5;if( cc == 'e')ci = 4;if( cc == 'f')ci = 3;if( cc == 'g')ci = 2;if( cc == 'h')ci = 1;
    if( d == 'a')cf = 8;if( d == 'b')cf = 7;if( d == 'c')cf = 6;if( d == 'd')cf = 5;if( d == 'e')cf = 4;if( d == 'f')cf = 3;if( d == 'g')cf = 2;if( d == 'h')cf = 1;

    if(legal(c,ri,ci,rf,cf)){
        deploy(c,ri,ci,rf,cf);
        move_count ++;
        cout<<endl;
        printc(c);
        cout<<endl<<endl<<endl;break;
    }

    else{
        cout<<endl;
        cout<<"illegal move . plz try again"<<endl;continue;
    }
    }

    while(true){
    cout<<endl<<"black:";
    cin>>cc>>a>>d>>b;
    ri = a;
    rf = b;
    if( cc == 'a')ci = 8;if( cc == 'b')ci = 7;if( cc == 'c')ci = 6;if( cc == 'd')ci = 5;if( cc == 'e')ci = 4;if( cc == 'f')ci = 3;if( cc == 'g')ci = 2;if( cc == 'h')ci = 1;
    if( d == 'a')cf = 8;if( d == 'b')cf = 7;if( d == 'c')cf = 6;if( d == 'd')cf = 5;if( d == 'e')cf = 4;if( d == 'f')cf = 3;if( d == 'g')cf = 2;if( d == 'h')cf = 1;

    if(legal(c,ri,ci,rf,cf)){
        deploy(c,ri,ci,rf,cf);
        move_count ++;
        cout<<endl;
        printc(c);
        cout<<endl<<endl<<endl;break;
    }

    else{
        cout<<endl;
        cout<<"illegal move . plz try again"<<endl;continue;
    }
    }
}*/

}