#include <NTL/BasicThreadPool.h>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

#include "Methods.h"
#include "Tools.h"

//#include "TestScheme.h"


using namespace std;
using namespace NTL;


int main(int argc, char **argv) {

	// Get the number of hardware threads available on the current system
	unsigned int numThreads = thread::hardware_concurrency();
	if (numThreads == 0) {
		cerr << "Unable to get the number of hardware threads." << endl;
		return EXIT_FAILURE;
	}

	// Print the number of hardware threads
	cout << "Number of hardware threads available: " << numThreads << endl;

	// Set the number of threads in NTL to the number of hardware threads
	SetNumThreads(numThreads + 2);

	


        //TestScheme::testAllFunctions();



	string mnisttestfile  = "../data/MNIST_test_dataset.csv";
	string cifartestfile  = "../data/CIFAR10_test_dataset.csv";
	vector<vector<vector<double>>> dataset = Tools::dataFromFile(mnisttestfile);


	for (int n = 0; n < 5; n++) {
		cout<< endl << testdatalabel[n] << endl;

		for (int i=0; i < 28; ++i) {
			for ( int j=0; j < 28; ++j)
				if(testdataset[n][i*28+j] < 1e-2) cout << "     ";
            	else printf("%5d", int(testdataset[n][i*28+j]) ) ;
    		cout << endl;
		}
	}




	string CNNweightsMNIST  = "../data/CNNweightsMNIST.csv";
	string CNNweightsCIFAR10  = "../data/CNNweightsCIFAR10.csv";
	vector<vector<double>> weights = Tools::dataFromCNNweightsFile(CNNweightsMNIST);
	


	cout << endl << "END OF THE PROGRAMM" << endl;
	return 0;
}
