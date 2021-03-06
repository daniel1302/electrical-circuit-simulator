#include <iostream>
#include <Model/Math/Matrix.h>
#include <Model/Math/GaussianElimination.h>


#ifndef TEST_GAUSSIAN_ELIMINATION
#define TEST_GAUSSIAN_ELIMINATION

void gaussianEliminationTest()
{

    auto matrix3 = new Matrix<double>();
    matrix3->insert(0, 0, 1);
    matrix3->insert(0, 1, -1);
    matrix3->insert(0, 2, 0);
    matrix3->insert(1, 0, -1);
    matrix3->insert(1, 1, 2.125);
    matrix3->insert(1, 2, 0.625);
    matrix3->insert(2, 0, 0);
    matrix3->insert(2, 1, 0.625);
    matrix3->insert(2, 2, 3.125);

    auto freeMatrix = new Matrix<double>();

    freeMatrix->insert(0, 0, 10);
    freeMatrix->insert(1, 0, 0);
    freeMatrix->insert(2, 0, 0);

    std::cout << "Before reduction"
              <<"Matrix [" <<matrix3->rows() << " x " << matrix3->cols() << "]" << std::endl
              <<matrix3->print()<<endl
              <<freeMatrix->print()<<endl;

    GaussianElimination<double> gaussianElimination(matrix3, freeMatrix);
    gaussianElimination.reduce();

    std::cout << "After reduction"
              <<"Matrix [" <<matrix3->rows() << " x " << matrix3->cols() << "]" << std::endl
              <<matrix3->print()<<endl
              <<freeMatrix->print()<<endl;

}

#endif //END TEST_GAUSSIAN_ELIMINATION