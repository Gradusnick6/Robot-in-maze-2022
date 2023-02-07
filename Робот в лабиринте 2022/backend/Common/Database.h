#pragma once


//уровни сложности
#define DL_EASY 1
#define DL_MIDDLE 2
#define DL_PROFESSIONAL 3

//путь к файлу с картами
#define PATH_TO_MAPS "database\\maps\\maps"

//путь к файлу с пользовательскими кодами
#define PATH_TO_CODE "database\\code\\"

#define START_SYMBOL '7'
#define FINISH_SYMBOL '9'

//структура RouteStep - направление шага робота
#define RS_UP 1	
#define RS_DOWN 2	
#define RS_LEFT 3	
#define RS_RIGHT 4	

const std::string emptyStr = "";