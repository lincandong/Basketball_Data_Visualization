#ifndef TEAMRANKCOMMAND_H
#define TEAMRANKCOMMAND_H

#include "../base/command.h"
using namespace std;
class viewModel;
class teamRankCommand : public command
{
private:
    viewModel *vm;
    shared_ptr<rankParameter> para;
public:
    teamRankCommand();
    void setVm(viewModel* ptr);
    void action();
};

#endif // TEAMRANKCOMMAND_H
