#include "Fixed.h"
#include "Point.h"

int main() {
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);
	Point d(1, 1);
	Point f(-1, -1);

	// Test 1
	Point p10(1, 2);
	std::cout << "Test 1: " << (bsp(a, b, c, p10) ? "inside" : "outside") << std::endl;

	// Test 2
	Point p2(1, 0.5);
	std::cout << "Test 2: " << (bsp(a, b, c, p2) ? "inside" : "outside") << std::endl;

	// Test 3
	Point p3(1, 0);
	std::cout << "Test 3: " << (bsp(a, b, c, p3) ? "inside" : "outside") << std::endl;

	// Test 4
	Point p4(2, 2);
	std::cout << "Test 4: " << (bsp(a, b, c, p4) ? "inside" : "outside") << std::endl;

	// Test 5
	Point p5(0.33, 0.33);
	std::cout << "Test 5: " << (bsp(a, b, c, p5) ? "inside" : "outside") << std::endl;

	// Test 6
	Point p6(0, 0.5);
	std::cout << "Test 6: " << (bsp(a, b, c, p6) ? "inside" : "outside") << std::endl;

	// Test 7
	Point p7(0, 1);
	std::cout << "Test 7: " << (bsp(a, b, c, p7) ? "inside" : "outside") << std::endl;

	// Test 8
	Point p8(-1, -1);
	std::cout << "Test 8: " << (bsp(a, b, c, p8) ? "inside" : "outside") << std::endl;

	// Test 9
	Point p9(0.1, 0.1);
	std::cout << "Test 9: " << (bsp(a, b, c, p9) ? "inside" : "outside") << std::endl;

	// Test 10
	Point p11(0.4, 0.4);
	std::cout << "Test 10: " << (bsp(a, b, c, p11) ? "inside" : "outside") << std::endl;

	return 0;
}

