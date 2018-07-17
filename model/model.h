#include "..\common\common.h"
#include "..\notification\base\sender.h"

class model
{
private:
    int a;
    string b;
    /* ... */
    
    void load();//load data from file
    void store();//stroe data to file, after program exits
public:
    model();
    ~model();
    //pairs of set() and get()
    void set_a(int&& value);
    const int& get_a();
    void set_b(string&& str);
    const string& get_b();

    //algorithms
    string a_plus_b();
    /* ... */

    sender snd;
};