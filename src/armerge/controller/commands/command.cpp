#include "command.h"
#include <iostream>


using namespace std;

Command::Command()
{

}

Command::~Command()
{

}

void Command::finishCommand()
{
    mIsFinished = true;
    emit finished();
}

bool Command::isFinished()
{
    return mIsFinished;
}
void Command::execute(){cout << "execute base command (do nothing) " << endl;}
