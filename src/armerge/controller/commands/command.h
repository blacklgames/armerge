#ifndef COMMAND_H
#define COMMAND_H

#include<string>

using namespace std;

static string PROJECT_PATH = "D:\\work\\GM\\source\\new_E2\\GM_E2_MY21_VP\\gm.di.e4.bsp.delivery\\di.gen.2022.gm.e4.vip.bsw.cfg\\project\\Config";
static string WORKING_PATH = "..\\tmp";

class Command
{
public:
    Command();

    virtual void execute() = 0;
};

#endif // COMMAND_H
