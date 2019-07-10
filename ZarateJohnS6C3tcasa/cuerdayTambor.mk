    
Plots_cuerdayTambor.py : a.out
	python Plots_cuerdayTambor.py 
a.out: ZarateJohn_cuerdayTambor.cpp
	g++ ZarateJohn_cuerdayTambor.cpp
	./a.out 