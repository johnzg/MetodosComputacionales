plotsS5C2.py : datos.txt
	python plotsS5C2.py   
datos.txt : a.out
	./a.out > datos.txt
a.out: ZarateJohnS5C2.cpp
	g++ ZarateJohnS5C2.cpp