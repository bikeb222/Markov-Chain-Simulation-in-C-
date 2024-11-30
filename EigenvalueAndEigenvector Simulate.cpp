#include <iostream>
#include <Eigen/Dense>
#include <iomanip>

using namespace Eigen;
using namespace std;

int main() {
    Matrix3d matrix;
    matrix << 0.2, 0.6, 0.2,
               0.3, 0, 0.7,
               0.5, 0, 0.5;

    cout << "Matrix:\n" << matrix << "\n" << endl;
    EigenSolver<Matrix3d> solver(matrix);
    Vector3d eigenvalues = solver.eigenvalues().real();
    cout << setprecision(2) << "Eigenvalues:\n" << eigenvalues << "\n" << endl;


    Matrix3d transposeMatrix = matrix.transpose();
    EigenSolver<Matrix3d> leftSolver(transposeMatrix);
    Matrix3d leftEigenvectors = leftSolver.eigenvectors().real();
    for (int i = 0; i < 3; ++i) {
        leftEigenvectors.col(i).normalize();
    }
    cout << setprecision(2) << "Left Eigenvectors:\n" << leftEigenvectors << "\n" << endl; 
    return 0;
}
