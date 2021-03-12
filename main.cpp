#include <iostream>
using namespace std;
struct list_
{
    string value;
    list_ * last = NULL;
};

void print_stek(list_ * stck);
list_ add_in_stack(list_ * stck, string value);
list_ * new_elem(list_ * last);
list_ * push(list_ point);
void remove_memory(list_ * slice);

int main()
{
    list_ a, b, c, d;
    a.value = "утечку памяти";
    b.value = "b";
    c.value = "c";
    d.value = "d";
    
    //b = add_in_stack(&a, "b");
    //c = add_in_stack(&b, "c");
    
    //cout << (*a.last).value;
    
    list_ * point = &a;
    
    //b = add_in_stack(point, "b");
    
    point = new_elem(point);
    (*point).value = "i used";
    
    point = new_elem(point);
    (*point).value = "hahahhah";
    
    print_stek(point);
    
    cout << (*((*point).last)).value;
    
    
    //cout << *doSomething();
    
    remove_memory(point);
    
    return 0;
}

void print_stek(list_ * stck)
{
    while ((*stck).last != NULL)
    {
        cout << (*stck).value << endl;
        
        stck = (*stck).last;
    }
    
    cout << (*stck).value << endl;
}

list_ add_in_stack(list_ * stck, string value)
{
    list_ nstck;
    nstck.value = value;
    nstck.last = stck;
    
    return nstck;
}


list_ * new_elem(list_ * last)
{
    list_ *ptr = new list_;
    (*ptr).last = last;
    return ptr;
}

//list_ * push(list_ point)
//{
  //  return (*point).last;
    
//}


void remove_memory(list_ * slice)
{
    list_* t;
    while ((*slice).last != NULL)
    {
        t = slice;
        slice = (*slice).last;
        
        delete t;
    }
}
