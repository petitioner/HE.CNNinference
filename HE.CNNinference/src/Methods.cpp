#include "Tools.h"
#include "Methods.h"


#include "NTL/ZZX.h"

#include <cmath>




#include <NTL/BasicThreadPool.h>
#include <NTL/RR.h>
#include <NTL/ZZ.h>

#include <iomanip>
#include <set>
#include <map>
#include <typeinfo>
#include <vector>
#include <algorithm>    // std::shuffle
#include <vector>        // std::vector
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include <unistd.h>

#include "HEAAN.h"




double computeAverage(const vector<vector<double>>& matrix) {
    double sum = 0;
    size_t count = 0;

    for (const auto& row : matrix) {
        sum += accumulate(row.begin(), row.end(), 0.0); 
        count += row.size();
    }

    if (count == 0) {
        return 0.0; 
    }

    return sum / count;
}


int CNNinference(int rownum, int vctslots, int image_height, int image_width, vector<vector<vector<double>>> dataset, vector<vector<double>> weights)
{
  cout << endl << endl << endl << endl;
  cout << "Running CNNinference(int rownum, int vctslots, int image_height, int image_width, vector<vector<vector<double>>> dataset, vector<vector<double>> weights)" << endl << endl;
  cout << "rownum: " << rownum << endl;
  cout << "vctslots: " << vctslots << endl;
  cout << "image_height: " << image_height << endl;
  cout << "image_width: " << image_width << endl;

    double avg = computeAverage(weights);
    cout << "Average of weights: " << avg << endl;

  //-----------------------------------------
  long logN = 11;
  long logQ = 1200;
  long logp = 30;
  long logSlots = 3;
  long slots = 1 << logSlots;
 

  

      

	Scheme scheme(logN, logQ);
  SecretKey secretKey(logN);
	auto pubKey = scheme.generatePubKey(secretKey);	scheme.setEncryptionKey(pubKey);
	auto conjKey = scheme.generateConjKey(secretKey);	scheme.setConjugationKey(conjKey);
	auto multKey = scheme.generateMultKey(secretKey);	scheme.setMultiplicationKey(multKey);
	auto leftRotKey = scheme.generateLeftRotKey(secretKey, 1);	scheme.setLeftRotKey(1, leftRotKey);
	auto rightRotKey = scheme.generateRightRotKey(secretKey, 1);	scheme.setRightRotKey(1, rightRotKey);

  scheme.addLeftRotKey(secretKey, 2);
  scheme.addRightRotKey(secretKey, 2);
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////

  double mval = EvaluatorUtils::randomReal();
  Ciphertext cipher = scheme.encrypt(mval, logp, logQ);
  
  double dval = scheme.decryptSingle(secretKey, cipher);
  StringUtils::showcompare(mval, dval, "Enc and Dec");
  cout << endl << endl << endl;
  
  auto negct = cipher.negate();

  
  
  cipher.negateAndEqual();

  
  cipher = scheme.encrypt(mval, logp, logQ);
  auto ctrs = cipher.reScaleBy(1);
  cipher.reScaleByAndEqual(1);

  
  cipher = scheme.encrypt(mval, logp, logQ);
  ctrs = cipher.reScaleTo(30);

  
  
  cipher = scheme.encrypt(mval, logp, logQ);
  cipher.reScaleToAndEqual(30);

  
  
  cipher = scheme.encrypt(mval, logp, logQ);
  ctrs = cipher.modDownBy(10);

  
  
  cout << "cipher.logq = " << cipher.logq << endl;
  cipher.modDownByAndEqual(80);

  
  
  cout << "cipher.logq = " << cipher.logq << endl;
  ctrs = cipher.modDownTo(300);

  
  
  cout << "cipher.logq = " << cipher.logq << endl;
  cipher.modDownToAndEqual(300);

  
  
  double mval1 = EvaluatorUtils::randomReal();
  Ciphertext cipher1 = scheme.encrypt(mval1, logp, logQ);
  double mval2 = EvaluatorUtils::randomReal();
  Ciphertext cipher2 = scheme.encrypt(mval2, logp, logQ);
  
  auto cipher3 = scheme.add(cipher1, cipher2);

  
  Ciphertext cipher4; cipher4.copy(cipher1);
  scheme.addAndEqual(cipher4, cipher2);

  
  double cnst = EvaluatorUtils::randomReal();
  auto cipher5 = scheme.addConst(cipher1, cnst);

  
  Ciphertext cipher6; cipher6.copy(cipher1);
  scheme.addConstAndEqual(cipher6, cnst);

  
  
  
  mval1 = EvaluatorUtils::randomReal();
  cipher1 = scheme.encrypt(mval1, logp, logQ);
  mval2 = EvaluatorUtils::randomReal();
  cipher2 = scheme.encrypt(mval2, logp, logQ);
  
  auto cipher7 = scheme.sub(cipher1, cipher2);

  
  Ciphertext cipher8(cipher1), cipher9(cipher2);
  scheme.subAndEqual(cipher8, cipher9);

  
  Ciphertext cipher10(cipher1), cipher11(cipher2);
  scheme.subAndEqual2(cipher10, cipher11);

  
  cnst = EvaluatorUtils::randomReal();
  
  auto cipher12 = scheme.subConst(cipher1, cnst);

  
  Ciphertext cipher13(cipher1);
  scheme.subConstAndEqual(cipher13, cnst);

  
  
  mval1 = EvaluatorUtils::randomReal();
  cipher1 = scheme.encrypt(mval1, logp, logQ);
  mval2 = EvaluatorUtils::randomReal();
  cipher2 = scheme.encrypt(mval2, logp, logQ);
  
  auto cipher14 = scheme.mult(cipher1, cipher2);
  dval = scheme.decryptSingle(secretKey, cipher14);

  
  Ciphertext cipher15(cipher1);
  scheme.multAndEqual(cipher15, cipher2);

  
        Ciphertext cipher16(cipher1);
  scheme.imultAndEqual(cipher16);
  scheme.imultAndEqual(cipher16);

  
  
  cnst = EvaluatorUtils::randomReal();
  auto cipher17 = scheme.multByConst(cipher1, cnst, 30);

  
  Ciphertext cipher18(cipher1);
  scheme.multByConstAndEqual(cipher18, cnst, 30);




  
 cout << endl << "--------------- END ---------------" << endl;

  return 0;
}


int HE_SquareMatrixMult(long dim)  // dim = 4, 16, 64 
{
  
 cout << endl << "--------------- END ---------------" << endl;

  return 0;
}
