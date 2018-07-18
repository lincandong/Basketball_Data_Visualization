#include "model.h"

//load data from file
void model::load()
{
    /* ... */
}
//stroe data to file, after program exits
void model::store()
{
    /* ... */
}
model::model()
{
    load();
}
model::~model()
{
    store();
}

//pairs of set() and get()
void model::set_a(int&& value)
{
    a = value;
    snd.notify("a has been set");
}
const int& model::get_a()
{

}
void model::set_b(string&& str)
{

}
const string& model::get_b()
{

}

//algorithms
int a_plus_b()
{
    //........................
}
/* ... */