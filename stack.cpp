#include <iostream>
using namespace std;

struct stack
{
    string value;
    stack * last;
};

void print_stack(stack *stk);
void clear_stack(stack *stk);
stack * new_elem(stack *last);

int main()
{
  stack *point = NULL;
  
  for (int i = 0; i < 15; i++)
  {
    point = new_elem(point);
    (*point).value = i;
  }
  
  print_stack(point);
  
  return 0;
}

void print_stack(stack *stk)
{
    while ((*stk).last != NULL)
    {
        cout << (*stk).value << endl;
        stk = (*stk).last;
    }
    cout << (*stk).value << endl;
}
void clear_stack(stack *stk)
{
    stack * t;
    while((*stk).last != NULL)
    {
        t = stk;
        stk = (*stk).last;
        delete stk;
    }
}
stack * new_elem(stack *last)
{
    stack *plt = new stack;
    (*plt).last = last;
    return plt;
}
