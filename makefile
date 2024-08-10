# Remember to run everything in the parent folder, not in src/ or test/ or build/

OPTIONS := -Wall -Wextra

# Builds & debugs:

# Tests:

test_body:
	gcc test/test_body.c src/body.c -o build/test_body ${OPTIONS}
	./build/test_body

test_graphics:
	gcc test/test_graphics.c src/graphics.c src/body.c src/food.c -o build/test_graphics ${OPTIONS}
	./build/test_graphics