//
// Created by Christopher on 5/4/2025.
//

#ifndef METISADJNCYFIND_H
#define METISADJNCYFIND_H

#include "MatrixStruct.h"
#include <vector>

void METISAdjncyFind(MatrixReadInFormat A, std::vector<int> &xadj, std::vector<int> &adjncy);

#endif //METISADJNCYFIND_H
