#pragma once
#include <iostream>
#include <string>
#include "QSInterface.h"
#include "QSTestInterface.h"
using namespace std;

/*
 * WARNING: It is expressly forbidden to modify any part of this document, including its name
 */

class QSTest:public QSTestInterface
{
	public:
		/*
		 * For all methods below, the correctness of an operation is defined in QSInterface.h.
		 */

		/*
		 * testSortAll
		 *
		 * Returns true if the given QSInterface object correctly sorts given arrays.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly sorts; false otherwise
		 */
		bool testSortAll(QSInterface* test);

		/*
		 * testSort
		 *
		 * Returns true if the given QSInterface object correctly sorts given subarrays.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly sorts; false otherwise
		 */
		bool testSort(QSInterface* test);

		/*
		 * testMedianOfThree
		 *
		 * Returns true if the given QSInterface object correctly performs median-of-three pivot selection.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly selects a pivot; false otherwise
		 */
		bool testMedianOfThree(QSInterface* test);

		/*
		 * testPartition
		 *
		 * Returns true if the given QSInterface object correctly partitions.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly partitions; false otherwise
		 */
		bool testPartition(QSInterface* test);

		/*
		 * testSwap
		 *
		 * Returns true if the given QSInterface object correctly swaps elements.
		 *
		 * @param test
		 * 		an implementation of the QSInterface class
		 * @return
		 * 		true if [test] correctly swaps elements = 0; false otherwise
		 */
		bool testSwap(QSInterface* test);
};
