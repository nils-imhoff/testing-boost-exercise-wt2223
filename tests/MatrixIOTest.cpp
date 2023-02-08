#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(LoadMatrix)
{
  MatrixXd expected(3, 3);
  expected << 4, 5, -8,
      1, 9.5, -3,
      0.0, -0, -0.56;

  MatrixXd matrix = matrixIO::openData("testmatrix.csv", 3);
  BOOST_TEST(expected(0, 0) == matrix(0, 0));
  BOOST_TEST(expected(0, 1) == matrix(0, 1));
  BOOST_TEST(expected(0, 2) == matrix(0, 2));
  BOOST_TEST(expected(1, 0) == matrix(1, 0));
  BOOST_TEST(expected(1, 1) == matrix(1, 1));
  BOOST_TEST(expected(1, 2) == matrix(1, 2));
  BOOST_TEST(expected(2, 0) == matrix(2, 0));
  BOOST_TEST(expected(2, 1) == matrix(2, 1));
  BOOST_TEST(expected(2, 2) == matrix(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()