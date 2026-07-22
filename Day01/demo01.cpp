
#include <stdio.h>
//struct in C : collection of variables under a single name
struct time
{
    int hour;
    int minute;
    int second;
};

void display(struct time* tm)
{
    printf("Time is %d:%d:%d\n", tm->hour, tm->minute, tm->second);
}
int main()
{
    struct time t1={ 21, 02, 15};
    struct time t2;
    t2.hour = 10;
    t2.minute = 20;
    t2.second = 40;
    display(&t1);
    display(&t2);
}