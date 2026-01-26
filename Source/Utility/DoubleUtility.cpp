#include "DoubleUtility.h"
#include <cmath>

using namespace std;

constexpr double epsilon = std::numeric_limits<double>::epsilon();
bool DoubleEqual(const double& left, const double& right)
{
	return std::abs(left - right) <= epsilon;
}
bool DoubleNotEqual(const double& left, const double& right)
{
	return !DoubleEqual(left, right);
}
bool DoubleLess(const double& left, const double& right)
{
	return left < right - epsilon;
}
bool DoubleLessEqual(const double& left, const double& right)
{
	return left < right + epsilon;
}
bool DoubleGreat(const double& left, const double& right)
{
	return left > right + epsilon;
}
bool DoubleGreatEqual(const double& left, const double& right)
{
	return left > right - epsilon;
}