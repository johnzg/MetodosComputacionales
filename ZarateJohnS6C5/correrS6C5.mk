Plots_DifusionS5C5.py : a.out
	python Plots_DifusionS6C5.py 
a.out: DifusionS6C5.cpp
	g++ DifusionS6C5.cpp
	./a.out 