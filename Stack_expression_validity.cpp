#include<iostream>
using namespace std;

class stack
{
    int size;
    char *array;
    int top;
    public:
    stack()
    {
        size=1;
        array = new char[size];
        top=-1;
    }
    bool stack_empty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool stack_full()
    {
        if(top==size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(char x)
    {
        if(!stack_full())
        {
            top++;
            array[top]=x;
        }
        else
        {
            cout<<"\nStack is full.\n";
        }
    }
    int pop()
    {
        if(!stack_empty())
        {
            top--;
            return array[top+1];
        }
        else
        {
            cout<<"\nStack is empty.\n";
            return 1;
        }
    }
    char Top()
    {
        if(!stack_empty())
        {
            return array[top];
        }
        return -1;
    }
	bool checkValidity(string x)
	{
		int countOperators = 0;
		int countOperands = 0;
		for(int i = 0;i<x.length();i++)
		{
			if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'||x[i]=='%')
			{
				countOperators++;
			}
			else if(isdigit(x[i])||(x[i]>='a'&&x[i]<='z') ||(x[i]>='A'&&x[i]<='Z') )
			{
				countOperands++;
			}
		}
		if(countOperators<countOperands)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
    bool check(char x)
    {
        size++;
        if(x=='('||x=='['||x=='{')
        {
            push(x);
            return false;
        }
        else if(x==')'||x==']'||x=='}')
        {
            if(stack_empty())
            {
                return false;
            }
            else
            {
                if(array[top]=='('&& x==')'||array[top]=='{'&& x == '}'||array[top]=='['&& x==']')
                {
                    pop();
                    if(!stack_empty())
                    {
                        return false;
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    int get_size()
    {
        return size;
    }
};

int main()
{
    stack s;
    string exp;
    cout<<"Enter expression: ";
    cin>>exp;
    bool reply;
    if(s.checkValidity(exp))
  {
        for(int i=0;i<exp.length();i++)
    {
        s.check(exp[i]);
        reply=s.check(exp[i]);
    }
    if (reply==true)
	{
		cout << "Balanced" << endl;
	}
	else
	{
		cout << "Not Balanced" << endl;
	}
  }
  else
  {
      cout<<"Expression is not valid.";
  }
}