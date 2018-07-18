#include "viewmodel.h"

viewModel::viewModel()
{
    age = make_shared<int>(0);
    name = make_shared<string>("");
    /* ... */   

    //m.model();
}
void viewModel::set_c(int&& value)
{
    *c = value;
}
const int & viewModel::get_c()
{
    return *c;
}
const command* viewModel::get_cmd1()
{
    return c1;
}