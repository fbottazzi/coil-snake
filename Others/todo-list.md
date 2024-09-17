# To-Do

* ~~"Design" the state diagram / flow chart and module division to have the work more organized & coordinated~~
* Divide modules / tasks

* Modularization: changes in getKey (>>> getInput), gameInfo_t (>>> game_info_t)
* Have to accomodate that so that everything keeps working
* So the logic is so:
    * Backend: body, food, game_info
    * Frontend: graphics (output of game), input (input of game and in/out of menus)
    * "Integration": game_rules and main (and "states"? or that in game_rules?)
    * Extra headers: progstates.h && consts.h