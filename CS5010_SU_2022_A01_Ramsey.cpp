#include <iostream>
#include <string>
using namespace std;

int main(){
    //declaration of variables here
    string Input1;
    string Input2;
    int hammingDistance = 0; // calculated Hamming Distance
    int input1Length = 0; // length of string 1
    int input2Length = 0; // length of string 2

    
    
    // introduction
    cout << "This program will calculate the Hamming distance of two strings \n" << endl;

    //user instructions
    cout << "Please enter two string values when prompted. \n";
    cout << "Blank string values will not be accepted. \n" << endl;



    //conversion for -99 Do I need to? no. but leaving this here to remind me I thought about this already

    //first condition: While input is not -99     
    while ((Input1 != "-99") || (Input2 != "-99")) {
        hammingDistance = 0; // reset to zero for each loop

        cout << "Enter the first string value" << endl;
        getline(cin, Input1);
        
        // check sentinal value
        if (Input1 == "-99") {
            cout << "break-1";
            break;
        }

        //testing loop to prevent blank strings (needed only if I switch to getline (I did))
        while (Input1.empty()) {
            cout << "No blank strings accepted. \n Enter the first string to compare (or -99 to end the program)" << endl;
            getline(cin, Input1);
        }
        
        cout << "Enter the second string value \n (make sure they are the same length)" << endl;
        getline(cin, Input2);
       
        // check sentinal value
        if (Input2 == "-99") {
            cout << "break-2";
            break;
        }
        
        //testing loop to prevent blank strings (needed only if I switch to getline (I did))
        while (Input2.empty()) {
            cout << "No blank strings accepted \n Enter the second string to compare (or -99 to end the program)" << endl;;
            getline(cin, Input2);
        }

        // string length check
        input1Length = (Input1.size());
        input2Length = (Input2.size());

        while (input1Length == input2Length) { 
        /*  
            cout << "length of 1: " << input1Length << endl; //error checking comment out
            cout << "length of 2: " << input2Length << endl; //error checking comment out
        */  
            // calculate Hamming Distance Here
            for (int i=0; i <= (input1Length -1); ++i) {
		        if ((Input1.at(i)) != (Input2.at(i))) {
			        hammingDistance += 1;
		        }
	        }
	cout << "Hamming Distance is : " << hammingDistance << endl;

            break;
        
        }
        if (input1Length != input2Length) {
            cout << "Caution: Input values do not match. Please make sure values match for comparison" << endl;
        }

    }

    return 0;
}