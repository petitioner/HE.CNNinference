#include <NTL/BasicThreadPool.h>
#include <thread>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iomanip> //setw()

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


	auto labels = dataset[0];
        auto reddata = dataset[1];
        auto grndata = dataset[2];
        auto blkdata = dataset[3];

	cout << endl << endl;
	cout << "total number of images: " << reddata.size() << endl;
	cout << "total number of images: " << grndata.size() << endl;
	cout << "total number of images: " << blkdata.size() << endl;
	cout << "total number of images: " << labels.size() << endl;

	cout << endl << endl;

	cout << "total element number of an image: " << reddata[0].size() << endl;
	cout << "total element number of an image: " << grndata[0].size() << endl;
	cout << "total element number of an image: " << blkdata[0].size() << endl;

	
	for (int imgidx = 0; imgidx < 15; imgidx++) {
		cout<< "label: " << int(labels[imgidx][0]) << endl;

		for(int i=0; i<32; ++i) { 
			for(int j=0; j<32; ++j)
				cout <<  setw(3) << reddata[imgidx][32*i+j]<< "  "; 
			cout << endl;
		}
		for(int i=0; i<32; ++i) { 
			for(int j=0; j<32; ++j)
				cout <<  setw(3) << grndata[imgidx][32*i+j]<< "  "; 
			cout << endl;
		}
		for(int i=0; i<32; ++i) { 
			for(int j=0; j<32; ++j)
				cout <<  setw(3) << blkdata[imgidx][32*i+j]<< "  "; 
			cout << endl;
		}

		for (int pixidx=0; pixidx < reddata[imgidx].size(); ++pixidx) {
		    if ( pixidx % 32 == 0) cout << endl;

            	    double gray_value = (reddata[imgidx][pixidx] + grndata[imgidx][pixidx] + blkdata[imgidx][pixidx]) / 3.0;
            	    int gray_code = 232 + std::round(gray_value / 255.0 * 23);
                    std::cout << "\033[38;5;" << gray_code << "m" << " . " << "\033[0m";
		}

		cout << endl << endl << endl << endl;
	}
	cout << endl << endl << endl << endl;




	string CNNweightsMNIST  = "../data/CNNweightsMNIST.csv";
	string CNNweightsCIFAR10  = "../data/CNNweightsCIFAR10.csv";
	vector<vector<double>> weights = Tools::dataFromCNNweightsFile(CNNweightsMNIST);

	cout << "CNN Weights: " << weights.size() << " lines" <<  endl;
	for (auto wetrow : weights) {
	    cout << wetrow.size() << " parameters:  " << endl;
            for (auto it = wetrow.begin(); it != wetrow.end(); ++it) {
        	cout << *it << "\t";
    	    }
	    cout << endl << endl << endl << endl << endl << endl << endl;
	    for(int i=0; i<30;++i) cout << "- "; cout << endl << endl;
        }
	
	//rownum, vctslots, image_height, image_width
	CNNinference(32, 1024, 32, 32, dataset, weights);

	
	cout << endl << "END OF THE PROGRAMM" << endl;
	return 0;
}
