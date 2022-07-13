for (int i=0; i <= (input1Length -1); ++i) {
		        if ((userInput1.at(i)) != (userInput2.at(i))) {
			        hammingDistance += 1;
		        }
	        }
	cout << "Hamming Distance is : " << hammingDistance << endl;

            break;
        
        }
        if (input1Length != input2Length) {
            cout << "WARNING: Inputs must be the same length to compare" << endl;
        }

    }

    return 0;
}