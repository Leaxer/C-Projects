all: clean compile run

compile: main.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o a main.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./a
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f a
