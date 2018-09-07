#ifndef TEAMDATACOMMAND_H
#define TEAMDATACOMMAND_H

#include "../base/command.h"
using namespace std;
class viewModel;
class teamDataCommand : public command
{
private:
    viewModel *vm;
public:
    teamDataCommand();
    void setVm(viewModel* ptr);
    void action();
};

#endif // TEAMDATACOMMAND_H
