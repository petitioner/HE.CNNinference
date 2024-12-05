#include "Tools.h"

#include <assert.h>

#include <numeric> // for std::accumulate

double computeAverage(const vector<vector<double>>& matrix);

int CNNinference(int rownum, int vctslots, int image_height, int image_width, vector<vector<vector<double>>> dataset, vector<vector<double>> weights);

int HE_SquareMatrixMult(long dim=64);

