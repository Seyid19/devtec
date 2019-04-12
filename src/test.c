#include"stringLib.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int init_suite(void) { return 0; }

int clean_suite(void) { return 0; }

void test_str_len(void){//our test function 1
	CU_ASSERT(3==str_len(123));
	CU_ASSERT(4==str_len(5678));
	CU_ASSERT(3==str_len("ana"));
	CU_ASSERT(4==str_len("ufaz"));
}

void test_str_cmp(void){//our test function 2
	char *x=(char*)malloc(1); char *p=(char*)malloc(1); x=p;
	CU_ASSERT_PTR_EQUAL(x,p);
	CU_ASSERT(1==str_cmp(123,14));
	CU_ASSERT(0==str_cmp(234,234));
	CU_ASSERT(1==str_cmp("ana","ata"));
CU_ASSERT(0==str_cmp("ana","ana"));
}

void test_isPolindrome(void){//our test function 1
	CU_ASSERT(0==isPolindrome(121));
	CU_ASSERT(1==isPolindrome(122));
	CU_ASSERT(1==isPolindrome("ufaz"));
	CU_ASSERT(1==isPolindrome("ata"));
}


void tests(void){//some other tests
	char *x=(char*)malloc(1); char *p=(char*)malloc(1); x=p;
	CU_ASSERT_PTR_EQUAL(x,p);
	CU_ASSERT_DOUBLE_NOT_EQUAL(sqrt(4),1,0.0);
	
}

int main (void){// Main function

	CU_pSuite pSuite1 = NULL,pSuite2 = NULL;

	// Initialize CUnit test registry 
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	// Add suite1 to registry 
	pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
	if (NULL == pSuite1) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	//Add suite2 to registery
	pSuite2 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
	if (NULL == pSuite2) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	// add test1 to suite1 
	if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing str_len function……..\n\n", test_str_len))){
		CU_cleanup_registry();
		return CU_get_error();
	}

	//add test 2 to suite2 
	if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing str_cmp function……..\n\n", test_str_cmp))){
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing isPalindrome function……..\n\n", test_isPolindrome))){
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite2, "\n\n……… Testing other function……..\n\n", tests))){
		CU_cleanup_registry();
		return CU_get_error();
	}
	CU_basic_run_tests();// OUTPUT to the screen

	CU_basic_show_failures(CU_get_failure_list());
	return CU_get_number_of_failures();
}
