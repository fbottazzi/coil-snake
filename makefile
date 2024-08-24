# Remember to run everything in the parent folder, not in src/ or test/ or build/

OPTIONS := -ĺncurses -Wall -Wextra

# Builds & debugs:

# Tests:

test_game:
	gcc test/test_game.c src/body.c src/graphics.c src/game_rules.c src/food.c ${OPTIONS} -o build/test_game
	./build/test_game

test_body:
	gcc test/test_body.c src/body.c ${OPTIONS} -o build/test_body
	./build/test_body

test_graphics:
	gcc test/test_graphics.c src/graphics.c src/body.c src/food.c src/game_rules.c ${OPTIONS} -o build/test_graphics
	./build/test_graphics

test_keys:
	gcc test/test_keys.c src/game_rules.c ${OPTIONS} -o build/test_keys