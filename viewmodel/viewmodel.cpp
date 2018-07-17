#include "viewmodel.h"

viewModel::viewModel()
{
    age = make_shared<int>(0);
    name = make_shared<string>("");
    /* ... */   

    m.model();
}
