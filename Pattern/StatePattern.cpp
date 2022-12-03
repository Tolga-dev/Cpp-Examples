#include <iostream>

class Context;


class State
{

public:
    inline virtual ~State() noexcept
    {
    }

    virtual void Handle1() = 0;

};



class Walk : public State
{

public:
    inline virtual ~Walk() noexcept
    {
    }

    inline virtual void Handle1()
    {
        std::cout<<"Walk!"<<(std::endl);
    }

};



class Run : public State
{

public:
    inline virtual ~Run() noexcept
    {
    }

    inline virtual void Handle1()
    {
        std::cout<< "Run!"<<std::endl;
    }

};

class Context
{

public:
    inline Context()
            : state{nullptr}
    {
    }

    inline ~Context() noexcept
    {
        delete this->state;
    }

    inline void SetState(State *const s)
    {
        if(this->state) {
            delete this->state;
        }

        this->state = s;
    }

    inline void Request()
    {
        this->state->Handle1();
    }

private:
    State * state;
};
void Attempt1()
{
    Context * context = new Context();
    context->SetState(static_cast<State *>(new Walk()));
    context->Request();

    context->SetState(static_cast<State *>(new Run()));

    context->Request();
    delete context;
}


int main()
{


    return 0;
}

