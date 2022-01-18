#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <math.h>
using namespace std;

int counterlist = 0;

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
void fileBuild(int size, float passArray[1000][8], bool debug){

    if(debug == true){
        cout << "Writing Data to file > NewData.txt" << endl;
    }

    ofstream MyFile("NewData.txt");
    MyFile << "Unit: ~~~~" << endl;
    MyFile << "R1   L1   R2   L2   R3   L3   R4   L4" << endl << endl;

    for(int i=0; i<size; i++){
        MyFile << passArray[i][0] << "    " << passArray[i][1] << "    " << passArray[i][2] 
        << "    " << passArray[i][3] << "    " << passArray[i][4] << "    " << passArray[i][5] 
        << "    " << passArray[i][6] << "    " << passArray[i][7] << endl;
    }

    MyFile.close();
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

double rand_double(){
    return ((double)rand())/((double)RAND_MAX);
}

double rand_double_int(double a, double b){
    return rand_double() * (b - a) + a;
    cout << "seeding process" << endl;
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

void arrayFill(int size, float passArray[1000][8], bool debug){          //This is a backup if the file does not edit a line
    passArray[size][0] = 0;
    passArray[size][1] = 0;
    passArray[size][2] = 0;
    passArray[size][3] = 0;
    passArray[size][4] = 0;
    passArray[size][5] = 0;
    passArray[size][6] = 0;
    passArray[size][7] = 0;
    for(int i=0; i<size; i++){
        while(passArray[i][0] == 0){
            double L1,R1,L2,R2,L3,R3,L4,R4,Math,ptOne,ptTwo,ptThree,ptFour;
            L1 = rand_double_int(0.02, 0.2);
            R1 = rand_double_int(0.25, 0.75);
            L2 = rand_double_int(0.02, 0.2);
            R2 = rand_double_int(0.25, 0.75);
            L3 = rand_double_int(0.02, 0.2);
            R3 = rand_double_int(0.25, 0.75);
            L4 = rand_double_int(0.02, 0.2);
            R4 = rand_double_int(0.25, 0.75);

            ptOne = (M_PI*(R1*R1)*L1);
            ptTwo = (M_PI*(R2*R2)*L2);
            ptThree = (M_PI*(R3*R3)*L3);
            ptFour = (M_PI*(R4*R4)*L4);
            Math = ((2500*ptOne)+(19250*ptTwo)+(2500*ptThree)+(2500*ptFour));
            if(Math <= 650){
                passArray[i][0] = R1 * 1000;
                passArray[i][1] = L1 * 1000;
                passArray[i][2] = R2 * 1000;
                passArray[i][3] = L2 * 1000;
                passArray[i][4] = R3 * 1000;
                passArray[i][5] = L3 * 1000;
                passArray[i][6] = R4 * 1000;
                passArray[i][7] = L4 * 1000;
            }
        }
    }
    if(debug == true){
        for(int i=0; i<size; i++){
            cout << passArray[i][0] << " " << passArray[i][1] << " " << passArray[i][2] << " " << passArray[i][3]
            << " " << passArray[i][4] << " " << passArray[i][5] << " " << passArray[i][6] << " " << passArray[i][7] << endl;
        }
        system("pause");
    }
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

void arrayRand(int size, float passArray[1000][8], int changeval, int rantry, bool debug){
    int numchanger;
    int caller;
    double L1,R1,L2,R2,L3,R3,L4,R4,Math,ptOne,ptTwo,ptThree,ptFour;
    int counter = 0;
    int parsArray[251];          //Must make 251 if running 1k
    int counterpars = 0;
    int countercent = 0;
    int counterset = 0;
    int countertemp = 0;

    for(int i=0; i<size; i++){
        if(passArray[i][0] != 0){
            parsArray[counterpars] = i;             //fills array with data of passArray Data location
            counterpars ++;
            if(debug == true){
                cout << i << endl;
            }
        }
    }
    if(debug == true){
        system("pause");
    }

    for(int j=0; j<size; j++){
        passArray[j][0] = passArray[j][0]/1000;
        passArray[j][1] = passArray[j][1]/1000;
        passArray[j][2] = passArray[j][2]/1000;
        passArray[j][3] = passArray[j][3]/1000;
        passArray[j][4] = passArray[j][4]/1000;
        passArray[j][5] = passArray[j][5]/1000;
        passArray[j][6] = passArray[j][6]/1000;
        passArray[j][7] = passArray[j][7]/1000;
        if(passArray[j][0] == 0){
            numchanger = rand() % changeval * 8;

            countertemp ++;

            for (int i=0; i<numchanger; i++){
                caller = rand() % 8 + 1;
                if(debug == true){
                    cout << caller << endl;
                }
                counter = 0;
                do{
                    
                    if(counterlist == 26){              //change data if error
                        break;
                    }
                        L1 = passArray[parsArray[counterlist]][0];
                        R1 = passArray[parsArray[counterlist]][1];
                        L2 = passArray[parsArray[counterlist]][2];
                        R2 = passArray[parsArray[counterlist]][3];
                        L3 = passArray[parsArray[counterlist]][4];
                        R3 = passArray[parsArray[counterlist]][5];
                        L4 = passArray[parsArray[counterlist]][6];
                        R4 = passArray[parsArray[counterlist]][7];
                    

                    if(caller == 1){
                        L1 = rand_double_int(0.02, 0.2);
                    }else if(caller == 2){
                        R1 = rand_double_int(0.25, 0.75);
                    }else if(caller == 3){
                        L2 = rand_double_int(0.02, 0.2);
                    }else if(caller == 4){
                        R2 = rand_double_int(0.25, 0.75);
                    }else if(caller == 5){
                        L3 = rand_double_int(0.02, 0.2);
                    }else if(caller == 6){
                        R3 = rand_double_int(0.25, 0.75);
                    }else if(caller == 7){
                        L4 = rand_double_int(0.02, 0.2);
                    }else if(caller == 8){
                        R4 = rand_double_int(0.25, 0.75);
                    }
                    ptOne = (M_PI*(R1*R1)*L1);
                    ptTwo = (M_PI*(R2*R2)*L2);
                    ptThree = (M_PI*(R3*R3)*L3);
                    ptFour = (M_PI*(R4*R4)*L4);
                    Math = ((2500*ptOne)+(19250*ptTwo)+(2500*ptThree)+(2500*ptFour));
                    if(debug == true){
                        cout << Math << endl;
                    }
                    counter ++;
                    if(counter == rantry){
                        goto noNumError;
                    }
                }
                while(Math >= 650);
                passArray[j][0] = L1;
                passArray[j][1] = R1;
                passArray[j][2] = L2;
                passArray[j][3] = R2;
                passArray[j][4] = L3;
                passArray[j][5] = R3;
                passArray[j][6] = L4;
                passArray[j][7] = R4;
            }
        }
        noNumError: 
            if(debug == true){
            if(counter == rantry){
                cout << "Data in location " << j << " could not change after " << rantry << " tries" << endl;
                counterset ++;
                    if(counterset == 4){
                        counterlist ++;
                        counterset = 0;
                    }
            }else{cout << "Data Saved" << endl;
                    counterset ++;
                    if(counterset == 4){
                        counterlist ++;
                        counterset = 0;
                    }}
        };
        cout << countertemp << endl;
    }
    for(int i=0; i<size; i++){
        passArray[i][0] = passArray[i][0] * 1000;
        passArray[i][1] = passArray[i][1] * 1000;
        passArray[i][2] = passArray[i][2] * 1000;
        passArray[i][3] = passArray[i][3] * 1000;
        passArray[i][4] = passArray[i][4] * 1000;
        passArray[i][5] = passArray[i][5] * 1000;
        passArray[i][6] = passArray[i][6] * 1000;
        passArray[i][7] = passArray[i][7] * 1000;
        if(debug == true){
            cout << passArray[i][0] << " " << passArray[i][1] << " " << passArray[i][2] << " " << passArray[i][3]
            << " " << passArray[i][4] << " " << passArray[i][5] << " " << passArray[i][6] << " " << passArray[i][7] << endl;
        }
    }
    if(debug == true){
        system("pause");
    }
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


void arrayFilter(int size, float passArray[1000][8], string dataword[1000][8], float smartline[1000][9], float score[1000][2], int perc, bool debug){
    float passPerc = (perc/100) * size;
    for(int j=0; j<251; j++){                                //Currently have to man put in percent number
        for(int i=0; i<size; i++){
            if(smartline[i][8] == score[j][1]){
                passArray[i][0] = smartline[i][0];
                passArray[i][1] = smartline[i][1];
                passArray[i][2] = smartline[i][2];
                passArray[i][3] = smartline[i][3];
                passArray[i][4] = smartline[i][4];
                passArray[i][5] = smartline[i][5];
                passArray[i][6] = smartline[i][6];
                passArray[i][7] = smartline[i][7];
            }
        }
    }
    if(debug == true){
        for(int i=0; i<size; i++){
            cout << passArray[i][0] << " " << passArray[i][1] << " " << passArray[i][2] << " " << passArray[i][3]
            << " " << passArray[i][4] << " " << passArray[i][5] << " " << passArray[i][6] << " " << passArray[i][7] << endl;
        }
        cout << "end line ________________" << endl;
        cout << passPerc << endl;
        system("pause");
    }

}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

int dataDraw(int size, string dataword[1000][8], float smartline[1000][9], bool debug){                   // Set 100 to Len of file AKA size
    string testline;
    int score[size];

    ifstream Test ( "Data.txt" );                                       //File Name

    if (!Test)
    {
        cout << "There was an error opening the Data file.\n";          //Error
        return 1;
    }


    //store words in array
    int x=0,y=0;
    while( Test>>testline )
    {
        dataword[y][x]=testline;
        x++;
        if (testline=="")
        y++;
    }


    //output whole array with array position numbers for each entry
    if(debug == true){
        cout<<"Array contents:\n";
        for (int y=0;y<size;y++)
        {
            for (int x=0;x<8;x++)
            cout<<dataword[y][x]<<"("<<y<<","<<x<<")"<<endl;
        }

        cout << "Data File Mix Print:" << endl;
    }


    for(int i=0; i<size; i++){                                  //Seting smartLine as new array with datset from file and counter
        smartline[i][0] = stof(dataword[i][0]);
        smartline[i][1] = stof(dataword[i][1]);
        smartline[i][2] = stof(dataword[i][2]);
        smartline[i][3] = stof(dataword[i][3]);
        smartline[i][4] = stof(dataword[i][4]);
        smartline[i][5] = stof(dataword[i][5]);
        smartline[i][6] = stof(dataword[i][6]);
        smartline[i][7] = stof(dataword[i][7]);
        smartline[i][8] = i;
    }
    if(debug == true){
        for(int i=0; i<size; i++){
            cout << smartline[i][0] << " " << smartline[i][1] << " " << smartline[i][2] << " " << smartline[i][3] <<
            " " << smartline[i][4] << " " << smartline[i][5] << " " << smartline[i][6] << " " << smartline[i][7] <<
            " " << smartline[i][8] <<  endl;
        }
        system("pause");
    }
    

    return 0;
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-


void scoreRun(float perc, int size, float word[1000][2], float score[1000][2], bool debug){                   //Change 100 to file size
    string testline;

    ifstream Test ( "Score.txt" );                               //Seting File Name

    if (!Test)
    {
        cout << "There was an error opening the Score file.\n";          //Error
    }


    //store words in array
    int x=0,y=0;
    for(int i=0; i < size * 2; i++)
    {
        Test>>testline;
//-----------------------------------------------------
        string fileCorrect;                                         //Removing last data so it can convert to int
        if(i%2 == 1){
            fileCorrect = testline.substr (0,testline.length()-1);
        }else{
            fileCorrect = testline;
        }
//-----------------------------------------------------
        float streamer = stof(fileCorrect);                       //Change String to int for math
//-----------------------------------------------------
        word[y][x]=streamer; // fileCorrect can be convt to testline
        x++;
        if (testline=="")
        y++;
    }


    for(int i=0; i< size; i++){
        word[i][1] = word[i][1] / 170;
    }

    //output whole array with array position numbers for each entry
    if(debug == true){
        cout << "Array contents:" << endl;
        for (int y=0;y<size;y++)
        {
            for (int x=0;x<2;x++)
            cout<<word[y][x]<<"("<<y<<","<<x<<")"<<endl;
        }
        cout << "Score Array Contents:" << endl;
    }

    //Set Score of each Set in Array
    
    for(int i=0; i<size; i++){
        score[i][0] = word[i][0]+word[i][1];
        score[i][1] = i;
        if(debug == true){
            cout << score[i][0] << endl;
        }
    }

    //Filter % Score to lowest to pass to Cell Mutation
    float passPerc = (perc/100) * size;
    if(debug == true){
        cout << "The top " << perc << "% is passing on:" << endl;
    }
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(score[j][0]>score[j+1][0]){
                float temp = score[j][0];
                float temptwo = score[j][1];
                score[j][1] = score[j+1][1];
                score[j+1][1] = temptwo;
                score[j][0] = score[j+1][0];
                score[j+1][0] = temp;
            }
        }
    }
    if(debug == true){
        for(int i=0; i<passPerc; i++){
            cout << score[i][0] << " , " << score[i][1] << endl;
        }
        
        system("pause");
    }

}


//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-



int main(){
    srand(time(NULL));
    float percent = 25;             //Dont change on this update there is man dataset in func arrayRand
    int size = 1000;
    int changeval = 3;
    int rantry = 500000;            //Higher num allows the arrayRand func to fill 0 loc more rec is 15000
    bool debug = false;             //Lower num speeds up GA

    float word[size][2];
    float scoreArray[size][2];
    string dataword[size][8];
    float smartline[size][9];
    float passArray[size][8];

    int callback = 0;

    scoreRun(percent, size, word, scoreArray, debug);

    callback = dataDraw(size, dataword, smartline, debug);
    if(callback == 1){
        cout << "File Error Use Debug to find Loc" << endl;
    }

    arrayFilter(size, passArray, dataword, smartline, scoreArray, percent, debug);

    arrayRand(size, passArray, changeval, rantry, debug);

    arrayFill(size, passArray, debug);

    fileBuild(size, passArray, debug);

    cout << "System Call to file has been processed" << endl;
    system("pause");

    return 0;
}


// Set if statement to test if the score file is -09 or -10 and change multiplication to value