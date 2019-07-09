ZarateJohnS6C1plots.py : datos.txt
	python ZarateJohnS6C1plots.py 
datos.txt:a.out
	./a.out >datos.txt
a.out: ZarateJohnS6C1.cpp
	g++ ZarateJohnS6C1.cpp
