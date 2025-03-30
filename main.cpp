#include "csparsematrix.h"
#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0));

    char answer = 'y';
    while (answer == 'y' || answer == 'Y') {
        int rows, cols;
        cout << "Enter row, col size: ";
        cin >> rows >> cols;

        // 일반행렬 A,B 생성
        cout << "Matrix A" << endl;
        Matrix* mat1 = new Matrix(rows, cols);
        mat1->printMatrix();
        cout << "Matrix B" << endl;
        Matrix* mat2 = new Matrix(rows, cols);
        mat2->printMatrix();

         // Addition
         auto start = high_resolution_clock::now();
         Matrix* added = mat1->addMatrix(*mat1, *mat2);
         auto end = high_resolution_clock::now();
         cout << "\nResult of A + B:\n";
         added->printMatrix();
         auto durationAdd = duration_cast<milliseconds>(end - start).count();
         cout << "Addition Time: " << durationAdd << " ms\n";
         delete added;

         // Subtraction
        start = high_resolution_clock::now();
        Matrix* sub = mat1->subtractMatrix(*mat1, *mat2);
        end = high_resolution_clock::now();
        cout << "\nResult of A - B:\n";
        sub->printMatrix();
        auto durationSub = duration_cast<milliseconds>(end - start).count();
        cout << "Subtraction Time: " << durationSub << " ms\n";
        delete sub;

        // Multiplication ㅡ맏 
        start = high_resolution_clock::now();
        Matrix* mul = mat1->multMatrix(*mat1, *mat2);
        end = high_resolution_clock::now();
        cout << "\nResult of A * B:\n";
        mul->printMatrix();
        auto durationMul = duration_cast<milliseconds>(end - start).count();
        cout << "Multiplication Time: " << durationMul << " ms\n";
        delete mul;

        // Division (element-wise)
        start = high_resolution_clock::now();
        Matrix* div = mat1->divideElement(*mat1, *mat2);
        end = high_resolution_clock::now();
        cout << "\nResult of A / B:\n";
        div->printMatrix();
        auto durationDiv = duration_cast<milliseconds>(end - start).count();
        cout << "Element-wise Division Time: " << durationDiv << " ms\n";
        delete div;

        cout << "=========================================" << endl;
        
        // 희소행렬 A,B 생성
        cout << "\n Generate Sparse Matrix A" << endl;
        start = high_resolution_clock::now();
        CSparseMatrix sMat1 = CSparseMatrix::structArraySparseMatrixCOO(*mat1);
        end = high_resolution_clock::now();
        sMat1.printSparseMatrix();
        auto duration = duration_cast<milliseconds>(end - start).count();
        cout << "Convert to Sparse Matrix Time (A): " << duration << " ms\n";

        cout << "\n Generate Sparse Matrix B" << endl;
        start = high_resolution_clock::now();
        CSparseMatrix sMat2 = CSparseMatrix::structArraySparseMatrixCOO(*mat2);
        end = high_resolution_clock::now();
        sMat2.printSparseMatrix();
        duration = duration_cast<milliseconds>(end - start).count();
        cout << "Convert to Sparse Matrix Time (B): " << duration << " ms\n";

        // matrix A,B를 전치한 전치함수 생성
        cout << "\nTranspose Matrix A" << endl;
        start = high_resolution_clock::now();
        Matrix* transposedA = mat1->transposeMatrix(*mat1);
        end = high_resolution_clock::now();
        transposedA->printMatrix();
        duration = duration_cast<milliseconds>(end - start).count();
        cout << "Transpose Matrix Time (A): " << duration << " ms\n";
        delete transposedA;
 
        cout << "\nTranspose Matrix B" << endl;
        start = high_resolution_clock::now();
        Matrix* transposedB = mat2->transposeMatrix(*mat2);
        end = high_resolution_clock::now();
        transposedB->printMatrix();
        duration = duration_cast<milliseconds>(end - start).count();
        cout << "Transpose Matrix Time (B): " << duration << " ms\n";
        delete transposedB;
        /*
        delete sMat1;
        delete sMat2;*/
        delete mat1;
        delete mat2;
               
    }

    return 0;
}