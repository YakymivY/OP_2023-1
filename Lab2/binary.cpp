#include "binary.h"

using namespace std;

// function that takes name of the file from user
string inputFilename () {
    string str;
    cout<<"Choose the name of file to create/open (without extension): "<<endl;
    fflush(stdin);
    cin>>str;
    return str;
}

//function that takes int value from the user
int inputInt (int min, int max) {
    int ans;
    int error;
    do {
        cin>>ans;
        if (cin.fail()){
            cin.clear();
            fflush(stdin);
            cout<<"You have entered wrong input. Try again:"<<endl;
            error = 1;
        } else {
            if (ans < min) {
                cout<<"The value must be greater than "<<min<<endl;
                error = 1;
            } else if (ans > max) {
                cout<<"The value must be smaller than "<<max<<endl;
                error = 1;
            } else {
                error = 0;
            }    
        }
    } while(error);
    return ans;
}

//function that takes name of the city from user
char* inputCity () {
    static char myString[MAX_CITY];
    fflush(stdin);
    cin.getline(myString, MAX_CITY);
    return myString;
}

//function that takes time from value user
int* inputTime () {
    static int time[2];
    int error = 0;
    do {
        fflush(stdin);
        cin>>time[0]; cin>>time[1];
        if (time[0] < 0 || time[0] > 23) {
            cout<<"Incorrect hours input (must be 0 to 23)"<<endl;
            error = 1;
        } else if (time[1] < 0 || time[1] > 59) {
            cout<<"Incorrect minutes input (must be 0 to 59)"<<endl;
            error = 1;
        } else {
            error = 0;
        }
    } while (error);
    
    return time;
}

// function that takes y/n answer from user
int inputAns (string question) {
    int output;
    int error = 0;
    char ans;
    do {
        cout<<question<<endl;
        fflush(stdin);
        cin>>ans;
        if (ans == 'Y' || ans == 'y') {
            output = 1;
            error = 0;
        } else if (ans == 'N' || ans == 'n') {
            output = 0;
            error = 0;
        } else {
            cout<<"Incorrect input. Value must be y or n."<<endl;
            error = 1;
        }
    } while (error);
    return output;
}

//function that adds 0 before minutes less than 9 to correctly print them out
string printMinutes (int value) {
    string str;
    if (value <= 9) {
        str = '0' + to_string(value); //adding 0 before actual value
    } else {
        str = to_string(value);
    }
    return str;
}

//function that adds a route to opened/created file
void addRoute (string filename) {
    int answer;
    int error;
    ofstream file(filename + ".bin", ios::binary | ios::app);
    if (!file) {
        cout<<"ERROR. Couldn't open/create the file."<<endl;
        return;
    }

    do {
        Route myRoute;
        cout<<"Enter id of the route:"<<endl;
        myRoute.id = inputInt(1, INT_MAX);

        cout<<"Enter the departure city (up to 20 letters):"<<endl;
        strcpy(myRoute.departure, inputCity());

        cout<<"Enter the destination city (up to 20 letters):"<<endl;
        strcpy(myRoute.destination, inputCity());

        cout<<"Enter departure time(hh mm):"<<endl;
        int *myDepTime = inputTime();
        for (int i = 0; i < 2; i++) myRoute.depTime[i] = myDepTime[i];

        int *myDestTime;
        do {
            cout<<"Enter arriving time (hh mm):"<<endl;
            myDestTime = inputTime();
            if ((myDestTime[0] < myRoute.depTime[0]) || ((myDestTime[0] == myRoute.depTime[0]) && (myDestTime[1] <= myRoute.depTime[1]))) {
                cout<<"Arrival time must be greater than departure time"<<endl;
                error = 1;
            } else {
                error = 0;
            }
        } while (error);
        for (int j = 0; j < 2; j++) myRoute.destTime[j] = myDestTime[j];

        cout<<"There is your added route:"<<endl;
        //output format
        cout<<myRoute.id<<" "<<myRoute.departure<<" - "<<myRoute.destination<<' '<<myRoute.depTime[0]<<':'<<printMinutes(myRoute.depTime[1])<<" - "<<myRoute.destTime[0]<<':'<<printMinutes(myRoute.destTime[1])<<endl;

        //output to file
        file.write((char*)&myRoute, sizeof(Route));
    } while (inputAns("Do you want to input one more route?(y/n)"));
    file.close();
}

//function that prints timetable
void printFile (string name) {
    Route pRoute;
    ifstream file(name, ios::binary);
    if (!file) {
        cout<<"You've created a new file"<<endl;
        return;
    }

    const int id_width = 5;
    const int city_width = MAX_CITY;
    const int time_width = 2;
    const int num_flds = 5;
    const string sep = " |" ; // separator
    const int total_width = id_width + city_width*2 + time_width*4 + sep.size() * num_flds + 2; //width of all string
    const string line = sep + string(total_width-1, '-') + '|';

    //adding headings
    cout << line << '\n' << sep
              << setw(id_width) << "ID" << sep << setw(city_width) << "DEPARTURE" << sep
              << setw(city_width) << "DESTINATION" << sep << setw(time_width*2 + 1) << "OUT" << sep
              << setw(time_width*2 + 1) << "IN" << sep << '\n' << line << '\n';

    while(file.read((char*)&pRoute, sizeof(Route))) {
        cout << sep << setw(id_width) << pRoute.id << sep << setw(city_width) << pRoute.departure << sep
             << setw(city_width) << pRoute.destination << sep << setw(time_width) << pRoute.depTime[0] << ':' << printMinutes(pRoute.depTime[1]) << sep
             << setw(time_width) << pRoute.destTime[0] << ':' << printMinutes(pRoute.destTime[1]) << sep << '\n';
    }
    cout << line << '\n';
    file.close();
}


//function that creates new winter schedule
void newSchedule (string filename) {
    ifstream inFile(filename + ".bin", ios::binary);
    if (!inFile) {
        cout<<"ERROR. Couldn't open/create the file."<<endl;
        return;
    }
    ofstream outFile(filename + "_winter.bin", ios::binary);
    if (!outFile) {
        cout<<"ERROR. Couldn't open/create the file."<<endl;
        return;
    }

    Route outRoute;
    while(inFile.read((char*)&outRoute, sizeof(Route))) {
        if (((outRoute.depTime[0] < 10) || (outRoute.depTime[0] == 10 && outRoute.depTime[1] == 0)) || outRoute.depTime[0] >= 18) {
            outFile.write((char*)&outRoute, sizeof(Route));
        }
    }

    outFile.close();
    inFile.close();
}