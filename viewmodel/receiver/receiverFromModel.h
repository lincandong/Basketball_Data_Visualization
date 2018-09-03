#ifndef RECEIVERFROMMODEL_H
#define RECEIVERFROMMODEL_H
#include "../../common/receiver.h"
using namespace std;
class viewModel;
class receiverFromModel : public propertyReceiver
{
private:
    viewModel* vm;
public:
    receiverFromModel() = default;
    receiverFromModel(viewModel* ptr);
    virtual void exec(string str);
};
#endif
