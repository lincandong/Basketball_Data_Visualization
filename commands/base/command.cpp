#include "command.h"

command::command()
{

}

void command::setParameter(std::shared_ptr<parameters> para)
{
    parameter = para;
}
