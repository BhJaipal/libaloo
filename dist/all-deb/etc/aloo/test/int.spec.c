#include "aloo.h"
#include <stdio.h>

int main(int argc, char **argv) {
	Test *t = createTest("Testing Aloo");
	t->addTest("Test trying", t, t->expectInt(2 * 2, 4));
	t->result(t);
	return 0;
}