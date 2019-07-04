plotsS5C1.py : datos.txt
	python plotsS5C1.py   
datos.txt : a.out
	./a.out > datos.txt
a.out:S5C1Deriv.cpp
	g++ S5C1Deriv.cpp