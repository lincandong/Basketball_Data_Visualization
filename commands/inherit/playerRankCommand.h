#ifndef PLAYERRANKCOMMAND_H
#define PLAYERRANKCOMMAND_H

#include "../base/command.h"
using namespace std;
class viewModel;

class playerRankCommand : public command
{
private:
    viewModel *vm;
public:
    playerRankCommand();
    void setVm(viewModel* ptr);
    void action();
};

#endif // PLAYERRANKCOMMAND_H
