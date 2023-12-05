default:
	g++ DayThree.cpp -o DayThree
	./DayThree inputEngine.txt > output.txt
clean:
	rm DayThree a.out