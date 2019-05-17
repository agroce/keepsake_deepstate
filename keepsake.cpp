#include <deepstate/DeepState.hpp>

using namespace deepstate;

#include <assert.h>

unsigned int code[5];

void initialize() {
  for (int i = 0; i < 5; i++) {
    code[i] = 1;
  }
}

void fix_numbers(){ 
  for (uint j = 0; j < 5; j++) {
    if (code[j] > 5) {
      code[j] = code[j] % 5;
    }
  }  
}

void increment_number_1() { 
  code[0] = code[0] + 1;
  code[3] = code[3] + 2;
  
  fix_numbers();
}

void increment_number_2(){ 
  code[1] = code[1] + 1;
  code[2] = code[2] + 2;
  
  fix_numbers();
}

void increment_number_3(){ 
  code[2] = code[2] + 1;
  code[4] = code[4] + 2;
  
  fix_numbers();
}

void increment_number_4(){ 
  code[3] = code[3] + 1;
  code[1] = code[1] + 2;
  
  fix_numbers();
}

void increment_number_5(){ 
  code[4] = code[4] + 1;
  code[0] = code[0] + 2;
  
  fix_numbers();
}

TEST(Keepsake, CheckCombination) {
  initialize(); 
  increment_number_4();
  increment_number_4();
  increment_number_4();
  increment_number_2();
  increment_number_2();
  increment_number_3();
  increment_number_3();
  increment_number_3();
  increment_number_5();
  increment_number_5();
  increment_number_5();
  assert (!(code[0] == 2 && code[1] == 4 && code[2] == 3 && code[3] == 4 && code[4] == 5));
}

#define N 100

TEST(Keepsake, FindCombination) {
  initialize();
  for (int i = 0; i < N; i++) {
    OneOf (
	   [&] {
	     LOG(TRACE) << i << ": increment_number_1();";
	     increment_number_1();
	   },
	   [&] {
	     LOG(TRACE) << i << ": increment_number_2();";
	     increment_number_2();
	   },
	   [&] {
	     LOG(TRACE) << i << ": increment_number_3();";
	     increment_number_3();
	   },
	   [&] {
	     LOG(TRACE) << i << ": increment_number_4();";
	     increment_number_4();
	   },
	   [&] {
	     LOG(TRACE) << i << ": increment_number_5();";
	     increment_number_5();
	   });
    assert (!(code[0] == 2 && code[1] == 4 && code[2] == 3 && code[3] == 4 && code[4] == 5));
  }
}
