# CXX should be a recent clang.  build DeepState with AFL instrumentation and copy lib to get deepstate_AFL

all:
	$(CXX) -o keepsake keepsake.cpp -ldeepstate
