Plots_Difusiontcasa.py : a.out
	python Plots_Difusiontcasa.py 
a.out: Difusiontcasa.cpp
	g++ Difusiontcasa.cpp
	./a.out 