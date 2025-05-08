//
// Created by Christopher on 5/2/2025.
//
#ifndef MATRIXSTRUCT_H
#define MATRIXSTRUCT_H

#include <vector>

struct MatrixReadInFormat {
    /* This struct is used for read in format where this is treated
     * as a "tuple" for entries, row and columns. This format can
     * be used for other format testing
     */
    int rowCount;
    int colCount;
    std::vector<double> MatrixEntries;
    std::vector<int>    RowEntry;
    std::vector<int>    ColEntry;
};

struct CompressedSparseRow {
    /* Fill format for Compress Sparse Row
     * Entry - Nonzero Values
     *       - Should be ordered such that all values in a row are next to each other
     * ColIndex - Corresponding Column Index for the Nonzero entries
     * RowIndex - Contains m+1 values for numbers of m rows
     *          - Values are paired such that it is a pointer to starting row value to end of the row entries
     *            for Entry and ColIndex vectors
     * NOTE: A bit redundant, obviously
     */
    int rowCount;
    int colCount;

    std::vector<double> Entry;
    std::vector<int>    ColIndex;
    std::vector<int>    RowIndex;
};

#endif //MATRIXSTRUCT_H
