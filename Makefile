default:
	g++ DayFour.cpp -o DayFour
	./DayFour lottery.txt > output.txt
clean:
	rm DayFour a.out