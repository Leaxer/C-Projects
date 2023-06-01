all: clean compile run

compile: main.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc main.c -c -lm
	@gcc main.o -lm

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./a.out
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out
	@rm -f temporary.txt
