#ifndef TEST_ALOO_H
#define TEST_ALOO_H
#include "../common/widget.h"

/******************** Private Funcs ********************/

struct _Test;

int __expectInt(int expected, int actual);
int __expectWidget(AlooWidget *expected, AlooWidget *actual);
int __expectGtkWidget(GtkWidget *expected, AlooWidget *actual);
void __addTest(const char *test_name, struct _Test *test, int test_res);
void __testRes(struct _Test *t);

/******************** Private Types ********************/

typedef struct _Test {
	int (*expectInt)(int expected, int actual);
	int (*expectWidget)(AlooWidget *expected, AlooWidget *actual);
	int (*expectGtkWidget)(GtkWidget *expected, AlooWidget *actual);
	void (*addTest)(const char *test_name, struct _Test *test, int test_res);
	void (*result)(struct _Test *t);
	int testCount;
	int testPassed;
	int testFailed;
	const char *label;
} Test;

Test *createTest(const char *name);

#endif // TEST_ALOO_H