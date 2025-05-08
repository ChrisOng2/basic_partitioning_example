//
// Created by Christopher on 5/2/2025.
//

#ifndef MATRIXGEN_H
#define MATRIXGEN_H

#include "MatrixStruct.h"

MatrixReadInFormat OnlyDiagionals(int Row, int Col, double Diagional);

MatrixReadInFormat OnlyTop(int Row, int Col, int Top);

MatrixReadInFormat OnlyBottom(int Row, int Col, int Bottom);

MatrixReadInFormat RandomEntries(int Row, int Col);

#endif //MATRIXGEN_H
