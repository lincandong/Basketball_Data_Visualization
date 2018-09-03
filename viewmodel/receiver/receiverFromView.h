#ifndef RECEIVERFROMVIEW_H
#define RECEIVERFROMVIEW_H
#include "../../common/receiver.h"
using namespace std;
class viewModel;
class receiverFromView : public propertyReceiver
{
private:
    viewModel* vm;
public:
    receiverFromView() = default;
    receiverFromView(viewModel* ptr);
    virtual void exec(string str);
};
#endif
