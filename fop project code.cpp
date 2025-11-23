/* Fundamentals of Programming Project 
Group Members : 
Ashwinaa A/P Sivakumar ( F24SP5877 )
Cheng Zhi Min ( F24SP5448 )
Lee Yin Xu ( F24SP5192 )
Lily Amira Batrisya ( F24SP5057 ) */ 

//header
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//course fee array to use in function
double fee[] = {1470, 525, 1570, 850, 1890};

//function to calculate total fee
double calcFee(int courseCode, int participants){
    return fee[courseCode - 1] * participants;
    //courseCode - 1 to match fee index
    //e.g. fee of courseCode = 1 is fee[0]
}

//function to calculate fee after discount
double getDisc(double totalFee, int participants){
    if(participants > 50)      //if number of participants more than 50
        return totalFee * 0.9; //10% discount
    else
        return totalFee;
}

int main(){
    string name;
    string course[] = {"AutoCAD Basic","Microsoft Excel Basic","Android Studio","E-Invoice Strategic","Analyzing Data"};

    //get customer name
    cout << "Enter customer name: ";
    getline(cin, name);

    //display available courses
    cout << "\nAvailable Courses: \n";

    for(int i = 0; i < 5; i++){
        cout << fixed << setprecision(2);
        cout << i + 1 << ". " << setw(21) << left << course[i] << " - RM " << setw(7) << right << fee[i] << '\n';
    }

    /*variable declaration
    courseCount  - number of courses registered
    courseCode   - course code entered by user (1-5)
    participants - number of participants per course
    */

    int courseCount, courseCode, participants;

    do{
        //get number of courses registered
        cout << "\nHow many courses do you want to register? ";

        //reject non-number input
        while(!(cin >> courseCount)){
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nHow many courses do you want to register? ";
        }

        //display invalid message if less than 1 or more than 5 courses registered
        if(courseCount < 1)
            cout << "Please register at least one course.\n";
        if(courseCount > 5)
            cout << "There are only 5 available courses that you can register.\n";

    }while(courseCount < 1||courseCount > 5);

    //store information in arrays
    string courseSelected[courseCount];
    int courseParticipants[courseCount];
    double totalFee[courseCount];
    double discount[courseCount];
    double afterDiscount[courseCount];

    int usedCodes[courseCount]; //store selected codes

    //number of iterations based on number of courses registered
    for(int i = 0; i < courseCount; i++){
        usedCodes[i] = 0;
        bool duplicate;

        do{
            duplicate = false;

            //get course code
            cout << "\nEnter course code #" << i + 1 << ": ";

            //reject non-number input
            while(!(cin >> courseCode)){
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nEnter course code #" << i + 1 << ": ";
            }

            //display invalid message if course code outside of 1-5
            if(courseCode < 1||courseCode > 5){
                cout << "Please enter a valid course code.\n";
                continue;
            }

            //check for duplicates
            for(int j = 0; j < i; j++){
                if(courseCode == usedCodes[j]){
                    cout << "You have already selected this course. Please choose another.\n";
                    duplicate = true;
                    break;
                }
            }

        }while(courseCode < 1||courseCode > 5||duplicate);

        usedCodes[i] = courseCode;

        do{
            //get number of participants per course
            cout << "Enter the number of participants (min 30): ";

            //reject non-number input
            while(!(cin >> participants)){
                cout << "Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\nEnter the number of participants (min 30): ";
            }

            //display invalid message if less than 30 participants per course
            if(participants < 30)
                cout << "Please enter at least 30 participants.\n\n";

        }while(participants < 30);

        //add elements to arrays
        courseSelected[i] = course[courseCode - 1];
        courseParticipants[i] = participants;
        totalFee[i] = calcFee(courseCode, participants); //function calcFee()
        afterDiscount[i] = getDisc(totalFee[i], participants); //function getDisc()
        discount[i] = totalFee[i] - afterDiscount[i];
    }

    //calculate subtotal by adding up all elements in afterDiscount array
    double subtotal = 0;
    for (int i = 0; i < courseCount; i++){
        subtotal += afterDiscount[i];
    }

    //calculate tax (6%)
    const double TAX_RATE = 0.06;
    double tax = subtotal * TAX_RATE;

    //calculate grand total including tax
    double grandtotal = subtotal + tax;

    //calculate total participants by adding up all elements in courseParticipants array
    int totalParticipants = 0;
    for (int i = 0; i < courseCount; i++){
        totalParticipants += courseParticipants[i];
    }

    //calculate amount per person
    double perPerson = grandtotal / totalParticipants;

    //generate receipt
    cout << "\n========= IT UTM CONSULTANCY - RECEIPT =========\n";
    cout << "Customer Name: " << name;

    //loop through each element in all arrays and display it
    for(int i = 0; i < courseCount; i++){
        cout << "\n\nCourse             : " << courseSelected[i];
        cout << "\nParticipants       : " << courseParticipants[i];
        cout << "\nTotal Fee          : RM " << totalFee[i];
        cout << "\nDiscount           : RM " << discount[i];
        cout << "\nFee After Discount : RM " << afterDiscount[i];
    }

    //display final totals
    cout << "\n\nSubtotal           : RM " << subtotal;
    cout << "\nTax (6%)           : RM " << tax;
    cout << "\nGrand Total        : RM " << grandtotal;
    cout << "\nTotal Participants : " << totalParticipants;
    cout << "\nAmount per Person  : RM " << perPerson << '\n';

    for(int i = 0; i < 48; i++){
        cout << "=";
    }

    cout << "\nThank you for registering!";
    return 0;
}
