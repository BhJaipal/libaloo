#include "aloo.h"
// #include "gtest/gtest.h"
#include <stdio.h>

int main() {
	Test *t = createTest("Testing Aloo");
	t->addTest("Test trying", t, t->expectInt(2 * 2, 4));
	t->result(t);
	return 0;
}