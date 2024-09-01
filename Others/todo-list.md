# To-Do

* ~~"Design" the state diagram / flow chart and module division to have the work more organized & coordinated~~
* Divide modules / tasks

* Have the game working:
    * ~~Body module: all functions~~
    * ~~Graphics module: printGameInit, -printBoard-, -eraseScreen-, -printGameOver-~~
    * ~~Game rules module: getInputInTime, runOneGameTick~~
    (maybe change runOneGameTick for a function that runs the game until death or quitting)
    * Some test to run and play the game
* Have the mandatory requirements done (probably in the process we'll have some optionals done or semi-done too)
    * progdata.h: Settings
    * Menus: initGame
    * History log: saveThisMatch, name
    * Graphics module: printHeader
    * Some test to run and see the game working with gameOver and bla bla
* Have the other optionals done
    * Graphics module: better printGameInit & printGameOver (animations), better printBoard (tail & head direction)
    * progdata.h: Game states
    * History: appendMatchToTopScore, getTopScores
    * Menus: everything (Start, TOP scores, pause, settings)
    * Food & game_rules: better checkFood & runOneGameTick (food timeout)
    * Game rules: pause functionality