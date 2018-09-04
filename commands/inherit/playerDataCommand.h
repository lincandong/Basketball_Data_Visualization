#ifndef PLAYERDATACOMMAND_H
#define PLAYERDATACOMMAND_H

#include "../base/command.h"
using namespace std;
class viewModel;

class playerDataCommand : public command
{
private:
    viewModel *vm;
    shared_ptr<dataParameter> para;
public:
    playerDataCommand();
    void setVm(viewModel* ptr);
    void action();
};

#endif // PLAYERDATACOMMAND_H
