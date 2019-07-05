plotsS5C2.py : ./a.out
	python plotsS5C2.py   
a.out: ZarateJohnS5C2casa.cpp
	g++ ZarateJohnS5C2casa.cpp
	./a.out